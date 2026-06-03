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
import urllib.request
import urllib.parse
import urllib.error
import ssl

# --- Dependency check ---

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
    """Return (account, project) for USE_GITHUB=yes ports, else None."""
    use_github = get_makefile_var(makefile_path, "USE_GITHUB")
    if not use_github or use_github.lower() != "yes":
        return None

    portname = get_makefile_var(makefile_path, "PORTNAME")
    if not portname:
        return None

    gh_account = get_makefile_var(makefile_path, "GH_ACCOUNT") or portname
    gh_project = get_makefile_var(makefile_path, "GH_PROJECT") or portname
    gh_account = resolve_make_value(gh_account.split()[0], portname)
    gh_project = resolve_make_value(gh_project.split()[0], portname)
    return gh_account, gh_project


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
    Return (versions, uses_types, github_repos) keyed by port origin.
    versions[origin] = real version string
    uses_types[origin] = comma-separated port type string
    github_repos[origin] = (account, project) for USE_GITHUB ports
    """
    versions = {}
    uses_types = {}
    github_repos = {}
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

    return versions, uses_types, github_repos


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

    quoted_account = urllib.parse.quote(account, safe="")
    quoted_project = urllib.parse.quote(project, safe="")
    url = f"{GITHUB_API_BASE}/repos/{quoted_account}/{quoted_project}/releases/latest"

    try:
        with github_request(url) as resp:
            data = json.load(resp)
    except urllib.error.HTTPError as e:
        if e.code != 404:
            print(
                f"Warning: Could not query GitHub latest release for {account}/{project}: HTTP {e.code}",
                file=sys.stderr,
            )
        cache[key] = None
        return None
    except urllib.error.URLError as e:
        print(
            f"Warning: Could not query GitHub latest release for {account}/{project}: {e.reason}",
            file=sys.stderr,
        )
        cache[key] = None
        return None
    except Exception as e:
        print(
            f"Warning: Could not query GitHub latest release for {account}/{project}: {e}",
            file=sys.stderr,
        )
        cache[key] = None
        return None

    tag = (data.get("tag_name") or "").strip()
    cache[key] = tag.strip() or None
    return cache[key]


def query_github_releases(github_repos):
    """Return dict {origin: latest_release_tag} for GitHub-based ports with releases."""
    cache = {}
    latest_releases = {}

    unique_repos = sorted(set(github_repos.values()))
    with concurrent.futures.ThreadPoolExecutor(max_workers=16) as executor:
        future_map = {
            executor.submit(query_github_latest_release, account, project, cache): (account, project)
            for account, project in unique_repos
        }
        for future in concurrent.futures.as_completed(future_map):
            future.result()

    for origin, repo in github_repos.items():
        latest = cache.get(repo)
        if latest:
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


def print_report(maintainer_email, local_versions, local_uses, outdated_repology, github_latest):
    total_ports = len(local_versions)

    headers = [
        "Port origin",
        "Latest released version",
        "Current port version",
        "Outdatedness level",
        "Port Type",
        "Notes",
    ]

    major_ports = []
    minor_ports = []
    patch_ports = []

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
        row = (
            origin,
            display_version(latest["real"], latest["aux"]),
            display_version(local_real, local_aux),
            level,
            port_type,
            latest["notes"],
        )
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


# --- Main ---

def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <maintainer-email>", file=sys.stderr)
        sys.exit(1)

    maintainer_email = sys.argv[1]
    check_portsdir()

    print(f"Scanning {PORTSDIR} for ports maintained by {maintainer_email}...", file=sys.stderr)
    local_versions, local_uses, github_repos = find_maintained_ports(maintainer_email)

    if not local_versions:
        print(f"No ports maintained by {maintainer_email}")
        sys.exit(0)

    print(
        f"Found {len(local_versions)} local ports ({len(github_repos)} GitHub-based). Querying Repology and GitHub...",
        file=sys.stderr,
    )
    outdated_repology = query_repology_outdated(maintainer_email)
    github_latest = query_github_releases(github_repos)
    print(f"Repology reports {len(outdated_repology)} outdated FreeBSD ports.", file=sys.stderr)
    print(f"GitHub provides latest releases for {len(github_latest)} GitHub-based ports.", file=sys.stderr)

    print_report(maintainer_email, local_versions, local_uses, outdated_repology, github_latest)


if __name__ == "__main__":
    main()
