PORTNAME=	krita
DISTVERSION=	6.0.2.1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sketching and painting program
WWW=		https://krita.org

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

BUILD_DEPENDS=	boost-libs>=1.65:devel/boost-libs \
		immer>=0:devel/immer \
		lager>=0:devel/lager \
		zug>=0:devel/zug
BUILD_DEPENDS+=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_aarch64=	xsimd>=8.1:devel/xsimd
BUILD_DEPENDS_amd64=	xsimd>=8.1:devel/xsimd
LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio \
		libexiv2.so:graphics/exiv2 \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgif.so:graphics/giflib \
		libgsl.so:math/gsl \
		libharfbuzz.so:print/harfbuzz \
		libheif.so:graphics/libheif \
		libjxl.so:graphics/libjxl \
		libKDcrawQt6.so:graphics/libkdcraw \
		liblcms2.so:graphics/lcms2 \
		libmypaint.so:graphics/libmypaint \
		libopenjp2.so:graphics/openjpeg \
		libpng.so:graphics/png \
		libpoppler.so:graphics/poppler \
		libpoppler-qt6.so:graphics/poppler-qt6 \
		libquazip1-qt6.so:archivers/quazip \
		libtiff.so:graphics/tiff \
		libturbojpeg.so:graphics/libjpeg-turbo \
		libunibreak.so:textproc/libunibreak \
		libwebp.so:graphics/webp

USES=		cmake compiler:c++17-lang desktop-file-utils eigen:3 gettext \
		gnome jpeg kde:6 localbase:ldflags mlt:7 pkgconfig python qt:6 \
		sdl shared-mime-info tar:xz xorg
USE_GNOME=	glib20
USE_KDE=	colorscheme completion config coreaddons crash \
		guiaddons i18n itemviews widgetsaddons \
		ecm:build
USE_QT=		5compat base svg \
		sqldriver-sqlite:run
USE_SDL=	sdl2
USE_XORG=	ice sm x11 xcb xext xi

CMAKE_ARGS=	-DALLOW_UNSTABLE=QT6
CMAKE_ON=	BUILD_WITH_QT6

PLIST_SUB=	SHLIB_VER=21.0.0 \
		SHLIB_SHVER=21

OPTIONS_DEFINE=		PYTHON OPENEXR
OPTIONS_DEFAULT=	PYTHON OPENEXR
OPTIONS_SUB=		yes

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
			libKSeExpr.so:graphics/kseexpr
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR

PYTHON_BUILD_DEPENDS=	${PY_SETUPTOOLS}
PYTHON_USES=		pyqt:6
PYTHON_USE=		PYQT=pyqt6,pysip,sip:build
PYTHON_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_PyQt6

.include <bsd.port.mk>
