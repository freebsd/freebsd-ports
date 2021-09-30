# LTO Support

LTO_Include_MAINTAINER=	pkubaj@FreeBSD.org

.if !defined(LTO_UNSAFE)
# Overridable as a user may want to use -flto
LTO_FLAGS?=	-flto=thin
CFLAGS+=	${LTO_FLAGS}
CXXFLAGS+=	${LTO_FLAGS}
LDFLAGS+=	${LTO_FLAGS}
.endif
