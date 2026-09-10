#!/usr/bin/env python3
"""Report outdated FreeBSD ports for a maintainer using Repology and GitHub."""

# report-outdated-for-maintainer.py - a script that find outdated ports for
# a given maintainer based on Repology API and GitHub releases, and prints
# a categorized report.
#
# MAINTAINER= yuri@FreeBSD.org
#


import sys
import os
import re
import json
import time
import subprocess
import concurrent.futures
import asyncio
import urllib.request
import urllib.parse
import urllib.error
import shutil
import ssl

# --- Dependency check ---

# missing python dependencies
missing_deps = []
try:
    from tabulate2 import tabulate
except ImportError:
    missing_deps.append("tabulate2")

if missing_deps:
    py_ver = f"py{sys.version_info.major}{sys.version_info.minor}"
    pkg_names = " ".join(f"{py_ver}-{dep}" for dep in missing_deps)
    print(
        f"Missing dependencies: {', '.join(missing_deps)}. "
        f"Please install them with 'pkg install {pkg_names}' and try again."
    )
    sys.exit(1)


# --- Configuration ---

PORTSDIR = os.environ.get("PORTSDIR", "/usr/ports")
REPOLOGY_API_BASE = "https://repology.org/api/v1"
GITHUB_BASE = "https://github.com"
GITHUB_API_BASE = "https://api.github.com"
USER_AGENT = "report-outdated-for-maintainer/1.0 (FreeBSD ports maintainer tool)"
GITHUB_TOKEN = None
GIT_PARALLELISM = int(os.environ.get("GIT_PARALLELISM", 32))
GIT_SINGLE_THRESHOLD = int(os.environ.get("GIT_SINGLE_THRESHOLD", 500))

USAGE = f"""Usage: {os.path.basename(sys.argv[0])} [--disable-last-updated] <maintainer-email>
       {os.path.basename(sys.argv[0])} --help

Report outdated FreeBSD ports for a maintainer using Repology and GitHub.

Options:
  --disable-last-updated  Skip git history queries and omit the 'Last Updated' column.
  --help, -h              Show this help message and exit.

Example:
  {os.path.basename(sys.argv[0])} yuri@FreeBSD.org
"""

STALENESS_THRESHOLDS = [
    ("1 week", 7 * 24 * 3600),
    ("2 weeks", 14 * 24 * 3600),
    ("1 month", 30 * 24 * 3600),
    ("2 months", 60 * 24 * 3600),
    ("3 months", 90 * 24 * 3600),
    ("4 months", 120 * 24 * 3600),
    ("5 months", 150 * 24 * 3600),
    ("6 months", 180 * 24 * 3600),
    ("12 months", 365 * 24 * 3600),
    ("24 months", 730 * 24 * 3600),
]

# USES keyword → Port Type label (in priority order)
USES_TYPES = [
    ("gmake",    "gmake"),
    ("cmake",    "cmake"),
    ("meson",    "meson"),
    ("waf",      "waf"),
    ("python",   "Python"),
    ("cargo",    "Rust"),
    ("cabal",    "Haskel"),
    ("go",       "GoLang"),
    ("nodejs",   "NodeJS"),
    ("fortran",  "Fortran"),
    ("drupal",   "Drupal"),
    ("cran",     "R"),
    ("ocaml",    "Ocaml"),
    ("php",      "php"),
    ("vala",     "Vala"),
    ("ruby",     "Ruby"),
    ("perl5",    "Perl"),
    ("mono",     "Mono"),
    ("ada",      "Ada"),
    ("lazarus",  "Lazarus"),
    ("erlang",   "Erlang"),
    ("electron", "Electron"),
    ("linux",    "Linux"),
    ("kmod",     "kmod"),
    ("java",     "Java"),
]


# --- Validation ---

def check_portsdir():
    required = [
        PORTSDIR,
        os.path.join(PORTSDIR, "Makefile"),
        os.path.join(PORTSDIR, "Mk"),
        os.path.join(PORTSDIR, "MOVED"),
        os.path.join(PORTSDIR, "devel"),
        os.path.join(PORTSDIR, "devel", "Makefile"),
    ]
    for path in required:
        if not os.path.exists(path):
            print(f"Error: Required path not found: {path}", file=sys.stderr)
            sys.exit(1)


