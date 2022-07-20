PORTNAME=	bitop
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://bitop.luajit.org/download/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTNAME=	LuaBitOp-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bitwise operations on numbers

LICENSE=	MIT

USES=		gmake lua:module

CFLAGS+=	-I${LUA_INCDIR}
MAKE_ARGS=	CC=${CC} LUA=${LUA_CMD}
TEST_TARGET=	test

PLIST_FILES=	${LUA_MODLIBDIR}/bit.so

.include <bsd.port.pre.mk>

.if ${LUA_VER_STR} >= 53
CFLAGS+=	-DLUA_NUMBER_DOUBLE
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-bittest.lua
.endif

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}/
	${INSTALL_LIB} ${WRKSRC}/bit.so ${STAGEDIR}${LUA_MODLIBDIR}/

.include <bsd.port.post.mk>
