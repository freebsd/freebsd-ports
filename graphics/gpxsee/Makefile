PORTNAME=	gpxsee
DISTVERSION=	16.17
CATEGORIES=	graphics geography

MAINTAINER=	mce@FreeBSD.org
COMMENT=	GPS log file viewer and analyzer
WWW=		https://www.gpxsee.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/licence.txt

USES=		compiler:c++11-lang desktop-file-utils gl qmake:outsource qt:6 \
		shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	tumic0
GH_PROJECT=	GPXSee
GH_TUPLE=	tumic0:GPXSee-maps:8ddbf3d:GPXSee
USE_GL=		opengl
USE_QT=		base multimedia positioning serialport svg tools:build

PORTDATA=	*

OPTIONS_DEFINE=		MAPS NLS TIFF
OPTIONS_DEFAULT=	MAPS TIFF
MAPS_DESC=		Install online maps catalogue
TIFF_DESC=		Support for GeoTIFF images
TIFF_USE=		QT=imageformats:run

pre-build-NLS-on:
	( cd ${BUILD_WRKSRC} && ${LRELEASE} ${WRKSRC}/${PORTNAME}.pro )

do-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/lang/*.qm ${STAGEDIR}${DATADIR}/translations

do-install-MAPS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/maps
	( cd ${WRKDIR}/GPXSee-maps-* && ${COPYTREE_SHARE} World \
		${STAGEDIR}${DATADIR}/maps "-name *.xml" )

.include <bsd.port.mk>
