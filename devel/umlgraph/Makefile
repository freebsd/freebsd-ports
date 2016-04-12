# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	umlgraph
PORTVERSION=	5.7.2
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/dspinellis/UMLGraph/archive/
DISTNAME=	R${PORTVERSION:S/./_/g}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Automated drawing of UML diagrams

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/UMLGraph-${DISTNAME}
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8

BUILD_DEPENDS=	dot:graphics/graphviz \
		pic2plot:graphics/plotutils
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_FILES=	bin/umlgraph %%JAVAJARDIR%%/UmlGraph.jar

post-configure:
	${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|; \
		s|%%JAVAJARDIR%%|${JAVAJARDIR}|' \
		${WRKSRC}/umlgraph

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/UmlGraph.jar ${STAGEDIR}${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/umlgraph ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
