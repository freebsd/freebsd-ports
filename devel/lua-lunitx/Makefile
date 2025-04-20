PORTNAME=	lunitx
DISTVERSION=	0.8.1
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Extended version of lunit, a unit testing framework for Lua
WWW=		https://github.com/dcurrie/lunit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		lua:52-54

USE_GITHUB=	yes
GH_ACCOUNT=	dcurrie
GH_PROJECT=	lunit

CONFLICTS=	lua${LUA_FLAVOR}-lunit

NO_BUILD=	yes

PORTDOCS=	DOCUMENTATION README README.lunitx
PORTEXAMPLES=	examples/*

OPTIONS_DEFINE=	DOCS EXAMPLES

LUNIT_FILES=	lunit.lua lunitx.lua lunit/console.lua lunitx/atexit.lua

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
.for lunit_part in ${LUNIT_FILES}
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}/${lunit_part:H}
	${INSTALL_DATA} ${WRKSRC}/lua/${lunit_part} ${STAGEDIR}${LUA_MODSHAREDIR}/${lunit_part}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

post-install-DOCS-on:
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

post-install-EXAMPLES-on:
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

do-test:
	cd ${WRKSRC}/lua && ${LUA_CMD} ${WRKSRC}/test/selftest.lua

.include <bsd.port.mk>