def check_required_commands(need_git=True):
    """Check that required external commands are available."""
    missing = []
    if not shutil.which("gh"):
        missing.append("gh")
    if need_git and not shutil.which("git"):
        missing.append("git")
    if missing:
        print(
            f"Missing required commands: {', '.join(missing)}. "
            "Please install them and try again."
        )
        sys.exit(1)


def parse_args():
    """Parse command-line arguments and return (maintainer_email, disable_last_updated)."""
    args = sys.argv[1:]
    if "--help" in args or "-h" in args:
        print(USAGE)
        sys.exit(0)

    disable_last_updated = False
    maintainer_email = None
    for arg in args:
        if arg == "--disable-last-updated":
            disable_last_updated = True
        elif arg.startswith("-"):
            print(f"Unknown option: {arg}\n{USAGE}", file=sys.stderr)
            sys.exit(1)
        elif maintainer_email is None:
            maintainer_email = arg
        else:
            print(USAGE, file=sys.stderr)
            sys.exit(1)

    if not maintainer_email:
        print(USAGE, file=sys.stderr)
        sys.exit(1)

    return maintainer_email, disable_last_updated


def get_github_token():
    """Return a GitHub token from env or gh auth, if available."""
    global GITHUB_TOKEN
    if GITHUB_TOKEN is not None:
        return GITHUB_TOKEN

    GITHUB_TOKEN = os.environ.get("GITHUB_TOKEN") or os.environ.get("GH_TOKEN")
    if GITHUB_TOKEN:
        return GITHUB_TOKEN

    try:
        result = subprocess.run(
            ["gh", "auth", "token"],
            capture_output=True,
            text=True,
            timeout=10,
        )
        token = result.stdout.strip()
        if result.returncode == 0 and token:
            GITHUB_TOKEN = token
            return GITHUB_TOKEN
    except Exception:
        pass

    GITHUB_TOKEN = ""
    return None


# --- Ports tree parsing ---

def get_subdir_entries(makefile_path):
    """Return list of SUBDIR += entries from a Makefile."""
    entries = []
    try:
        with open(makefile_path, "r", errors="replace") as f:
            content = f.read()
        for m in re.finditer(r"^\s*SUBDIR\s*\+=\s*(\S+)", content, re.MULTILINE):
            entries.append(m.group(1))
    except OSError:
        pass
    return entries


def read_makefile_logical_lines(makefile_path):
    """Read a Makefile and return a list of logical lines (continuations joined)."""
    try:
        with open(makefile_path, "r", errors="replace") as f:
            content = f.read()
    except OSError:
        return []
    # Join continuation lines
    content = re.sub(r"\\\n", " ", content)
    return content.splitlines()


def get_makefile_var(makefile_path, var):
    """Extract a simple variable value from a Makefile (first assignment found)."""
    for line in read_makefile_logical_lines(makefile_path):
        m = re.match(rf"^\s*{re.escape(var)}\s*(?::|\?)?=\s*(.+)$", line)
        if m:
            return re.sub(r"\s+#.*$", "", m.group(1)).strip()
    return None


def get_uses_types(makefile_path):
    """Return a comma-separated string of port types based on USES= in the Makefile."""
    uses_tokens = set()
    for line in read_makefile_logical_lines(makefile_path):
        # Match both USES= and USES+=
        m = re.match(r"^\s*USES\s*\+?=\s*(.+)$", line)
        if m:
            for token in m.group(1).split():
                # Strip :options suffix for matching
                uses_tokens.add(token.split(":")[0])

    types = []
    for keyword, label in USES_TYPES:
        if keyword in uses_tokens:
            types.append(label)
    return ", ".join(types)


def resolve_make_value(value, portname):
    """Resolve simple ${PORTNAME} substitutions in Makefile values."""
    if value is None:
        return None

    def replacer(match):
        modifier = match.group(1)
        if modifier == ":tl":
            return portname.lower()
        if modifier == ":tu":
            return portname.upper()
        return portname

    return re.sub(r"\$\{PORTNAME(?:(:tl|:tu))?\}", replacer, value)


