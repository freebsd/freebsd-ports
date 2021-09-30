# LTO Support

LTO_Include_MAINTAINER=	pkubaj@FreeBSD.org

.if !defined(LTO_UNSAFE)
# Overridable as a user may want to use -flto
LTO_CFLAGS?=	-flto=thin
CFLAGS+=	${LTO_CFLAGS}
CXXFLAGS+=	${LTO_CFLAGS}
.endif
