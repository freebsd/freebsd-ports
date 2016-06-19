#!/bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org

set -e

. "${dp_SCRIPTSDIR}/functions.sh"

validate_env dp_ECHO_MSG dp_PKG_BIN dp_PORTNAME dp_PKGNAME

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_CHECK_VULNERABLE}" ] && set -x

set -u

# If the package is pkg, disable these checks, it fails while
# upgrading when pkg is not there.
# FIXME: check is this is still true
if [ "${dp_PORTNAME}" = "pkg" ]; then
	exit 0
fi

if [ ! -x "${dp_PKG_BIN}" ]; then
	exit 0
fi

vlist=$(${dp_PKG_BIN} audit "${dp_PKGNAME}" || :)

if [ "${vlist}" != "0 problem(s) in the installed packages found." ]; then
	${dp_ECHO_MSG} "===>  ${dp_PKGNAME} has known vulnerabilities:"
	${dp_ECHO_MSG} "$vlist"
	${dp_ECHO_MSG} "=> Please update your ports tree and try again."
	${dp_ECHO_MSG} "=> Note: Vulnerable ports are marked as such even if there is no update available."
	${dp_ECHO_MSG} "=> If you wish to ignore this vulnerability rebuild with 'make DISABLE_VULNERABILITIES=yes'"
	exit 1
fi
