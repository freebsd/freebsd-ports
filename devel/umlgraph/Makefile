PORTNAME=	umlgraph
DISTVERSIONPREFIX=	R
DISTVERSION=	5_7_2
CATEGORIES=	devel java

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automated drawing of UML diagrams

LICENSE=	BSD3CLAUSE

USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8
USE_GITHUB=	yes
GH_ACCOUNT=	dspinellis
GH_PROJECT=	UMLGraph

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
