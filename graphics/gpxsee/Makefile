# Created by: Nikolay Korotkiy <sikmir@gmail.com>
# $FreeBSD$

PORTNAME=	gpxsee
DISTVERSION=	7.18
CATEGORIES=	graphics geography

MAINTAINER=	sikmir@gmail.com
COMMENT=	GPS log file viewer and analyzer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/licence.txt

USES=		compiler:c++11-lang desktop-file-utils gl qmake:outsource \
		qt:5 shared-mime-info
USE_QT=		buildtools_build concurrent core gui network opengl printsupport \
		sql sql-sqlite3_run widgets
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	tumic0
GH_PROJECT=	GPXSee

OPTIONS_DEFINE=	MAPS NLS PBF TIFF
OPTIONS_DEFAULT=	MAPS PBF TIFF
OPTIONS_SUB=	yes
MAPS_DESC=	Install map definitions of some well known global map services
NLS_USE=	QT=linguisttools_build
NLS_USES=	gettext-runtime
PBF_DESC=	Support for PBF vector maps
PBF_RUN_DEPENDS=	${QT_PLUGINDIR}/imageformats/libpbf.so:graphics/qtpbfimageplugin
TIFF_DESC=	Support for GeoTIFF images
TIFF_USE=	QT=imageformats_run

pre-build-NLS-on:
	( cd ${BUILD_WRKSRC} && ${LRELEASE} ${WRKSRC}/${PORTNAME}.pro )

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gpxsee ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}/csv
	${INSTALL_DATA} ${WRKSRC}/pkg/csv/* ${STAGEDIR}${DATADIR}/csv
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pkg/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/pkg/${PORTNAME}.xml ${STAGEDIR}${PREFIX}/share/mime/packages
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/pkg/appdata.xml ${STAGEDIR}${PREFIX}/share/metainfo/${PORTNAME}.appdata.xml

do-install-MAPS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/maps
	${INSTALL_DATA} ${WRKSRC}/pkg/maps/* ${STAGEDIR}${DATADIR}/maps

do-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/lang/*.qm ${STAGEDIR}${DATADIR}/translations

.include <bsd.port.mk>
