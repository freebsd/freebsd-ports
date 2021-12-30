# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	darktable
PORTVERSION=	3.8.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/darktable-org/${PORTNAME}/releases/download/release-${PORTVERSION:C/\.rc/rc/}/
PKGNAMESUFFIX=	38

MAINTAINER=	mandree@FreeBSD.org
# lwhsu and dumbbell hereby receive blanket approval to deal with this port
# as though they were maintainers. Courtesy Cc: by e-mail of important changes appreciated. --mandree
COMMENT=	Virtual lighttable and darkroom for photographers v3.8

LICENSE=	GPLv3

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	uses 64-bit address space

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		${P5_POD_PARSER} \
		po4a-translate:textproc/po4a \
		xsltproc:textproc/libxslt \
		bash:shells/bash
LIB_DEPENDS=	libcolord-gtk.so:graphics/colord-gtk \
		libcolord.so:graphics/colord \
		libcurl.so:ftp/curl \
		libexiv2.so:graphics/exiv2 \
		libharfbuzz.so:print/harfbuzz \
		libheif.so:graphics/libheif \
		libicui18n.so:devel/icu \
		libjasper.so:graphics/jasper \
		libjson-glib-1.0.so:devel/json-glib \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		libpng.so:graphics/png \
		libpugixml.so:textproc/pugixml \
		libsoup-2.4.so:devel/libsoup \
		libtiff.so:graphics/tiff

# Fix build against cmake-3.21: the ninja generator in 3.21 suffers a
# regression (see https://gitlab.kitware.com/cmake/cmake/-/issues/22487)
# appending an invalid "-Wl,--no-as-needed" to the linker arguments for static
# libraries.  Once this regression has been fixed upstream, this can be
# switched back to USES=cmake, and LTO can be re-enabled.
USES=		cmake compiler:c++14-lang desktop-file-utils gl gnome jpeg \
		perl5 pkgconfig sdl shebangfix sqlite tar:xz xorg
OPTIONS_EXCLUDE=LTO
USE_GL=		gl
USE_GNOME=	cairo gtk30 intltool librsvg2 libxml2
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_SDL=	sdl2
USE_XORG=	ice sm x11 xext xrandr

SHEBANG_FILES=	tools/*.sh

CMAKE_ARGS+=	-DBINARY_PACKAGE_BUILD=1 \
		-DBUILD_CMSTEST:BOOL=ON \
		-DUSE_KWALLET:BOOL=ON

CFLAGS+=	-fopenmp
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.rc/~rc/}

OPTIONS_DEFINE=		DOCS GEO GPHOTO GMIC GRAPHMAGICK LIBAVIF LIBSECRET LTO \
			LUA NLS OPENEXR OPENJPEG PRINT TOOLS WEBP
OPTIONS_DEFAULT=	GEO GPHOTO LUA OPENEXR OPENJPEG PRINT WEBP
OPTIONS_SUB=		yes

GEO_DESC=		Support geotagging
GMIC_DESC=		Support G'Mic-compressed LUT in lut3d
LIBAVIF_DESC=		Support encoding and decoding .avif files
LIBSECRET_DESC=		Support libsecret as password backend

GEO_LIB_DEPENDS=	libosmgpsmap-1.0.so:x11-toolkits/osm-gps-map
GEO_CMAKE_OFF=		-DUSE_MAP:BOOL=OFF

GMIC_LIB_DEPENDS=	libgmic.so:graphics/gmic
GMIC_CMAKE_OFF=		-DUSE_GMIC:BOOL=OFF

GPHOTO_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO_CMAKE_OFF=	-DUSE_CAMERA_SUPPORT:BOOL=OFF

GRAPHMAGICK_LIB_DEPENDS=libGraphicsMagick.so:graphics/GraphicsMagick
GRAPHMAGICK_CMAKE_OFF=	-DUSE_GRAPHICSMAGICK:BOOL=OFF

LIBAVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
LIBAVIF_CMAKE_OFF=	-DUSE_LIBAVIF:BOOL=OFF

LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CMAKE_OFF=	-DUSE_LIBSECRET:BOOL=OFF

LTO_CMAKE_BOOL=		RAWSPEED_ENABLE_LTO

LUA_USES=		lua:54
LUA_CMAKE_OFF=		-DUSE_LUA:BOOL=OFF

# FIXME: Even with NLS turned off, darktable(1) is still linked to
# libintl.so.
NLS_USES=		gettext
NLS_USES_OFF=		gettext-runtime
NLS_CMAKE_OFF=		-DUSE_NLS:BOOL=OFF
NLS_LDFLAGS=		-L${LOCALBASE}/lib -lintl

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
			libImath.so:math/Imath
OPENEXR_CFLAGS=		-I${LOCALBASE}/include/Imath
OPENEXR_CMAKE_OFF=	-DUSE_OPENEXR:BOOL=OFF

OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
OPENJPEG_CMAKE_OFF=	-DUSE_OPENJPEG:BOOL=OFF

PRINT_LIB_DEPENDS=	libcups.so:print/cups
PRINT_CMAKE_OFF=	-DBUILD_PRINT:BOOL=OFF

TOOLS_DESC=		Install additional scripts
TOOLS_BUILD_DEPENDS=	exiftool:graphics/p5-Image-ExifTool
TOOLS_RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CMAKE_OFF=		-DUSE_WEBP:BOOL=OFF

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == powerpc64le
CMAKE_ARGS+=	-DUSE_OPENCL:BOOL=OFF
CXXFLAGS+=	-DGDK_DISABLE_DEPRECATED
PLIST_SUB+=	NO_OPENCL="@comment "
.else
PLIST_SUB+=	NO_OPENCL=""
.endif

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang && ${OPSYS} == FreeBSD || ${ARCH} == "i386"
LLVM_DEFAULT=	13
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CC=		${LOCALBASE}/bin/clang${LLVM_DEFAULT}
CPP=		${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT}
CXX=		${LOCALBASE}/bin/clang++${LLVM_DEFAULT}
LD=		${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT}
BINARY_ALIAS+=	ld.lld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT}
BINARY_ALIAS+=	llvm-objcopy=${LOCALBASE}/bin/llvm-objcopy${LLVM_DEFAULT}
.endif

# work around CMAKE/CCACHE flaw (cmake stomps over ccache)
.if "${WITH_CCACHE_BUILD}" == "yes" && !defined(NO_CCACHE)
CMAKE_ARGS+=	-DCMAKE_C_COMPILER_LAUNCHER=${CCACHE_BIN} \
		-DCMAKE_CXX_COMPILER_LAUNCHER=${CCACHE_BIN}
.endif

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	RelWithDebInfo
STRIP=
.endif

# darktable defines the __XOPEN_SOURCE preprocessor macro, which
# restricts symbol visibility on FreeBSD and causes compilation failures
# on, for instance, the cups_print module, because u_char remains
# undefined. Remove _XOPEN_SOURCE maro definitions.
post-patch:
	${REINPLACE_CMD} '/add_definitions."-D_XOPEN_SOURCE=.*"/d' ${WRKSRC}/CMakeLists.txt

post-install-TOOLS-off:
	@${RM} -f ${STAGEDIR}${DATADIR}/tools/extract_wb_from_images.sh

.include <bsd.port.post.mk>
