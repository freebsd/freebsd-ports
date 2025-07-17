PORTNAME=	josm
PORTVERSION=	19423
CATEGORIES=	astro java
MASTER_SITES=	https://josm.openstreetmap.de/download/
DISTNAME=	${PORTNAME}-snapshot-${PORTVERSION}.jar
EXTRACT_SUFX=	# empty

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Comprehensive editor for OpenStreetMap.org database
WWW=		https://josm.openstreetmap.de/

LICENSE=	GPLv2+

PORTSCOUT=	ignore:1

NO_WRKSUBDIR=	yes

USES=		java zip:infozip
JAVA_VERSION=	11+

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	josm.sh
SUB_LIST=	JARNAME=${DISTNAME}

PLIST_FILES=	bin/josm \
		${JAVAJARDIR:C,${PREFIX}/?,,}/${DISTNAME} \
		share/pixmaps/josm.png

DESKTOP_ENTRIES="JOSM" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Education;Geoscience;Maps;" \
		true

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/josm.sh ${STAGEDIR}${PREFIX}/bin/josm
	${INSTALL_DATA} ${WRKSRC}/images/logo_32x32x32.png ${STAGEDIR}${PREFIX}/share/pixmaps/josm.png

.include <bsd.port.mk>