def get_github_repo(makefile_path):
    """Return (account, project) for USE_GITHUB=yes ports or from WWW field, else None."""
    use_github = get_makefile_var(makefile_path, "USE_GITHUB")
    if use_github and use_github.lower() == "yes":
        portname = get_makefile_var(makefile_path, "PORTNAME")
        if not portname:
            return None

        gh_account = get_makefile_var(makefile_path, "GH_ACCOUNT") or portname
        gh_project = get_makefile_var(makefile_path, "GH_PROJECT") or portname
        gh_account = resolve_make_value(gh_account.split()[0], portname)
        gh_project = resolve_make_value(gh_project.split()[0], portname)
        return gh_account, gh_project
    
    # If USE_GITHUB is not set, try to extract from WWW field, but only for ports
    # that appear to use GitHub releases and are explicitly marked with a comment
    # or have DISTVERSION matching a GitHub-style tag pattern (YYYY.M.DD or similar)
    version = get_makefile_var(makefile_path, "DISTVERSION") or get_makefile_var(makefile_path, "PORTVERSION")
    if version and looks_like_version(version):
        # Only query from WWW if version matches GitHub-style patterns:
        # - YYYY.M.DD (date-based like 2026.4.26, 2026.4.29)
        # - X.Y.Z.W (4+ numeric components)
        # This filters out most non-GitHub ports while catching real GitHub releases
        parts = re.findall(r"\d+", version)
        if len(parts) >= 3:
            # Check if it looks like YYYY.M.DD (year >= 2000)
            if int(parts[0]) >= 2000 and int(parts[0]) <= 2099:
                if int(parts[1]) >= 1 and int(parts[1]) <= 12:
                    if int(parts[2]) >= 1 and int(parts[2]) <= 31:
                        # Looks like a date-based version from GitHub
                        www = get_makefile_var(makefile_path, "WWW")
                        if www:
                            m = re.match(r"https?://(?:www\.)?github\.com/([^/]+)/([^/\s]+)", www)
                            if m:
                                return m.group(1), m.group(2)
            # Also check for simple 4+ component versions (e.g., 1.2.3.4)
            elif len(parts) >= 4:
                www = get_makefile_var(makefile_path, "WWW")
                if www:
                    m = re.match(r"https?://(?:www\.)?github\.com/([^/]+)/([^/\s]+)", www)
                    if m:
                        return m.group(1), m.group(2)
    
    return None


# --- Version handling ---

VERSION_RE = re.compile(r"^[A-Za-z0-9][A-Za-z0-9._+-]*$")
G_VERSION_RE = re.compile(r"^g[a-zA-Z0-9]+$")
YYYYMMDD_RE = re.compile(r"^(\d{4})(\d{2})(\d{2})$")


def looks_like_version(s):
    return bool(s and VERSION_RE.match(s) and any(ch.isdigit() for ch in s))


def compute_aux_version(real_version, latest_effective=None):
    """
    Return the auxiliary version string if it differs from real_version, else None.

    - gNNNNN  → 0.0.0... (matching component count of latest_effective)
    - YYYYMMDD → YYYY.MM.DD
    """
    if G_VERSION_RE.match(real_version) and latest_effective is not None:
        parts = parse_version(latest_effective)
        n = max(len(parts), 1)
        return ".".join(["0"] * n)

    m = YYYYMMDD_RE.match(real_version)
    if m:
        year, month, day = int(m.group(1)), int(m.group(2)), int(m.group(3))
        if 1900 <= year <= 2099 and 1 <= month <= 12 and 1 <= day <= 31:
            return f"{m.group(1)}.{m.group(2)}.{m.group(3)}"

    return None


def display_version(real, aux):
    """Return 'real (aux)' if aux differs from real, else just 'real'."""
    if aux and aux != real:
        return f"{real} ({aux})"
    return real


def parse_version(version_str):
    """Parse version string into a tuple of ints."""
    parts = [int(part) for part in re.findall(r"\d+", version_str)]
    return tuple(parts) if parts else (0,)


def compare_versions(left_version, right_version):
    """Return 1 if left>right, -1 if left<right, 0 if equal by numeric components."""
    left = parse_version(left_version)
    right = parse_version(right_version)
    max_len = max(len(left), len(right), 3)
    left = left + (0,) * (max_len - len(left))
    right = right + (0,) * (max_len - len(right))
    if left > right:
        return 1
    if left < right:
        return -1
    return 0


