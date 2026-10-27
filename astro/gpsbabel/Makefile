PORTNAME=	gpsbabel
DISTVERSIONPREFIX=	${PORTNAME}_
DISTVERSION=	1_10_0
CATEGORIES=	astro geography

MAINTAINER=	dev2@heesakkers.info
COMMENT=	GPS file translating tool
WWW=		https://www.gpsbabel.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++20-lang qt:6
USE_QT=		5compat base declarative serialport webchannel \
		tools:build
USE_GITHUB=	yes

CMAKE_ARGS=	-DGPSBABEL_WITH_LIBUSB=custom \
		-DGPSBABEL_EXTRA_LINK_LIBRARIES=usb

CONFLICTS=	gpsbabel14

OPTIONS_DEFINE=		WEBENGINE
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_armv7=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE
OPTIONS_DEFAULT_powerpc64le=	WEBENGINE

WEBENGINE_DESC=		Map preview in the GUI (requires QtWebEngine)
WEBENGINE_USE=		QT=webengine
WEBENGINE_CMAKE_BOOL=	GPSBABEL_MAPPREVIEW

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gpsbabel ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gui/GPSBabelFE/gpsbabelfe \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/gui/gpsbabel.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/gui/*.qm ${STAGEDIR}${DATADIR}/translations/
	${INSTALL_DATA} ${WRKSRC}/gui/images/appicon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/gpsbabel.png


.include <bsd.port.mk>
