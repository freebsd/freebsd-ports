# $FreeBSD$

PORTNAME=	lpeg
PORTVERSION=	0.12
CATEGORIES=	devel
MASTER_SITES=	http://www.inf.puc-rio.br/~roberto/lpeg/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	olevole@olevole.ru
COMMENT=	Parsing Expression Grammars For Lua

LICENSE=	MIT

USES?=		lua

ALL_TARGET=	linux
MAKEFILE=	${WRKSRC}/makefile

PLIST_FILES=	%%LUA_MODLIBDIR%%/lpeg.so

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e \
		"s|%%INCDIR%%|${LUA_INCDIR}|" ${WRKSRC}/makefile

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so ${STAGEDIR}/${LUA_MODLIBDIR}

.include <bsd.port.post.mk>