def categorize_outdatedness(current_effective, latest_effective):
    """
    Compare effective (auxiliary) versions.
    Returns (category, level) or None if not outdated.
    """
    if compare_versions(latest_effective, current_effective) <= 0:
        return None

    cur = parse_version(current_effective)
    lat = parse_version(latest_effective)
    max_len = max(len(cur), len(lat), 3)
    cur = cur + (0,) * (max_len - len(cur))
    lat = lat + (0,) * (max_len - len(lat))

    if lat[0] > cur[0]:
        return ("major", lat[0] - cur[0])

    if lat[1] > cur[1]:
        return ("minor", lat[1] - cur[1])

    for i in range(2, max_len):
        if lat[i] > cur[i]:
            return ("patch", lat[i] - cur[i])
        if lat[i] < cur[i]:
            break

    return ("patch", 1)


# --- Ports scanning ---

def get_port_version_from_makefile(makefile_path):
    """Try PORTVERSION then DISTVERSION; return value if it looks like a version."""
    for var in ("PORTVERSION", "DISTVERSION"):
        val = get_makefile_var(makefile_path, var)
        if val and looks_like_version(val):
            return val
    return None


def get_port_version_via_make(port_dir):
    """Run 'make -V PORTVERSION' in port_dir and return the result."""
    try:
        result = subprocess.run(
            ["make", "BATCH=yes", "-V", "PORTVERSION"],
            cwd=port_dir,
            capture_output=True,
            text=True,
            timeout=30,
        )
        v = result.stdout.strip()
        if looks_like_version(v):
            return v
    except Exception:
        pass
    return None


def find_maintained_ports(maintainer_email):
    """
    Return (versions, uses_types, github_repos, github_version_prefixes) keyed by port origin.
    versions[origin] = real version string
    uses_types[origin] = comma-separated port type string
    github_repos[origin] = (account, project) for USE_GITHUB ports
    github_version_prefixes[origin] = (prefix, suffix) to strip from GitHub release tags
    """
    versions = {}
    uses_types = {}
    github_repos = {}
    github_version_prefixes = {}
    top_makefile = os.path.join(PORTSDIR, "Makefile")
    categories = get_subdir_entries(top_makefile)

    for category in categories:
        cat_makefile = os.path.join(PORTSDIR, category, "Makefile")
        if not os.path.isfile(cat_makefile):
            continue
        port_dirs = get_subdir_entries(cat_makefile)
        for port_dir in port_dirs:
            port_path = os.path.join(PORTSDIR, category, port_dir)
            port_makefile = os.path.join(port_path, "Makefile")
            if not os.path.isfile(port_makefile):
                continue
            maintainer = get_makefile_var(port_makefile, "MAINTAINER")
            if not maintainer or maintainer.lower() != maintainer_email.lower():
                continue
            origin = f"{category}/{port_dir}"
            version = get_port_version_from_makefile(port_makefile)
            if version is None:
                version = get_port_version_via_make(port_path)
            if version is None:
                print(
                    f"Warning: Could not determine version for {origin}, skipping.",
                    file=sys.stderr,
                )
                continue
            versions[origin] = version
            uses_types[origin] = get_uses_types(port_makefile)
            github_repo = get_github_repo(port_makefile)
            if github_repo:
                github_repos[origin] = github_repo
                portname = get_makefile_var(port_makefile, "PORTNAME") or ""
                prefix_raw = get_makefile_var(port_makefile, "DISTVERSIONPREFIX") or ""
                suffix_raw = get_makefile_var(port_makefile, "DISTVERSIONSUFFIX") or ""
                prefix = resolve_make_value(prefix_raw, portname)
                suffix = resolve_make_value(suffix_raw, portname)
                if prefix or suffix:
                    github_version_prefixes[origin] = (prefix, suffix)

    return versions, uses_types, github_repos, github_version_prefixes


# --- Git last-update queries ---

