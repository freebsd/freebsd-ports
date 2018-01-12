# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bitop
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://bitop.luajit.org/download/ \
		LOCAL/sunpoet
DISTNAME=	LuaBitOp-${PORTVERSION}
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bitwise operations on numbers

LICENSE=	MIT

CFLAGS+=	-DLUA_NUMBER_LONG_LONG -I${LUA_INCDIR}
MAKE_ARGS=	CC=${CC} LUA=${LUA_CMD}
TEST_TARGET=	test
USES?=		gmake lua

PLIST_FILES=	%%LUA_MODLIBDIR%%/bit.so

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}/
	${INSTALL_LIB} ${WRKSRC}/bit.so ${STAGEDIR}${LUA_MODLIBDIR}/

.include <bsd.port.mk>
