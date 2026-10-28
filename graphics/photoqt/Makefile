PORTNAME=	photoqt
DISTVERSION=	5.4.1
CATEGORIES=	graphics
MASTER_SITES=	https://photoqt.org/downloads/source/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple, powerful and good looking Qt image viewer
WWW=		https://photoqt.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		liblcms2.so:graphics/lcms2 \
		libraw.so:graphics/libraw \
		libresvg.so:graphics/resvg-capi \
		libwayland-client.so:graphics/wayland \
		libyaml-cpp.so:devel/yaml-cpp \
		libZXing.so:textproc/zxing-cpp

USES=		cmake:testing compiler:c++17-lang desktop-file-utils \
		display:test gl kde:6 libarchive localbase:ldflags qt:6 ssl
USE_GL=		opengl
USE_KDE=	ecm:build
USE_QT=		base declarative multimedia imageformats:run location:run \
		positioning:run quick3d:run sqldriver-sqlite:run \
		sqldriver-sqlite:test svg tools:build

CMAKE_ON=		WITH_EXIV2 WITH_EXTENSIONS_NONSYS_OPENSSL \
			WITH_EXTENSIONS_SUPPORT WITH_LCMS2 WITH_LIBARCHIVE \
			WITH_LIBRAW WITH_LOCATION WITH_PHOTOSPHERE WITH_RESVG \
			WITH_WAYLANDSPECIFIC WITH_ZXING
CMAKE_OFF=		WITH_ADAPTSOURCE WITH_CHROMECAST_PIPINSTALL WITH_DEVIL \
			WITH_FFMPEGTHUMBNAILER WITH_LIBSAI WITH_LIBVIPS \
			WITH_PHOTOSPHERE_QRHI WITH_PUGIXML WITH_TESTING
CMAKE_TESTING_ON=	WITH_TESTING
CMAKE_TESTING_JOBS=	1 # tests share /tmp/photoqt_test
TEST_ENV=		LC_ALL=en_US.UTF-8 # QCollator ignores numeric mode in the C locale

OPTIONS_DEFINE=		CHROMECAST MPV
OPTIONS_DEFAULT=	IMAGEMAGICK MPV POPPLER
OPTIONS_RADIO=		PDF
OPTIONS_RADIO_PDF=	POPPLER QTPDF
OPTIONS_SINGLE=		MAGICK
OPTIONS_SINGLE_MAGICK=	GRAPHMAGICK IMAGEMAGICK

CHROMECAST_DESC=	Stream images to Chromecast devices (via Python)
MAGICK_DESC=		Magick++ backend
MPV_DESC=		Video playback via libmpv (in addition to QtMultimedia)
PDF_DESC=		PDF/PostScript backend
POPPLER_DESC=		Render PDF with Poppler
QTPDF_DESC=		Render PDF with QtPdf (Chromium PDFium)

CHROMECAST_BUILD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pychromecast>0:net/py-pychromecast@${PY_FLAVOR}
CHROMECAST_USES=		python
CHROMECAST_CMAKE_BOOL=		WITH_CHROMECAST
CHROMECAST_CMAKE_ON=		-DPython3_EXECUTABLE:FILEPATH=${PYTHON_CMD}

GRAPHMAGICK_LIB_DEPENDS=	libGraphicsMagick++.so:graphics/GraphicsMagick
GRAPHMAGICK_CMAKE_BOOL=		WITH_GRAPHICSMAGICK

IMAGEMAGICK_USES=	magick:7
IMAGEMAGICK_CMAKE_BOOL=	WITH_IMAGEMAGICK

MPV_LIB_DEPENDS=	libmpv.so:multimedia/mpv
MPV_CMAKE_BOOL=		WITH_VIDEO_MPV

POPPLER_LIB_DEPENDS=	libpoppler-qt6.so:graphics/poppler-qt6 \
			libpoppler.so:graphics/poppler
POPPLER_CMAKE_BOOL=	WITH_POPPLER

QTPDF_USE=		QT=pdf
QTPDF_CMAKE_BOOL=	WITH_QTPDF

# The test targets do not repeat the ResvgQt.h detection done for the
# main target, so they look for <resvg/resvg.h>, which is not installed.
post-patch:
	@${REINPLACE_CMD} \
		-e 's|PRIVATE PQMRESVG)|PRIVATE PQMRESVG $$<$$<BOOL:$${RESVGQTINC}>:PQMRESVG_QT>)|' \
		${WRKSRC}/testing/*/CMakeLists.txt

.include <bsd.port.mk>