async def _find_last_updates_per_origin(origins):
    """Per-origin streaming git log, killing each process once a bump is found."""
    if not origins:
        return {}

    bump_re = re.compile(r"^(\+PORTVERSION=|\+DISTVERSION=)")
    semaphore = asyncio.Semaphore(GIT_PARALLELISM)

    async def _run_for_origin(origin):
        async with semaphore:
            makefile_rel = f"{origin}/Makefile"
            args = [
                "-C",
                PORTSDIR,
                "--no-optional-locks",
                "log",
                "-p",
                "-m",
                "--pretty=format:COMMIT:%H %ct",
                "--",
                makefile_rel,
            ]
            try:
                proc = await asyncio.create_subprocess_exec(
                    "git",
                    *args,
                    stdout=asyncio.subprocess.PIPE,
                    stderr=asyncio.subprocess.PIPE,
                )
            except Exception:
                return origin, None

            current_time = None
            timestamp = None

            while True:
                try:
                    line_b = await asyncio.wait_for(proc.stdout.readline(), timeout=60)
                except asyncio.TimeoutError:
                    break
                if not line_b:
                    break
                line = line_b.decode(errors="replace").rstrip("\n")

                if line.startswith("COMMIT:"):
                    parts = line[len("COMMIT:"):].split()
                    current_time = parts[1] if len(parts) >= 2 else None
                elif current_time and bump_re.match(line):
                    try:
                        timestamp = int(current_time)
                    except ValueError:
                        pass
                    break

            try:
                if proc.returncode is None:
                    proc.kill()
                    await proc.wait()
            except Exception:
                pass

            return origin, timestamp

    tasks = [_run_for_origin(origin) for origin in origins]
    results = await asyncio.gather(*tasks)

    last_updates = {}
    for origin, timestamp in results:
        if timestamp is not None:
            last_updates[origin] = timestamp
    return last_updates


async def _find_last_updates_single_log(origins):
    """One repository-wide git log -G parse, with per-origin fallback."""
    if not origins:
        return {}

    target_files = {f"{origin}/Makefile" for origin in origins}
    bump_re = re.compile(r"^(\+PORTVERSION=|\+DISTVERSION=)")

    args = [
        "-C",
        PORTSDIR,
        "--no-optional-locks",
        "log",
        "-p",
        "-m",
        "-G",
        "^PORTVERSION=|^DISTVERSION=",
        "--pretty=format:COMMIT:%H %ct",
        "--",
        "*/Makefile",
    ]

    last_updates = {}
    current_commit = None
    current_time = None
    current_file = None
    current_has_bump = False

    try:
        proc = await asyncio.create_subprocess_exec(
            "git",
            *args,
            stdout=asyncio.subprocess.PIPE,
            stderr=asyncio.subprocess.PIPE,
        )
    except Exception:
        return {}

    def _flush():
        nonlocal current_has_bump
        if (
            current_file
            and current_commit
            and current_time
            and current_has_bump
            and current_file in target_files
            and current_file not in last_updates
        ):
            try:
                last_updates[current_file] = int(current_time)
            except ValueError:
                pass
        current_has_bump = False

    while True:
        try:
            line_b = await asyncio.wait_for(proc.stdout.readline(), timeout=600)
        except asyncio.TimeoutError:
            break
        if not line_b:
            break
        line = line_b.decode(errors="replace").rstrip("\n")

        if line.startswith("COMMIT:"):
            _flush()
            current_file = None
            parts = line[len("COMMIT:"):].split()
            current_commit, current_time = (
                (parts[0], parts[1]) if len(parts) >= 2 else (None, None)
            )
        elif line.startswith("diff --git"):
            _flush()
            match = re.match(r"^diff --git a/(.+) b/(.+)$", line)
            current_file = match.group(2) if match else None
        elif current_commit and current_file and bump_re.match(line):
            current_has_bump = True

    _flush()

    try:
        if proc.returncode is None:
            proc.kill()
            await proc.wait()
    except Exception:
        pass

    # Fallback for renamed/moved Makefiles that the single -G log does not catch.
    missing = [origin for origin in origins if f"{origin}/Makefile" not in last_updates]
    if missing:
        fallback = await _find_last_updates_per_origin(missing)
        last_updates.update({f"{origin}/Makefile": ts for origin, ts in fallback.items()})

    return {path[:-len("/Makefile")]: ts for path, ts in last_updates.items()}


async def _find_last_updates(origins):
    """Return {origin: timestamp} for the last version-bumping commit of each origin.

    For large maintainer lists, use a single repository-wide ``git log -G``
    query; for small lists, use per-port streaming git logs.  A per-origin
    fallback handles renamed/moved Makefiles that the single log may miss.
    """
    if len(origins) > GIT_SINGLE_THRESHOLD:
        return await _find_last_updates_single_log(origins)
    return await _find_last_updates_per_origin(origins)


def format_last_updated(timestamp):
    """Format a Unix timestamp as minutes, hours, or days since that time."""
    if timestamp is None:
        return ""
    now = time.time()
    elapsed_seconds = now - timestamp
    if elapsed_seconds < 3600:
        minutes = int(elapsed_seconds / 60)
        return f"{minutes} minute{'s' if minutes != 1 else ''}"
    elapsed_hours = elapsed_seconds / 3600
    if elapsed_hours < 24:
        hours = int(elapsed_hours)
        return f"{hours} hour{'s' if hours != 1 else ''}"
    days = int(elapsed_hours / 24)
    return f"{days} day{'s' if days != 1 else ''}"


