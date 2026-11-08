#!/bin/sh
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Generates a pkg-config-format SBOM base file (pc(5)) describing a single
# package or subpackage, to be installed as
# ${PREFIX}/share/sbom/pc/${dp_SBOMNAME}.pc
#

set -e
set -o pipefail

. "${dp_SCRIPTSDIR}/functions.sh"

validate_env dp_ACTUAL_PACKAGE_DEPENDS dp_COMMENT dp_LICENSE dp_LICENSE_COMB \
	dp_MAINTAINER dp_PKGBASE dp_PKGORIGIN dp_PKGVERSION dp_PKG_BIN \
	dp_PKG_IGNORE_DEPENDS dp_PORTVERSION dp_PORT_SBOM_COPYRIGHT \
	dp_PORT_SBOM_CPE dp_PORT_SBOM_PROVIDES \
	dp_PORT_SBOM_SOURCE dp_PORT_SBOM_URL dp_PREFIX \
	dp_SBOMDIR dp_SBOMNAME dp_SCRIPTSDIR dp_STAGEDIR

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_CREATE_SBOM}" ] && set -x

set -u

# Escape a literal value for use in a pc(5) stanza.
pc_escape() {
	printf '%s' "$1" | tr '\n\t' '  ' | sed -e 's/\$/$$/g; s/#/\\#/g'
}

mkdir -p "${dp_STAGEDIR}${dp_SBOMDIR}"

# Save stdout and redirect it to the SBOM file.
exec 3>&1 >"${dp_STAGEDIR}${dp_SBOMDIR}/${dp_SBOMNAME}.pc"

# pc(5) variables queryable with `pkgconf --variable=pkgversion ${dp_SBOMNAME}`.
echo "pkgversion=$(pc_escape "${dp_PKGVERSION}")"
echo "origin=${dp_PKGORIGIN}"
echo

cat <<EOT
Name: ${dp_SBOMNAME}
Description: $(pc_escape "${dp_COMMENT}")
Version: $(pc_escape "${dp_PORTVERSION}")
EOT

if [ -n "${dp_LICENSE}" ]; then
	if [ "${dp_LICENSE_COMB}" = "dual" ]; then
		_license_join=" OR "
	else
		_license_join=" AND "
	fi
	echo "License: $(echo "${dp_LICENSE}" | sed -e "s/[[:space:]][[:space:]]*/${_license_join}/g")"
fi
[ -z "${dp_MAINTAINER}" ] || echo "Maintainer: $(pc_escape "${dp_MAINTAINER}")"
[ -z "${dp_PORT_SBOM_URL}" ] || echo "URL: $(pc_escape "${dp_PORT_SBOM_URL}")"
[ -z "${dp_PORT_SBOM_SOURCE}" ] || echo "Source: $(pc_escape "${dp_PORT_SBOM_SOURCE}")"
[ -z "${dp_PORT_SBOM_COPYRIGHT}" ] || echo "Copyright: $(pc_escape "${dp_PORT_SBOM_COPYRIGHT}")"

requires=$(eval "${dp_ACTUAL_PACKAGE_DEPENDS}" 2>/dev/null |
	{ grep -v -E "${dp_PKG_IGNORE_DEPENDS}" || :; } |
	sed -n 's/^"\([^"]*\)".*/\1/p' |
	sort -u |
	paste -sd, -)
[ -z "${requires}" ] || echo "Requires: ${requires}"
[ -z "${dp_PORT_SBOM_PROVIDES}" ] || echo "Provides: ${dp_PORT_SBOM_PROVIDES}"

echo "FreeBSD-Pkgversion: $(pc_escape "${dp_PKGVERSION}")"
echo "FreeBSD-Origin: ${dp_PKGORIGIN}"
[ -z "${dp_PORT_SBOM_CPE}" ] || echo "FreeBSD-CPE: $(pc_escape "${dp_PORT_SBOM_CPE}")"
