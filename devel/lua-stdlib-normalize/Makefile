# $FreeBSD$

PORTNAME=	stdlib-normalize
PORTVERSION=	2.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sasaki@fcc.ad.jp
COMMENT=	Collection of normalized lua functions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}stdlib-debug>=0:devel/lua-stdlib-debug

NO_ARCH=	yes
USES=		lua

USE_GITHUB=	yes
GH_ACCOUNT=	lua-stdlib
GH_PROJECT=	normalize

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}/std/normalize
	${INSTALL_DATA} ${WRKSRC}/lib/std/normalize/_base.lua ${STAGEDIR}${LUA_MODSHAREDIR}/std/normalize
	${INSTALL_DATA} ${WRKSRC}/lib/std/normalize/_strict.lua ${STAGEDIR}${LUA_MODSHAREDIR}/std/normalize
	${INSTALL_DATA} ${WRKSRC}/lib/std/normalize/_typecheck.lua ${STAGEDIR}${LUA_MODSHAREDIR}/std/normalize
	${INSTALL_DATA} ${WRKSRC}/lib/std/normalize/init.lua ${STAGEDIR}${LUA_MODSHAREDIR}/std/normalize
	${INSTALL_DATA} ${WRKSRC}/lib/std/normalize/version.lua ${STAGEDIR}${LUA_MODSHAREDIR}/std/normalize

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/index.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ldoc.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
