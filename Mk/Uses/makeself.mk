# $FreeBSD$
#
# handle makeself archives
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	makeself
# Usage:	USES=makeself
#
.if !defined(_INCLUDE_USES_MAKESELF_Mk)
_INCLUDE_USES_MAKESELF_MK=	yes

.if defined(makeself_ARGS)
IGNORE=	Incorrect 'USES+= makeself:${makeself_ARGS}' makeself takes no arguments
.endif

EXTRACT_DEPENDS+=	${UNMAKESELF_CMD}:${PORTSDIR}/archivers/unmakeself

EXTRACT_CMD=	${UNMAKESELF_CMD}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=

.endif
