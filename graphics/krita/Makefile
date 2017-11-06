# $FreeBSD$

PORTNAME=	krita
PORTVERSION=	3.1.2.1
PORTREVISION=	5
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/3.1.2
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sketching and painting program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:math/eigen3
LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR \
		libImath.so:graphics/ilmbase \
		libOpenColorIO.so:graphics/opencolorio \
		libX11.so:x11/libX11 \
		libboost_system.so:devel/boost-libs \
		libfftw3.so:math/fftw3 \
		libexiv2.so:graphics/exiv2 \
		libcurl.so:ftp/curl \
		libgsl.so:math/gsl \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libraw.so:graphics/libraw \
		libtiff.so:graphics/tiff \
		libxcb.so:x11/libxcb \
		libxcb-util.so:x11/xcb-util

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils \
		gettext jpeg kde:5
USE_KDE=	archive completion config coreaddons crash guiaddons i18n \
		itemmodels itemviews kio service widgetsaddons windowsystem
USE_QT5=	buildtools_build concurrent core dbus gui network printsupport \
		qmake_build quick svg testlib widgets x11extras xml
USE_XORG=	ice sm xcb xext xi

OPTIONS_DEFINE=		GMIC
OPTIONS_SUB=		yes

GMIC_DESC=		Build the G'Mic plugin
GMIC_CMAKE_BOOL=	WITH_GMIC

CONFLICTS_INSTALL=	calligra-2*

PLIST_SUB+=	SHLIB_VER=16.0.0 \
		SHLIB_SHVER=16

.include <bsd.port.mk>
