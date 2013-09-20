# Created by: Sergey V. Dyatko <sergey.dyatko@gmail.com>
# $FreeBSD$

PORTNAME=	lunit
PORTVERSION=	0.5
CATEGORIES=	devel
MASTER_SITES=	http://www.mroth.net/${PORTNAME}/
PKGNAMEPREFIX=	lua-

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Unit Testing Framework for Lua

LICENSE=	MIT

USE_LUA=	5.1

DOCFILES=	DOCUMENTATION README
EXAMPLES=	example.lua
LUNIT_FILES=	lunit-console.lua lunit-tests.lua lunit.lua

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} ==	"amd64"
CFLAGS+=	-fPIC
.endif

pre-install:
	${REINPLACE_CMD} -e 's|"lua"|"${LUA_CMD}"|g' ${WRKSRC}/lunit

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lunit ${PREFIX}/bin

.for lunit_part in ${LUNIT_FILES}
	${INSTALL_DATA} ${WRKSRC}/${lunit_part} ${LUA_MODSHAREDIR}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}"
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.lua ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}"
.endif

.include <bsd.port.mk>
