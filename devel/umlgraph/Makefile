# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	umlgraph
PORTVERSION=	5.6
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.umlgraph.org/
DISTNAME=	UMLGraph-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Automated drawing of UML diagrams

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz \
		pic2plot:${PORTSDIR}/graphics/plotutils
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_FILES=	bin/umlgraph %%JAVAJARDIR%%/UmlGraph.jar

post-configure:
	${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|; \
		s|%%JAVAJARDIR%%|${JAVAJARDIR}|' \
		${WRKSRC}/bin/umlgraph

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/UmlGraph.jar ${STAGEDIR}${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/umlgraph ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
