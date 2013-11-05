# $FreeBSD$
#
# handle dependency on the readline port
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	readline
# Usage:	USES=readline
# Valid ARGS:	port
#

.if !defined(_INCLUDE_USES_READLINE_MK)
_INCLUDE_USES_READLINE_MK=	yes

.if !exists(/usr/lib/libreadline.so)
readline_ARGS=	port
.endif

.if defined(readline_ARGS) && ${readline_ARGS} == port
LIB_DEPENDS+=		libreadline.so.6:${PORTSDIR}/devel/readline
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib -lreadline
.endif

.endif
