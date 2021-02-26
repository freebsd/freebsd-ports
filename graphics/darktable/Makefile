# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darktable
PORTVERSION=	3.4.1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/darktable-org/${PORTNAME}/releases/download/release-${PORTVERSION:C/\.rc/rc/}/

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	Virtual lighttable and darkroom for photographers

LICENSE=	GPLv3

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	uses 64-bit address space

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		p5-Pod-Parser>=0:textproc/p5-Pod-Parser \
		po4a-translate:textproc/po4a \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libcolord-gtk.so:graphics/colord-gtk \
		libcolord.so:graphics/colord \
		libcurl.so:ftp/curl \
		libexiv2.so:graphics/exiv2 \
		libjson-glib-1.0.so:devel/json-glib \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		libpng.so:graphics/png \
		libpugixml.so:textproc/pugixml \
		libsoup-2.4.so:devel/libsoup \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++14-lang desktop-file-utils gl gnome jpeg \
		pkgconfig shebangfix sqlite tar:xz xorg
USE_GL=		glu
USE_GNOME=	cairo gtk30 intltool librsvg2 libxml2
INSTALLS_ICONS=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_XORG=	ice sm x11 xext xrandr

SHEBANG_FILES=	tools/*.sh

CMAKE_ARGS+=	-DBINARY_PACKAGE_BUILD=1 \
		-DBUILD_CMSTEST:BOOL=ON \
		-DUSE_KWALLET:BOOL=ON

CFLAGS+=	-fopenmp
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.rc/~rc/}

OPTIONS_DEFINE=		DOCS GEO GPHOTO GRAPHMAGICK LIBAVIF LIBSECRET LUA \
			NLS OPENEXR OPENJPEG PRINT TOOLS WEBP
OPTIONS_DEFAULT=	GEO GPHOTO LUA OPENEXR OPENJPEG PRINT WEBP
OPTIONS_SUB=		yes

GEO_DESC=		Support geotagging
LIBAVIF_DESC=		Support encoding and decoding .avif files
LIBSECRET_DESC=		Support libsecret as password backend

GEO_LIB_DEPENDS=	libosmgpsmap-1.0.so:x11-toolkits/osm-gps-map
GEO_CMAKE_OFF=		-DUSE_MAP:BOOL=OFF

GPHOTO_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO_CMAKE_OFF=	-DUSE_CAMERA_SUPPORT:BOOL=OFF

GRAPHMAGICK_LIB_DEPENDS=libGraphicsMagick.so:graphics/GraphicsMagick
GRAPHMAGICK_CMAKE_OFF=	-DUSE_GRAPHICSMAGICK:BOOL=OFF

LIBAVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
LIBAVIF_CMAKE_OFF=	-DUSE_LIBAVIF:BOOL=OFF

LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CMAKE_OFF=	-DUSE_LIBSECRET:BOOL=OFF

LUA_USES=		lua:53
LUA_CMAKE_OFF=		-DUSE_LUA:BOOL=OFF

# FIXME: Even with NLS turned off, darktable(1) is still linked to
# libintl.so.
NLS_USES=		gettext
NLS_USES_OFF=		gettext-runtime
NLS_CMAKE_OFF=		-DUSE_NLS:BOOL=OFF
NLS_LDFLAGS=		-L${LOCALBASE}/lib -lintl

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr \
			libIlmThread.so:graphics/ilmbase
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

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang && ${OPSYS} == FreeBSD || ${ARCH} == "i386"
LLVM_DEFAULT=	10
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CC=		${LOCALBASE}/bin/clang${LLVM_DEFAULT}
CPP=		${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT}
CXX=		${LOCALBASE}/bin/clang++${LLVM_DEFAULT}
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
