# $FreeBSD$
#
# handle dependency on the libedit port
#
# Feature:	libedit
# Usage:	USES=libedit
# Valid ARGS:	none
#
# MAINTAINER:	portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_LIBEDIT_MK)
_INCLUDE_USES_LIBEDIT_MK=	yes
.include "${USESDIR}/localbase.mk"

LIB_DEPENDS+=	libedit.so.0:devel/libedit
.endif
