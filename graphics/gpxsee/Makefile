PORTNAME=	gpxsee
DISTVERSION=	16.10
CATEGORIES=	graphics geography

MAINTAINER=	sikmir@gmail.com
COMMENT=	GPS log file viewer and analyzer
WWW=		https://www.gpxsee.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/licence.txt

USES=		compiler:c++11-lang desktop-file-utils gl qmake:outsource qt:6 \
		shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	tumic0
GH_PROJECT=	GPXSee
USE_GL=		opengl
USE_QT=		base multimedia positioning serialport svg tools:build

OPTIONS_DEFINE=	NLS TIFF
OPTIONS_DEFAULT=	TIFF
OPTIONS_SUB=	yes
TIFF_DESC=	Support for GeoTIFF images
TIFF_USE=	QT=imageformats:run

pre-build-NLS-on:
	( cd ${BUILD_WRKSRC} && ${LRELEASE} ${WRKSRC}/${PORTNAME}.pro )

do-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/lang/*.qm ${STAGEDIR}${DATADIR}/translations

.include <bsd.port.mk>
