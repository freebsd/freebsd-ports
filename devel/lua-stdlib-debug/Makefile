# $FreeBSD$

PORTNAME=	stdlib-debug
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sasaki@fcc.ad.jp
COMMENT=	Debug hints management library for lua

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

NO_ARCH=	yes
USES=		lua

USE_GITHUB=	yes
GH_ACCOUNT=	lua-stdlib
GH_PROJECT=	_debug

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}

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
