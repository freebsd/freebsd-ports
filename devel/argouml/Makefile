PORTNAME=	argouml
DISTVERSION=	0.35.1
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/argouml-tigris-org/argouml/releases/download/VERSION_${DISTVERSION:C/\./_/g}/
DISTNAME=	ArgoUML-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		manual-${DISTVERSION}.pdf \
		quickguide-${DISTVERSION}.pdf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UML design tool with cognitive support
WWW=		https://github.com/argouml-tigris-org/argouml/wiki

LICENSE=	EPL

USES=		java
JAVA_VERSION=	${ARGOUML_JAVA_VERSION:U8 11 17 18}

DESKTOP_ENTRIES=	"ArgoUML" \
			"Create advanced UML diagrams" \
			"${DATADIR}/icon/ArgoIcon128x128.png" \
			"argouml" \
			"Development;Building;Java;" \
			false
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limitw:1,even \
		site:${MASTER_SITES:S/argouml-${DISTVERSION}\///}
SUB_FILES=	argouml.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PORTDOCS=	manual-${DISTVERSION}.pdf quickguide-${DISTVERSION}.pdf

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/argouml.sh ${STAGEDIR}${PREFIX}/bin/argouml
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/ext
	${INSTALL_DATA} ${WRKSRC}/ext/*.jar ${STAGEDIR}${DATADIR}/ext
	${INSTALL_DATA} ${WRKSRC}/ext/*.xml ${STAGEDIR}${DATADIR}/ext
	@${MKDIR} ${STAGEDIR}${DATADIR}/icon
	${INSTALL_DATA} ${WRKSRC}/icon/*.png ${STAGEDIR}${DATADIR}/icon
	${INSTALL_DATA} ${WRKSRC}/icon/*.svg ${STAGEDIR}${DATADIR}/icon

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manual-${DISTVERSION}.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/quickguide-${DISTVERSION}.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
