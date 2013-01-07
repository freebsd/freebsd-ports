# Created by: ijliao
# $FreeBSD$

PORTNAME=	argouml
PORTVERSION=	0.34
CATEGORIES=	devel java
MASTER_SITES=	http://argouml-downloads.tigris.org/nonav/argouml-${PORTVERSION}/
DISTNAME=	ArgoUML-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		manual-${PORTVERSION}.pdf \
		quickguide-${PORTVERSION}.pdf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UML design tool with cognitive support

LICENSE=	EPL

PORTSCOUT=	limitw:1,even \
		site:${MASTER_SITES:S/argouml-${PORTVERSION}\///}

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

SUB_FILES=	argouml.sh
SUB_LIST=	JAVA_VERSION=${JAVA_VERSION}
PORTDOCS=	manual-${PORTVERSION}.pdf quickguide-${PORTVERSION}.pdf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

DESKTOP_ENTRIES=	"ArgoUML" \
			"Create advanced UML diagrams" \
			"${DATADIR}/icon/ArgoIcon128x128.png" \
			"argouml" \
			"Development;Building;Java;" \
			false

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/argouml.sh ${PREFIX}/bin/argouml
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DATADIR}
	@${MKDIR} ${DATADIR}/ext
	${INSTALL_DATA} ${WRKSRC}/ext/*.jar ${DATADIR}/ext
	${INSTALL_DATA} ${WRKSRC}/ext/*.xml ${DATADIR}/ext
	@${MKDIR} ${DATADIR}/icon
	${INSTALL_DATA} ${WRKSRC}/icon/*.png ${DATADIR}/icon
	${INSTALL_DATA} ${WRKSRC}/icon/*.svg ${DATADIR}/icon
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manual-${PORTVERSION}.pdf ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/quickguide-${PORTVERSION}.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
