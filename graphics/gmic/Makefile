# $FreeBSD$

PORTNAME=	gmic
DISTVERSION=	2.4.3
CATEGORIES=	graphics
MASTER_SITES=	https://gmic.eu/files/source/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for image processing

LICENSE=	CeCILL
LICENSE_NAME=	CeCILL
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_i386=	error: "c++ crashes, clang-5 and 6 fail: undefined reference to `__atomic_load'"

BUILD_DEPENDS=	${LOCALBASE}/include/CImg.h:graphics/cimg
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libGraphicsMagick++.so:graphics/GraphicsMagick \
		libIlmImf.so:graphics/openexr \
		libImath.so:graphics/ilmbase \
		libopencv_core.so:graphics/opencv-core \
		libopencv_video.so:graphics/opencv \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

PORTSCOUT=	limit:[0-9]\..* # not v.220 and similar

USES=		cmake:outsource compiler:c++11-lang jpeg pkgconfig
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_LIB_STATIC
CMAKE_ON=	ENABLE_DYNAMIC_LINKING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		OPENMP PLUGINS X11
OPTIONS_DEFAULT=	OPENMP X11
OPTIONS_SUB=		yes

OPENMP_CMAKE_BOOL=	ENABLE_OPENMP
OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp

PLUGINS_CMAKE_BOOL=	BUILD_PLUGIN
PLUGINS_USE=		GNOME=atk,cairo,gdkpixbuf2,glib20,gtk20,pango
PLUGINS_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libgimp-2.0.so:graphics/gimp-app

X11_CMAKE_BOOL=		ENABLE_X
X11_USE=		XORG=ice,sm,x11,xext

.include <bsd.port.mk>
