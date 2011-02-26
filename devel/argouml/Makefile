# ex:ts=8
# Ports collection makefile for:	ArgoUML
# Date created:			June 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	argouml
PORTVERSION=	0.32.1
CATEGORIES=	devel java
MASTER_SITES=	http://argouml-downloads.tigris.org/nonav/argouml-${PORTVERSION}/
DISTNAME=	ArgoUML-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		manual-${PORTVERSION}.pdf \
		quickguide-${PORTVERSION}.pdf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	A UML design tool with cognitive support

LICENSE=	EPL

PORTSCOUT=	limitw:1,even

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

SUB_FILES=	argouml.sh
PORTDOCS=	manual-${PORTVERSION}.pdf quickguide-${PORTVERSION}.pdf

DESKTOP_ENTRIES=	"ArgoUML" \
			"Create advanced UML diagrams" \
			"${DATADIR}/icon/ArgoIcon128x128.png" \
			"argouml" \
			"Application;Development;Building;Java;" \
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manual-${PORTVERSION}.pdf ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/quickguide-${PORTVERSION}.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
