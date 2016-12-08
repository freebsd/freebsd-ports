# $FreeBSD$

PORTNAME=	jgraphx
PORTVERSION=	2.5.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	java graphics

MAINTAINER=	makc@FreeBSD.org
COMMENT=	The Java Graph Diagram Component version X (jgraph v6+)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

USE_GITHUB=	yes
GH_ACCOUNT=	jgraph
USE_JAVA=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	*

OPTIONS_DEFINE=	COMPILE DOCS

COMPILE_DESC=	Compile from source instead of using provided binary
COMPILE_USE=	ANT=yes

do-build:
	@${DO_NADA}

do-build-COMPILE-on:
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
