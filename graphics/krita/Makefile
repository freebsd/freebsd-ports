PORTNAME=	krita
DISTVERSION=	5.2.11
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sketching and painting program
WWW=		https://krita.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>=1.65:devel/boost-libs \
		immer>=0:devel/immer \
		lager>=0:devel/lager \
		zug>=0:devel/zug
BUILD_DEPENDS+=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_aarch64=	xsimd>=8.1:devel/xsimd
BUILD_DEPENDS_amd64=	xsimd>=8.1:devel/xsimd
LIB_DEPENDS=	libImath.so:math/Imath \
		libOpenColorIO.so:graphics/opencolorio \
		libX11.so:x11/libX11 \
		libexiv2.so:graphics/exiv2 \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgif.so:graphics/giflib \
		libgsl.so:math/gsl \
		libharfbuzz.so:print/harfbuzz \
		libheif.so:graphics/libheif \
		libjson-c.so:devel/json-c \
		libjxl.so:graphics/libjxl \
		liblcms2.so:graphics/lcms2 \
		libmypaint.so:graphics/libmypaint \
		libopenjp2.so:graphics/openjpeg \
		libpng16.so:graphics/png \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libquazip1-qt5.so:archivers/quazip@qt5 \
		libtiff.so:graphics/tiff \
		libturbojpeg.so:graphics/libjpeg-turbo \
		libunibreak.so:textproc/libunibreak \
		libwebp.so:graphics/webp

USES=		cmake compiler:c++11-lib desktop-file-utils eigen:3 gettext \
		gnome jpeg kde:5 localbase:ldflags mlt:7 pkgconfig python qt:5 \
		sdl shared-mime-info tar:xz xorg
USE_GNOME=	glib20
USE_KDE=	completion config coreaddons crash guiaddons i18n \
		itemmodels itemviews libkdcraw service widgetsaddons \
		windowsystem ecm:build
USE_QT=		concurrent core dbus gui network \
		printsupport sql svg widgets x11extras xml \
		buildtools:build qmake:build testlib:build \
		sql-sqlite3:run
USE_SDL=	sdl2
USE_XORG=	ice sm xcb xext xi

# Make Cmake use the python we installed dependencies for.
CMAKE_ARGS=	-DPython_EXECUTABLE:STRING=${PYTHON_CMD}

PLIST_SUB=	SHLIB_VER=19.0.0 \
		SHLIB_SHVER=19

OPTIONS_DEFINE=		PYTHON OPENEXR
OPTIONS_DEFAULT=	PYTHON OPENEXR
OPTIONS_SUB=		yes

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
			libKSeExpr.so:graphics/kseexpr
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR

PYTHON_BUILD_DEPENDS=	${PY_SETUPTOOLS}
PYTHON_USES=		pyqt:5
PYTHON_USE=		PYQT=pyqt5,pysip,sip:build
PYTHON_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_PyQt5

.include <bsd.port.mk>
