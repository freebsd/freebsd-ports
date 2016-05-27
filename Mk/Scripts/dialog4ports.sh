#! /bin/sh
# $FreeBSD$
# Maintainer: portmgr@FreeBSD.org
set -e

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_DIALOG4PORTS}" ] && set -x

if [ -z "${DIALOG4PORTS}" -o -z "${PORTSDIR}" -o -z "${MAKE}" ]; then
	echo "DIALOG4PORTS, MAKE and PORTSDIR required in environment." >&2
	exit 1
fi

: ${DIALOGPORT:=ports-mgmt/dialog4ports}
: ${DIALOGNAME:=dialog4ports}

OPTIONSFILE="$1"

if ! [ -e $DIALOG4PORTS ]; then
	# If INSTALL_AS_USER is set then just build and use the WRKDIR version
	# Also do this if PREFIX!=LOCALBASE to avoid missing file or double
	# installs
	if [ -n "${INSTALL_AS_USER}" -o "${PREFIX}" != "${LOCALBASE}" ]; then
		if ! [ -d "${PORTSDIR}/${DIALOGPORT}" ]; then
			echo "===> Skipping 'config' as ${DIALOGPORT} is not checked out" >&2
			exit 1
		fi
		DIALOG4PORTS=$(${MAKE} -C ${PORTSDIR}/${DIALOGPORT} -V DIALOG4PORTS)
		if ! [ -e "${DIALOG4PORTS}" ]; then
			echo "===> Building ${DIALOGNAME} as it is required for the config dialog"
			${MAKE} -C ${PORTSDIR}/${DIALOGPORT} -D NO_DIALOG clean build
		fi
	else
		# Build+install through su-install as normal
		echo "===> Building/installing ${DIALOGNAME} as it is required for the config dialog"
		${MAKE} -C ${PORTSDIR}/${DIALOGPORT} -D NO_DIALOG clean install
		# Need to clean again as it can't run twice in 1 call above
		${MAKE} -C ${PORTSDIR}/${DIALOGPORT} -D NO_DIALOG clean
	fi
fi

# Backwards compat with older version which used stdout [<= 0.1.1] (or stderr [0.1.2]).
# Clear environment of PKGNAME or the dialog will show on older versions
# that do not understand -v.
if ! env -u PKGNAME ${DIALOG4PORTS} -v > /dev/null 2>&1; then
	exec $DIALOG4PORTS > $OPTIONSFILE 2>&1
fi

# Newer versions use stderr to work around a jail issue
# http://lists.freebsd.org/pipermail/freebsd-ports/2013-March/082383.html
exec $DIALOG4PORTS 2> $OPTIONSFILE
