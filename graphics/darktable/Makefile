PORTNAME=	darktable
PORTVERSION=	5.2.1
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/darktable-org/${PORTNAME}/releases/download/release-${PORTVERSION:C/\.rc/rc/}/

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	Virtual lighttable and darkroom for photographers
WWW=		https://www.darktable.org/

LICENSE=	GPLv3

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	uses 64-bit address space

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		p5-Pod-Parser>=0:textproc/p5-Pod-Parser \
		po4a-translate:textproc/po4a \
		xsltproc:textproc/libxslt \
		bash:shells/bash
LIB_DEPENDS=	libavif.so:graphics/libavif \
		libcolord-gtk.so:graphics/colord-gtk \
		libcolord.so:graphics/colord \
		libcurl.so:ftp/curl \
		libexiv2.so:graphics/exiv2 \
		libgphoto2.so:graphics/libgphoto2 \
		libharfbuzz.so:print/harfbuzz \
		libheif.so:graphics/libheif \
		libicui18n.so:devel/icu \
		libImath.so:math/Imath \
		libjasper.so:graphics/jasper \
		libjson-glib-1.0.so:devel/json-glib \
		libjxl_threads.so:graphics/libjxl \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		libOpenEXR.so:graphics/openexr \
		libopenjp2.so:graphics/openjpeg \
		libosmgpsmap-1.0.so:x11-toolkits/osm-gps-map \
		libpng.so:graphics/png \
		libpugixml.so:textproc/pugixml \
		libsoup-2.4.so:devel/libsoup \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USES=		cmake compiler:c++11-lib desktop-file-utils gl gnome jpeg \
		llvm:build lua perl5 pkgconfig sdl shebangfix sqlite \
		tar:xz xorg
USE_GL=		gl
USE_GNOME=	cairo gtk30 intltool librsvg2 libxml2
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_SDL=	sdl2
USE_XORG=	ice sm x11 xext xrandr

SHEBANG_FILES=	tools/*.sh

CMAKE_ARGS+=	-DBINARY_PACKAGE_BUILD=1 -DUSE_PORTMIDI:BOOL=OFF

CMAKE_BOOL+=	BUILD_CMSTEST USE_AVIF USE_CAMERA_SUPPORT USE_HEIF \
		USE_ISOBMFF USE_KWALLET USE_LUA USE_MAP USE_OPENEXR \
		USE_OPENJPEG USE_WEBP RAWSPEED_ENABLE_LTO

# darktable wraps pthread lock/release functions, causing false
# compiler warnings from -Wthread-safety-analysis. Kill this warning.
CFLAGS+=	-fopenmp -Wno-thread-safety-analysis

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.rc/~rc/}

OPTIONS_DEFINE=		DOCS GMIC GRAPHMAGICK LIBSECRET NLS PRINT TOOLS
OPTIONS_DEFAULT=	PRINT
OPTIONS_SUB=		yes

GMIC_DESC=		Support G'Mic-compressed LUT in lut3d
LIBSECRET_DESC=		Support libsecret as password backend
TOOLS_DESC=		Install additional scripts

GMIC_LIB_DEPENDS=	libgmic.so:graphics/gmic
GMIC_CMAKE_BOOL=	USE_GMIC

GRAPHMAGICK_LIB_DEPENDS=libGraphicsMagick.so:graphics/GraphicsMagick
GRAPHMAGICK_CMAKE_BOOL=	USE_GRAPHICSMAGICK

LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CMAKE_BOOL=	USE_LIBSECRET

# FIXME: Even with NLS turned off, darktable(1) is still linked to
# libintl.so.
NLS_USES=		gettext
NLS_USES_OFF=		gettext-runtime
NLS_CMAKE_BOOL=		USE_NLS
NLS_LDFLAGS=		-L${LOCALBASE}/lib -lintl

PRINT_LIB_DEPENDS=	libcups.so:print/cups
PRINT_CMAKE_BOOL=	BUILD_PRINT

TOOLS_BUILD_DEPENDS=	exiftool:graphics/p5-Image-ExifTool
TOOLS_RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == powerpc64le
CMAKE_ARGS+=	-DUSE_OPENCL:BOOL=OFF
CXXFLAGS+=	-DGDK_DISABLE_DEPRECATED
PLIST_SUB+=	NO_OPENCL="@comment "
.else
PLIST_SUB+=	NO_OPENCL=""
.endif

.include <bsd.port.pre.mk>

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
