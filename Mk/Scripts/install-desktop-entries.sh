#!/bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org

set -e
set -o pipefail

. "${dp_SCRIPTSDIR}/functions.sh"

validate_env dp_SED dp_ECHO_CMD dp_STAGEDIR dp_DESKTOPDIR

[ -n "${DEBUG_MK_SCRIPTS}" ] || [ -n "${DEBUG_MK_SCRIPTS_INSTALL_DESKTOP_ENTRIES}" ] && set -x

set -u

while [ $# -ge 6 ]; do

	Name="${1}"
	Comment="${2}"
	Icon="${3}"
	Exec="${4}"
	Categories="${5}"
	StartupNotify="${6}"

	shift 6

	filename="$(${dp_ECHO_CMD} "${Exec}" | ${dp_SED} -e 's,^/,,g;s,[/ ],_,g;s,[^_[:alnum:]],,g').desktop"

	pathname="${dp_STAGEDIR}${dp_DESKTOPDIR}/${filename}"

	${dp_ECHO_CMD} "${dp_DESKTOPDIR}/${filename}" >> "${dp_TMPPLIST}"

	{
		${dp_ECHO_CMD} "[Desktop Entry]"
		${dp_ECHO_CMD} "Type=Application"
		${dp_ECHO_CMD} "Version=1.0"
		${dp_ECHO_CMD} "Name=${Name}"
	} > "${pathname}"

	if [ -n "${Comment}" ]; then
		comment="${Comment}"
	else
		comment="$(cd "${dp_CURDIR}" && ${dp_MAKE} -VCOMMENT)"
	fi

	${dp_ECHO_CMD} "GenericName=${comment}" >> "${pathname}"
	${dp_ECHO_CMD} "Comment=${comment}" >> "${pathname}"

	if [ -n "${Icon}" ]; then
		${dp_ECHO_CMD} "Icon=${Icon}" >> "${pathname}"
	fi

	${dp_ECHO_CMD} "Exec=${Exec}" >> "${pathname}"

	if [ -n "${Categories}" ]; then
		categories="${Categories}"
	else
		categories="$(cd "${dp_CURDIR}" && ${dp_MAKE} desktop-categories)"
	fi

	${dp_ECHO_CMD} "Categories=${categories}" >> "${pathname}"

	if [ -n "${StartupNotify}" ]; then
		${dp_ECHO_CMD} "StartupNotify=${StartupNotify}" >> "${pathname}"
	fi
done
