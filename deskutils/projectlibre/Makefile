# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	projectlibre
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	deskutils editors java
MASTER_SITES=	SF/${PORTNAME}/ProjectLibre/${PORTVERSION:S/.0$//} \
		LOCAL/cpm/projectlibre/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Open source desktop alternative to Microsoft Project

LICENSE=	CPAL-1.0

USE_JAVA=	yes

NO_ARCH=	yes
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}-${PORTVERSION}
DATAFILES=	lib projectlibre.jar readme.html

DESKTOP_ENTRIES="ProjectLibre" \
		"" \
		"${PREFIX}/share/pixmaps/projectlibre.png" \
		"${PORTNAME}" \
		"Office;ProjectManagement;" \
		false

SUB_FILES=	projectlibre.sh

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${DATAFILES}" ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/projectlibre.sh ${STAGEDIR}${PREFIX}/bin/projectlibre
	${INSTALL_DATA} ${_DISTDIR}/projectlibre.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
