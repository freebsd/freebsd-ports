# $FreeBSD$
#
# handle dependency depends on desktop-file-info and package regen
#
# MAINTAINER: gnome@FreeBSD.org
#
# Feature:	desktop-file-info
# Usage:	USES=desktop-file-info
# Valid ARGS:	does not require args
#
#
.if !defined(_INCLUDE_USES_DESKTOP_FILE_INFO_MK)
_INCLUDE_USES_DESKTOP_FILE_INFO_MK=	yes

.if defined(desktop-file-info_ARGS)
IGNORE=	USES=desktop-file-info does not require args
.endif

BUILD_DEPENDS+=	update-desktop-database:${PORTSDIR}/devel/desktop-file-utils
RUN_DEPENDS+=	update-desktop-database:${PORTSDIR}/devel/desktop-file-utils

# bolt our post-install target to post-install
post-install: desktop-file-post-install

desktop-file-post-install:
# run for port post-install
	@-update-desktop-database
# plist entries for packages.
	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-desktop-database > /dev/null || /usr/bin/true" \
		>> ${TMPPLIST}; \
	${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-desktop-database > /dev/null || /usr/bin/true" \
		>> ${TMPPLIST}

.endif
