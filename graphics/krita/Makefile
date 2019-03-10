# $FreeBSD$

PORTNAME=	krita
DISTVERSION=	4.1.8
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sketching and painting program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImath.so:graphics/ilmbase \
		libOpenColorIO.so:graphics/opencolorio \
		libX11.so:x11/libX11 \
		libboost_system.so:devel/boost-libs \
		libfftw3.so:math/fftw3 \
		libexiv2.so:graphics/exiv2 \
		libcurl.so:ftp/curl \
		libgif.so:graphics/giflib \
		libgsl.so:math/gsl \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libraw.so:graphics/libraw \
		libtiff.so:graphics/tiff \
		libxcb.so:x11/libxcb \
		libxcb-util.so:x11/xcb-util

# Disable ninja generator for now (with gmake), until the duplicate test targets are resolved upstream.
USES=		cmake:noninja gmake compiler:c++11-lib desktop-file-utils \
		eigen:3 gettext jpeg kde:5 pkgconfig python:3.4+ qt:5 \
		shared-mime-info
USE_KDE=	archive completion config coreaddons crash guiaddons i18n \
		itemmodels itemviews kio service widgetsaddons windowsystem
USE_QT=		concurrent core dbus declarative gui multimedia network printsupport \
		svg testlib widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	ice sm xcb xext xi

OPTIONS_DEFINE=		GMIC OPENEXR
OPTIONS_DEFAULT=	OPENEXR
OPTIONS_SUB=		yes

GMIC_DESC=		Depend on the G'Mic plugin #'
GMIC_RUN_DEPENDS=	gmic_krita_qt:graphics/gmic-qt

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR

CONFLICTS_INSTALL=	calligra-2*

PLIST_SUB=	SHLIB_VER=18.0.0 \
		SHLIB_SHVER=18

.include <bsd.port.mk>
