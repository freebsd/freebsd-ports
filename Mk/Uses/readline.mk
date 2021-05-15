# handle dependency on the readline port
#
# Feature:	readline
# Usage:	USES=readline
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_READLINE_MK)
_INCLUDE_USES_READLINE_MK=	yes

.if !empty(readline_ARGS)
IGNORE= Incorrect 'USES+= readline:${readline_ARGS}' readline takes no arguments
.endif

LIB_DEPENDS+=		libreadline.so.8:devel/readline
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

.endif
