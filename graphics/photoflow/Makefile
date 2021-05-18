PORTNAME=	photoflow
DISTVERSION=	0.2.8.20200828
PORTREVISION=	6
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Non-destructive photo retouching program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	see https://github.com/aferrero2707/PhotoFlow/issues/192

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libiptcdata.so:graphics/libiptcdata \
		libOpenEXR.so:graphics/openexr \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		libtiff.so:graphics/tiff \
		libpugixml.so:textproc/pugixml \
		libvips.so:graphics/vips

USES=		cmake compiler desktop-file-utils gettext gnome jpeg pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	aferrero2707
GH_PROJECT=	PhotoFlow
GH_TAGNAME=	8472024f
USE_GNOME=	atkmm cairomm glib20 glibmm gtk20 gtkmm24 libsigc++20 pangomm

CMAKE_OFF=	BUNDLED_LENSFUN
#Disable optimization for the builder CPU when building official packages
.if defined(PACKAGE_BUILDING)
CMAKE_ON=	BINARY_PACKAGE_BUILD
.endif

LDFLAGS+=	-lexecinfo

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		OCIO
OPTIONS_DEFAULT=	OCIO
OPTIONS_SUB=		yes

OCIO_DESC=		Enable the integration of OpenColorIO
OCIO_CMAKE_BOOL=	OCIO_ENABLED
OCIO_LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio
OCIO_VARS=		GH_TUPLE+=sobotka:filmic-blender:1.1.1:fb/../.build/data/filmic-blender \
			GH_TUPLE+=imageworks:OpenColorIO-Configs:0bb079c08be410030669cbf5f19ff869b88af953:c/../.build/data/ocio-configs

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.else
# clang-10 fails to compile photoflow because it bundles an old version of GMIC that clang-10 doesn't like: https://github.com/aferrero2707/PhotoFlow/issues/220
LLVM_VERSION=	90
BUILD_DEPENDS+=	clang${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}
CPP=		clang-cpp${LLVM_VERSION}
.endif

.include <bsd.port.post.mk>
