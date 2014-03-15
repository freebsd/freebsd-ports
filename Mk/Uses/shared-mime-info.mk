# $FreeBSD$
#
# handle dependency depends on shared-mime-info and package regen
#
# Feature:	shared-mime-info
# Usage:	USES=shared-mime-info
# Valid ARGS:	does not require args
#
# MAINTAINER: gnome@FreeBSD.org

.if !defined(_INCLUDE_USES_SHARED_MIME_INFO_MK)
_INCLUDE_USES_SHARED_MIME_INFO_MK=	yes

.if defined(shared-mime-info_ARGS)
IGNORE=	USES=shared-mime-info does not require args
.endif

BUILD_DEPENDS+=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS+=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

shared-mime-post-install:
.if defined(NO_STAGE)
# run for port post-install
	@-update-mime-database ${PREFIX}/share/mime
.endif
# plist entries for packages.
	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-mime-database %D/share/mime" \
		>> ${TMPPLIST}; \
	${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-mime-database %D/share/mime" \
		>> ${TMPPLIST}

.endif
