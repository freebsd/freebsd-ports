# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darktable
PORTVERSION=	2.2.5
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/darktable-org/${PORTNAME}/releases/download/release-${PORTVERSION:C/\.rc/rc/}/

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	Virtual lighttable and darkroom for photographers

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:textproc/libxslt \
		po4a-translate:textproc/po4a
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexiv2.so:graphics/exiv2 \
		libjson-glib-1.0.so:devel/json-glib \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		libpng16.so:graphics/png \
		libpugixml.so:textproc/pugixml \
		libsoup-2.4.so:devel/libsoup \
		libtiff.so:graphics/tiff

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	uses SSE instructions and 64-bit address space

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils	\
		jpeg pkgconfig sqlite tar:xz
USE_GL=		glu
USE_GNOME=	cairo gtk30 intltool librsvg2 libxml2
USE_XORG=	ice sm x11 xext xrandr
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	COLORD DOCS FLICKR GEO GPHOTO GRAPHMAGICK	\
		LIBSECRET LUA NLS OPENEXR OPENJPEG PRINT WEBP

GEO_DESC=	Support geotagging
LIBSECRET_DESC=	Support libsecret as password backend

OPTIONS_DEFAULT=COLORD FLICKR GEO GPHOTO LUA OPENEXR OPENJPEG	\
		PRINT WEBP
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.rc/~rc/}

CMAKE_ARGS+=	-DBINARY_PACKAGE_BUILD=1
CMAKE_ARGS+=	-DBUILD_CMSTEST:BOOL=ON
CMAKE_ARGS+=	-DUSE_KWALLET:BOOL=ON
LDFLAGS+=	-L${LOCALBASE}/lib

COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord \
			libcolord-gtk.so:graphics/colord-gtk
COLORD_CMAKE_OFF=	-DUSE_COLORD:BOOL=OFF

FLICKR_LIB_DEPENDS=	libflickcurl.so:www/flickcurl
FLICKR_CMAKE_OFF=	-DUSE_FLICKR:BOOL=OFF

GEO_LIB_DEPENDS=	libosmgpsmap-1.0.so:x11-toolkits/osm-gps-map
GEO_CMAKE_OFF=		-DUSE_MAP:BOOL=OFF

GPHOTO_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO_CMAKE_OFF=	-DUSE_CAMERA_SUPPORT:BOOL=OFF

GRAPHMAGICK_LIB_DEPENDS=libGraphicsMagick.so:graphics/GraphicsMagick
GRAPHMAGICK_CMAKE_OFF=	-DUSE_GRAPHICSMAGICK:BOOL=OFF

LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CMAKE_OFF=	-DUSE_LIBSECRET:BOOL=OFF

LUA_USES=		lua:52
LUA_CMAKE_OFF=		-DUSE_LUA:BOOL=OFF

# FIXME: Even with NLS turned off, darktable(1) is still linked to
# libintl.so.
NLS_USES=		gettext
NLS_USES_OFF=		gettext-runtime
NLS_CMAKE_OFF=		-DUSE_NLS:BOOL=OFF
NLS_LDFLAGS=		-L${LOCALBASE}/lib -lintl

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR \
			libIlmThread-2_2.so:graphics/ilmbase
OPENEXR_CMAKE_OFF=	-DUSE_OPENEXR:BOOL=OFF

OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
OPENJPEG_CMAKE_OFF=	-DUSE_OPENJPEG:BOOL=OFF

PRINT_LIB_DEPENDS=	libcups.so:print/cups
PRINT_CMAKE_OFF=	-DBUILD_PRINT:BOOL=OFF

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CMAKE_OFF=		-DUSE_WEBP:BOOL=OFF

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 && ${CHOSEN_COMPILER_TYPE} == clang
# Enable OpenMP support with Clang 4.0.
LLVM_VER=	40
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}

CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}

# FIXME: At least in 3.7.0 and 3.7.1, Clang doesn't find libomp.so
# itself. Furthermore, there may be a regression in 3.7.1 because we now
# need to explicitly link to libm.so as well. This remains true with
# Clang 3.9.1.
OPENMP_FLAGS=	-L${LOCALBASE}/llvm${LLVM_VER}/lib -lm -lomp
LDFLAGS+=	${OPENMP_FLAGS}

# Depend on devel/openmp instead of the full LLVM at runtime. Required
# for a consistent libomp experience.
LIB_DEPENDS+=	libomp.so.0:devel/openmp

# Last but not least, there is a second change or regression in CMake
# 3.4.x: CMAKE_EXE_LINKER_FLAGS is not passed to TRY_COMPILE by default
# anymore. The CMP0056 policy must be explicitly set to NEW to ensure
# linker flags are passed.
# See: https://cmake.org/cmake/help/v3.4/policy/CMP0056.html
CMAKE_ARGS+=	-DCMAKE_POLICY_DEFAULT_CMP0056:STRING=NEW
.endif

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	RelWithDebInfo
STRIP=
.endif

.include <bsd.port.post.mk>