# --- Repology API ---

def repology_request(url):
    """Make a single GET request to the Repology API; return parsed JSON."""
    ctx = ssl.create_default_context()
    req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT})
    try:
        with urllib.request.urlopen(req, timeout=30, context=ctx) as resp:
            return json.loads(resp.read())
    except urllib.error.HTTPError as e:
        print(f"Error: Repology API returned HTTP {e.code}: {e.reason}", file=sys.stderr)
        sys.exit(1)
    except urllib.error.URLError as e:
        print(f"Error: Could not reach Repology API: {e.reason}", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"Error querying Repology: {e}", file=sys.stderr)
        sys.exit(1)


def query_repology_outdated(maintainer_email):
    """
    Return dict {origin: latest_version} for FreeBSD ports that Repology
    considers outdated for this maintainer.
    """
    encoded_email = urllib.parse.quote(maintainer_email.lower(), safe="@")
    base_params = f"maintainer={encoded_email}&inrepo=freebsd&outdated=true"
    url = f"{REPOLOGY_API_BASE}/projects/?{base_params}"
    outdated = {}

    while url:
        data = repology_request(url)
        if not data:
            break

        for project_name, packages in data.items():
            freebsd_outdated = None
            newest_version = None

            for pkg in packages:
                if pkg.get("repo") == "freebsd" and pkg.get("status") == "outdated":
                    freebsd_outdated = pkg
                if pkg.get("status") == "newest" and newest_version is None:
                    newest_version = pkg.get("version")

            if freebsd_outdated and newest_version:
                srcname = freebsd_outdated.get("srcname") or freebsd_outdated.get("visiblename")
                if srcname:
                    outdated[srcname] = newest_version

        if len(data) == 200:
            last_project = list(data.keys())[-1]
            encoded_last = urllib.parse.quote(last_project, safe="")
            url = f"{REPOLOGY_API_BASE}/projects/{encoded_last}/?{base_params}"
            time.sleep(0.5)  # be polite to the API
        else:
            url = None

    return outdated


def github_request(url, method="GET"):
    """Make a single GitHub request and return the response object."""
    headers = {
        "User-Agent": USER_AGENT,
        "Accept": "application/vnd.github+json",
    }
    token = get_github_token()
    if token:
        headers["Authorization"] = f"Bearer {token}"
    req = urllib.request.Request(url, headers=headers, method=method)
    return urllib.request.urlopen(req, timeout=30)


def query_github_latest_release(account, project, cache):
    """Return the latest stable GitHub release tag for account/project, or None."""
    key = (account, project)
    if key in cache:
        return cache[key]

    # Use 'gh' CLI for better rate limit handling and authentication
    try:
        result = subprocess.run(
            ["gh", "release", "view", "--repo", f"{account}/{project}"],
            capture_output=True,
            text=True,
            timeout=30,
        )
        if result.returncode == 0:
            for line in result.stdout.split("\n"):
                if line.startswith("tag:"):
                    tag = line.split(":", 1)[1].strip()
                    cache[key] = tag.strip() or None
                    return cache[key]
        cache[key] = None
        return None
    except Exception:
        cache[key] = None
        return None


def query_github_releases(github_repos, version_prefixes=None):
    """Return dict {origin: latest_release_tag} for GitHub-based ports with releases."""
    cache = {}
    latest_releases = {}

    unique_repos = sorted(set(github_repos.values()))
    # gh CLI handles rate limiting better than direct API calls, so we can use more workers
    max_workers = min(8, len(unique_repos)) if unique_repos else 1
    with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
        future_map = {
            executor.submit(query_github_latest_release, account, project, cache): (account, project)
            for account, project in unique_repos
        }
        for future in concurrent.futures.as_completed(future_map):
            future.result()

    for origin, repo in github_repos.items():
        latest = cache.get(repo)
        if latest:
            if version_prefixes and origin in version_prefixes:
                prefix, suffix = version_prefixes[origin]
                if prefix and latest.startswith(prefix):
                    latest = latest[len(prefix):]
                if suffix and latest.endswith(suffix):
                    latest = latest[:-len(suffix)]
            latest_releases[origin] = latest
    return latest_releases


