#!/usr/bin/env python3
#
# repology-get-maintainer-stats.py - print aggregate FreeBSD ports maintainer
# statistics as reported by repology.org.
#
# MAINTAINER= yuri@FreeBSD.org
#

import argparse
import getpass
import importlib.util
import re
import sys
from urllib.parse import quote

REPOLOGY_MAINTAINER_URL = "https://repology.org/maintainer/{maintainer}"
USER_AGENT = (
    "repology-get-maintainer-stats.py "
    "(FreeBSD ports tools; https://www.freebsd.org/ports/)"
)


def check_dependencies() -> None:
    """Verify that all non-stdlib dependencies are available."""
    missing = []
    for module, package in (("requests", "requests"), ("bs4", "beautifulsoup4")):
        if importlib.util.find_spec(module) is None:
            missing.append(package)
    if missing:
        pkg_prefix = f" py{sys.version_info.major}{sys.version_info.minor}-"
        print(
            "Error: missing required package(s): " + ", ".join(missing),
            file=sys.stderr,
        )
        print(
            f"Install with: sudo pkg install{pkg_prefix}" + pkg_prefix.join(missing),
            file=sys.stderr,
        )
        sys.exit(1)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Print FreeBSD ports maintainer statistics from repology.org."
    )
    parser.add_argument(
        "maintainer",
        nargs="?",
        default=f"{getpass.getuser()}@FreeBSD.org",
        help="maintainer e-mail address (default: %(default)s)",
    )
    args = parser.parse_args()
    if len(sys.argv) > 2:
        parser.error("at most one maintainer argument is allowed")
    return args


def fetch_maintainer_page(maintainer: str) -> str:
    import requests

    url = REPOLOGY_MAINTAINER_URL.format(maintainer=quote(maintainer, safe="@"))
    try:
        response = requests.get(url, headers={"User-Agent": USER_AGENT}, timeout=30)
    except requests.RequestException as exc:
        print(f"Error fetching {url}: {exc}", file=sys.stderr)
        sys.exit(1)
    if response.status_code == 404:
        print(
            f"Error: maintainer '{maintainer}' was not found on repology.org.",
            file=sys.stderr,
        )
        sys.exit(1)
    response.raise_for_status()
    return response.text


def _cell_text(cell) -> str:
    """Return stripped text from a BeautifulSoup table cell."""
    return " ".join(cell.stripped_strings)


def extract_freebsd_stats(html: str) -> dict[str, str]:
    """Parse the repology maintainer page and return FreeBSD Ports aggregate stats."""
    from bs4 import BeautifulSoup

    soup = BeautifulSoup(html, "html.parser")

    # The page contains multiple tables; the one we need has a header with
    # "Repository" and "Packages".
    table = None
    for tbl in soup.find_all("table"):
        header_cells = tbl.find_all("th")
        texts = [_cell_text(c).lower() for c in header_cells]
        if "repository" in texts and "packages" in texts:
            table = tbl
            break

    if table is None:
        print(
            "Error: could not locate the repository activity table.",
            file=sys.stderr,
        )
        sys.exit(1)

    freebsd_row = None
    total_row = None
    for row in table.find("tbody").find_all("tr"):
        cells = row.find_all(["td", "th"])
        if not cells:
            continue
        first = _cell_text(cells[0]).strip()
        if re.search(r"FreeBSD\s+Ports", first, re.IGNORECASE):
            freebsd_row = cells
        elif first.lower() == "total":
            total_row = cells

    row = freebsd_row or total_row
    if row is None:
        print(
            "Error: no FreeBSD Ports or Total statistics row found.",
            file=sys.stderr,
        )
        sys.exit(1)

    # Cells layout: Repository, Packages, Projects Total, Newest, Newest%,
    # Outdated, Outdated%, Problematic, Problematic%, Potentially vulnerable,
    # Potentially vulnerable%, Other lists, Feeds.
    # We extract the first 11 meaningful cells.
    texts = [_cell_text(c) for c in row]
    if len(texts) < 11:
        print(
            "Error: unexpected table row format on repology.org.",
            file=sys.stderr,
        )
        sys.exit(1)

    return {
        "repository": texts[0],
        "packages": texts[1],
        "projects_total": texts[2],
        "newest": texts[3],
        "newest_pct": texts[4],
        "outdated": texts[5],
        "outdated_pct": texts[6],
        "problematic": texts[7],
        "problematic_pct": texts[8],
        "vulnerable": texts[9],
        "vulnerable_pct": texts[10],
    }


def format_table(stats: dict[str, str]) -> str:
    headers = [
        "Packages",
        "Projects Total",
        "Newest",
        "Outdated",
        "Problematic",
        "Potentially Vulnerable",
    ]
    values = [
        stats["packages"],
        stats["projects_total"],
        f"{stats['newest']} ({stats['newest_pct']})",
        f"{stats['outdated']} ({stats['outdated_pct']})",
        f"{stats['problematic']} ({stats['problematic_pct']})",
        f"{stats['vulnerable']} ({stats['vulnerable_pct']})",
    ]

    widths = [
        max(len(h), len(v)) for h, v in zip(headers, values)
    ]

    def horizontal() -> str:
        return "+" + "+".join("-" * (w + 2) for w in widths) + "+"

    def line(cells) -> str:
        return (
            "|"
            + "|".join(
                f" {cell.ljust(width)} " for cell, width in zip(cells, widths)
            )
            + "|"
        )

    return "\n".join(
        [horizontal(), line(headers), horizontal(), line(values), horizontal()]
    )


def main() -> None:
    check_dependencies()
    args = parse_args()
    maintainer = args.maintainer

    print(f"Maintainer: {maintainer}")
    html = fetch_maintainer_page(maintainer)
    stats = extract_freebsd_stats(html)
    print(format_table(stats))


if __name__ == "__main__":
    main()
