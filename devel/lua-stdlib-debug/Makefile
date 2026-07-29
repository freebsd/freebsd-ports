PORTNAME=	stdlib-debug
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sasaki12@gmail.com
COMMENT=	Debug hints management library for lua
WWW=		https://github.com/lua-stdlib/_debug

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		lua:module

USE_GITHUB=	yes
GH_ACCOUNT=	lua-stdlib
GH_PROJECT=	_debug

DOCSDIR=	${LUA_DOCSDIR}
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}/std/_debug
	${INSTALL_DATA} ${WRKSRC}/lib/std/_debug/init.lua ${STAGEDIR}${LUA_MODSHAREDIR}/std/_debug
	${INSTALL_DATA} ${WRKSRC}/lib/std/_debug/version.lua ${STAGEDIR}${LUA_MODSHAREDIR}/std/_debug

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/index.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ldoc.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
