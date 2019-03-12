# $FreeBSD$

PORTNAME=	lpeg
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.inf.puc-rio.br/~roberto/lpeg/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEG-based pattern-matching library for Lua

LICENSE=	MIT

USES=		lua

ALL_TARGET=	linux
MAKE_ARGS=	CC=${CC} LUADIR=${LUA_INCDIR}
MAKEFILE=	${WRKSRC}/makefile

PLIST_FILES=	${LUA_MODLIBDIR}/lpeg.so \
		${LUA_MODSHAREDIR}/re.lua

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/re.lua ${STAGEDIR}${LUA_MODSHAREDIR}

.include <bsd.port.mk>
