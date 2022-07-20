PORTNAME=	filmulator
PORTVERSION=	0.11.1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simplified raw editor with the power of film

LICENSE=	GPLv3+

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexiv2.so:graphics/exiv2 \
		liblensfun.so:graphics/lensfun \
		libraw_r.so:graphics/libraw \
		librtprocess.so:graphics/librtprocess \
		libtiff.so:graphics/tiff

USES=		cmake jpeg libarchive pkgconfig qt:5
USE_GITHUB=	yes
USE_QT=		buildtools_build qmake_build core declarative gui \
		network sql widgets

GH_ACCOUNT=	CarVac
GH_PROJECT=	${PORTNAME}-gui

WRKSRC_SUBDIR=	${GH_PROJECT}

post-patch:
	@${REINPLACE_CMD} -e '/target_compile_definitions.*LF_GIT/d' \
		${WRKSRC}/CMakeLists.txt
# Prerendered PNG icon is 64x58 which Qt does not want to load, so use
# original SVG instead which is square.  Qt's icon engine supports SVG
# since Qt 4.2.
	@${REINPLACE_CMD} -e '/filmulator64icon/s,png,svg,' \
		${WRKSRC}/main.cpp ${WRKSRC}/resources/pixmaps.qrc

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	${INSTALL_DATA} ${WRKSRC}/filmulator-gui64.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/filmulator-gui.png
	${INSTALL_DATA} ${WRKSRC}/filmulator-gui.desktop.in \
		${STAGEDIR}${PREFIX}/share/applications/filmulator-gui.desktop

.include <bsd.port.mk>
