# $FreeBSD$

PORTNAME=	lpeg
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.inf.puc-rio.br/~roberto/lpeg/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEG-based pattern-matching library for Lua

LICENSE=	MIT

ALL_TARGET=	linux
CFLAGS+=	-DLUA_32BITS
MAKE_ARGS=	CC=${CC} LUADIR=${LUA_INCDIR}
MAKEFILE=	${WRKSRC}/makefile
USES?=		lua

PLIST_FILES=	${LUA_MODLIBDIR}/lpeg.so

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
