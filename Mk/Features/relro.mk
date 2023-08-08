# RELRO Support

.if !defined(_RELRO_MK_INCLUDED)
_RELRO_MK_INCLUDED=	yes
RELRO_Include_MAINTAINER=	portmgr@FreeBSD.org

.  if !defined(RELRO_UNSAFE)
LDFLAGS+=	-Wl,-zrelro
.  endif
.endif
