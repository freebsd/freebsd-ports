# $FreeBSD$
#
# handle enforcing localbase in path
#
# Feature:	localbase
# Usage:	USES=localbase
# Valid ARGS:	none
#
# MAINTAINER:	portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_LOCALBASE_MK)
_INCLUDE_USES_LOCALBASE_MK=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif
