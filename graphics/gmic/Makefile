# $FreeBSD$

PORTNAME=	gmic
DISTVERSIONPREFIX=	v.
DISTVERSION=	2.3.2
CATEGORIES=	graphics
MASTER_SITES=	http://gmic.eu/:gmic_stdlib
DISTFILES=	gmic_stdlib.h:gmic_stdlib
DIST_SUBDIR=	${PORTNAME}-${DISTVERSIONFULL}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

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
		libIlmImf.so:graphics/OpenEXR \
		libImath-2_2.so:graphics/ilmbase \
		libomp.so:devel/openmp \
		libopencv_core.so:graphics/opencv-core \
		libopencv_video.so:graphics/opencv \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

PORTSCOUT=	limit:[0-9]\..* # not v.220 and similar

USES=		cmake:outsource compiler:c++11-lang jpeg pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dtschump
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_LIB_STATIC
CMAKE_ON=	ENABLE_DYNAMIC_LINKING

OPTIONS_DEFINE=		PLUGINS X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=		yes

PLUGINS_CMAKE_BOOL=	BUILD_PLUGIN
PLUGINS_USE=		GNOME=atk,cairo,gdkpixbuf2,glib20,gtk20,pango
PLUGINS_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libgimp-2.0.so:graphics/gimp-app

X11_CMAKE_BOOL=		ENABLE_X
X11_USE=		XORG=ice,sm,x11,xext

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/gmic_stdlib.h ${WRKSRC}/src/

.include <bsd.port.mk>
