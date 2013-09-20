# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	umlgraph
PORTVERSION=	5.6
CATEGORIES=	devel java
MASTER_SITES=	http://www.umlgraph.org/
DISTNAME=	UMLGraph-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	An automated drawing of UML diagrams

LICENSE=	BSD

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz \
		pic2plot:${PORTSDIR}/graphics/plotutils
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_FILES=	bin/umlgraph %%JAVAJARDIR%%/UmlGraph.jar

NO_STAGE=	yes
post-configure:
	${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|; \
		s|%%JAVAJARDIR%%|${JAVAJARDIR}|' \
		${WRKSRC}/bin/umlgraph

do-install:
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/UmlGraph.jar ${JAVAJARDIR}/
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/umlgraph ${PREFIX}/bin

.include <bsd.port.mk>
