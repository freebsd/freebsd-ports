PORTNAME=	lunit
PORTVERSION=	0.5
CATEGORIES=	devel
MASTER_SITES=	http://www.mroth.net/${PORTNAME}/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Unit Testing Framework for Lua

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		lua

NO_BUILD=	yes

DOCFILES=	DOCUMENTATION README
EXAMPLES=	example.lua
LUNIT_FILES=	lunit-console.lua lunit-tests.lua lunit.lua

post-patch:
	${REINPLACE_CMD} -e 's|"lua"|"${LUA_CMD}"|g' ${WRKSRC}/lunit

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lunit ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
.for lunit_part in ${LUNIT_FILES}
	${INSTALL_DATA} ${WRKSRC}/${lunit_part} ${STAGEDIR}${LUA_MODSHAREDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.lua ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