# --- Report formatting ---

SEP = "============="


def format_table_with_blank_header_line(rows, headers):
    """Render tabulate 'simple' table with a blank line inserted after the header separator."""
    raw = tabulate(rows, headers=headers, tablefmt="simple")
    lines = raw.splitlines()
    # simple format: line 0 = header names, line 1 = dashes, line 2+ = data
    if len(lines) >= 2:
        lines.insert(2, "")
    return "\n".join(lines)


def choose_latest_version(repology_real, github_real):
    """Choose the highest latest version from Repology/GitHub and return display info."""
    candidates = []
    if repology_real:
        repology_aux = compute_aux_version(repology_real)
        repology_effective = repology_aux if repology_aux else repology_real
        candidates.append(("Repology", repology_real, repology_aux, repology_effective))
    if github_real:
        github_aux = compute_aux_version(github_real)
        github_effective = github_aux if github_aux else github_real
        candidates.append(("GitHub", github_real, github_aux, github_effective))

    if not candidates:
        return None

    best = candidates[0]
    for candidate in candidates[1:]:
        cmp = compare_versions(candidate[3], best[3])
        if cmp > 0 or (cmp == 0 and candidate[0] == "Repology" and best[0] != "Repology"):
            best = candidate

    notes = [candidate[0] for candidate in candidates if compare_versions(candidate[3], best[3]) == 0]
    return {
        "real": best[1],
        "aux": best[2],
        "effective": best[3],
        "notes": ", ".join(notes),
    }


