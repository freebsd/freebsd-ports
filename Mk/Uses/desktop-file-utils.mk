# $FreeBSD$
#
# handle dependency depends on desktop-file-utils and package regen
#
# MAINTAINER: gnome@FreeBSD.org
#
# Feature:	desktop-file-utils
# Usage:	USES=desktop-file-utils
# Valid ARGS:	does not require args
#
#
.if !defined(_INCLUDE_USES_DESKTOP_FILE_UTILS_MK)
_INCLUDE_USES_DESKTOP_FILE_UTILS_MK=	yes

.if defined(desktop-file-utils_ARGS)
IGNORE=	USES=desktop-file-utils does not require args
.endif

BUILD_DEPENDS+=	update-desktop-database:${PORTSDIR}/devel/desktop-file-utils
RUN_DEPENDS+=	update-desktop-database:${PORTSDIR}/devel/desktop-file-utils

# bolt our post-install target to post-install
.PHONY: desktop-file-post-install
post-install: desktop-file-post-install

desktop-file-post-install:
.if defined(NO_STAGE)
# run for port post-install
	@-update-desktop-database -q
.endif
# plist entries for packages.
	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-desktop-database -q > /dev/null || /usr/bin/true" \
		>> ${TMPPLIST}; \
	${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-desktop-database -q > /dev/null || /usr/bin/true" \
		>> ${TMPPLIST}

.endif
