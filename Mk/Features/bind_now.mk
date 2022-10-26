# BIND_NOW Support

.if !defined(_BIND_NOW_MK_INCLUDED)
_BIND_NOW_MK_INCLUDED=	yes
BIND_NOW_Include_MAINTAINER=	portmgr@FreeBSD.org

.  if !defined(BIND_NOW_UNSAFE)
LDFLAGS+=	-Wl,-znow
.  endif
.endif