def print_report(
    maintainer_email,
    local_versions,
    local_uses,
    outdated_repology,
    github_latest,
    last_updates,
    disable_last_updated=False,
):
    total_ports = len(local_versions)

    headers = [
        "Port origin",
        "Latest released version",
        "Current port version",
        "Outdatedness level",
        "Port Type",
        "Notes",
    ]
    if not disable_last_updated:
        headers.insert(5, "Last Updated")

    major_ports = []
    minor_ports = []
    patch_ports = []
    outdated_origins = []
    stale_port_data = []  # (origin, outdatedness_level, last_update_timestamp)

    for origin, local_real in local_versions.items():
        latest = choose_latest_version(outdated_repology.get(origin), github_latest.get(origin))
        if latest is None:
            continue

        # Compute auxiliary version for local (gNNNNN needs latest_effective for depth)
        local_aux = compute_aux_version(local_real, latest["effective"])
        local_effective = local_aux if local_aux else local_real

        result = categorize_outdatedness(local_effective, latest["effective"])
        if result is None:
            continue
        category, level = result

        port_type = local_uses.get(origin, "")
        row = [
            origin,
            display_version(latest["real"], latest["aux"]),
            display_version(local_real, local_aux),
            level,
            port_type,
            latest["notes"],
        ]
        if not disable_last_updated:
            row.insert(5, format_last_updated(last_updates.get(origin)))
        row = tuple(row)

        if origin in last_updates:
            stale_port_data.append((origin, level, last_updates[origin]))

        outdated_origins.append(origin)
        if category == "major":
            major_ports.append(row)
        elif category == "minor":
            minor_ports.append(row)
        else:
            patch_ports.append(row)

    def sort_key(row):
        return (-row[3], row[0])

    major_ports.sort(key=sort_key)
    minor_ports.sort(key=sort_key)
    patch_ports.sort(key=sort_key)

    n_major = len(major_ports)
    n_minor = len(minor_ports)
    n_patch = len(patch_ports)
    n_outdated = n_major + n_minor + n_patch

    # Title
    print(f"Outdated ports for maintainer {maintainer_email}")
    print()
    print()

    # Summary line
    pct = (lambda n: f"{n / total_ports * 100:.2f}%") if total_ports > 0 else (lambda n: "0.00%")

    print(
        f"The maintainer has {n_outdated} ({pct(n_outdated)}) outdated ports, categorized as follows: "
        f"{n_major} ({pct(n_major)}) majorly outdated, "
        f"{n_minor} ({pct(n_minor)}) moderately outdated, "
        f"and {n_patch} ({pct(n_patch)}) slightly outdated."
    )
    print()

    for title, rows in [
        ("Majorly outdated ports", major_ports),
        ("Moderately outdated ports", minor_ports),
        ("Slightly outdated ports", patch_ports),
    ]:
        print(f"{SEP}{title}{SEP}")
        print()
        if rows:
            print(format_table_with_blank_header_line(rows, headers))
        else:
            print("No ports in this category")
        print()

    if not disable_last_updated and outdated_origins:
        now = time.time()
        stale_counts = []
        raw_counts = []
        stale_pct = (lambda n: f"{n / total_ports * 100:.1f}%") if total_ports > 0 else (lambda n: "0.0%")
        for label, seconds in STALENESS_THRESHOLDS:
            count = sum(
                1
                for origin in outdated_origins
                if origin in last_updates and (now - last_updates[origin]) >= seconds
            )
            stale_counts.append((label, f"{count} ({stale_pct(count)})"))
            raw_counts.append(count)

        print(f"{SEP}Staleness Analysis{SEP}")
        print()
        if any(raw_counts):
            print(format_table_with_blank_header_line(stale_counts, ["Stale for Longer Than", "Count"]))
        else:
            print("No stale ports with last update information available.")
        print()

    if not disable_last_updated and stale_port_data:
        now = time.time()

        # Non-overlapping staleness buckets in chronological order.
        bucket_intervals = [
            (f"< {STALENESS_THRESHOLDS[0][0]}", 0, STALENESS_THRESHOLDS[0][1]),
        ]
        for i in range(len(STALENESS_THRESHOLDS) - 1):
            label = f"{STALENESS_THRESHOLDS[i][0]} .. {STALENESS_THRESHOLDS[i + 1][0]}"
            bucket_intervals.append(
                (label, STALENESS_THRESHOLDS[i][1], STALENESS_THRESHOLDS[i + 1][1])
            )
        bucket_intervals.append((f"> {STALENESS_THRESHOLDS[-1][0]}", STALENESS_THRESHOLDS[-1][1], sys.maxsize))

        buckets_rows = []
        for period, lower, upper in bucket_intervals:
            bucket_ports = [
                (origin, level, timestamp)
                for origin, level, timestamp in stale_port_data
                if (age := now - timestamp) >= lower and age < upper
            ]
            if not bucket_ports:
                continue
            bucket_ports.sort(key=lambda x: (-x[2], x[0]))
            count = len(bucket_ports)
            for idx, (origin, level, timestamp) in enumerate(bucket_ports):
                last_updated_str = format_last_updated(timestamp)
                if idx == 0:
                    buckets_rows.append([period, count, origin, last_updated_str])
                else:
                    buckets_rows.append(["", "", origin, last_updated_str])

        print(f"{SEP}Ports by Time of Staleness{SEP}")
        print()
        if buckets_rows:
            print(format_table_with_blank_header_line(
                buckets_rows,
                ["Time Period", "Count", "Port origin", "Last Updated"],
            ))
        else:
            print("No stale ports with last update information available.")
        print()



# --- Main ---

def main():
    maintainer_email, disable_last_updated = parse_args()
    check_required_commands(need_git=not disable_last_updated)
    check_portsdir()

    print(f"Scanning {PORTSDIR} for ports maintained by {maintainer_email}...", file=sys.stderr)
    local_versions, local_uses, github_repos, github_version_prefixes = find_maintained_ports(maintainer_email)

    if not local_versions:
        print(f"No ports maintained by {maintainer_email}")
        sys.exit(0)

    print(
        f"Found {len(local_versions)} local ports ({len(github_repos)} GitHub-based). Querying Repology and GitHub...",
        file=sys.stderr,
    )
    outdated_repology = query_repology_outdated(maintainer_email)
    github_latest = query_github_releases(github_repos, github_version_prefixes)
    print(f"Repology reports {len(outdated_repology)} outdated FreeBSD ports.", file=sys.stderr)
    print(f"GitHub provides latest releases for {len(github_latest)} GitHub-based ports.", file=sys.stderr)

    last_updates = {}
    if not disable_last_updated:
        print("Querying git history for last port updates...", file=sys.stderr)
        if local_versions:
            last_updates = asyncio.run(_find_last_updates(local_versions.keys()))
        print(f"Found last update information for {len(last_updates)} ports.", file=sys.stderr)

    print_report(
        maintainer_email,
        local_versions,
        local_uses,
        outdated_repology,
        github_latest,
        last_updates,
        disable_last_updated=disable_last_updated,
    )


if __name__ == "__main__":
    main()
