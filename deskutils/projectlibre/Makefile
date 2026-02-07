PORTNAME=	projectlibre
DISTVERSION=	1.9.8
CATEGORIES=	deskutils editors java
MASTER_SITES=	SF/${PORTNAME}/ProjectLibre/${PORTVERSION:S/.0$//} \
		LOCAL/cpm/projectlibre/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Open source desktop alternative to Microsoft Project
WWW=		https://www.projectlibre.com/projectlibre-desktop/

LICENSE=	CPAL-1.0
LICENSE_FILE=	${WRKSRC}/license/license.txt

USES=		java
JAVA_VERSION=	21+

DATADIR=	${JAVASHAREDIR}/${PORTNAME}-${PORTVERSION}
DESKTOP_ENTRIES="ProjectLibre" \
		"" \
		"${PREFIX}/share/pixmaps/projectlibre.png" \
		"${PORTNAME}" \
		"Office;ProjectManagement;" \
		false
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	projectlibre.sh
SUB_LIST=	JAVA="${JAVA}"

DATAFILES=	lib projectlibre.jar readme.html

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${DATAFILES}" ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/projectlibre.sh ${STAGEDIR}${PREFIX}/bin/projectlibre
	${INSTALL_DATA} ${_DISTDIR}/projectlibre.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
