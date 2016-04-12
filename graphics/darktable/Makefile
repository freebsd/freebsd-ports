# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darktable
PORTVERSION=	2.0.3
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/darktable-org/${PORTNAME}/releases/download/release-${PORTVERSION:C/\.rc/rc/}/

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	Virtual lighttable and darkroom for photographers

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:textproc/libxslt
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexiv2.so:graphics/exiv2 \
		libjson-glib-1.0.so:devel/json-glib \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		libpugixml.so:textproc/pugixml \
		libtiff.so:graphics/tiff

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	uses SSE instructions and 64-bit address space

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils	\
		jpeg ninja pkgconfig sqlite tar:xz
USE_GNOME=	gtk30 intltool librsvg2 libxml2
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	COLORD DOCS FLICKR GEO GNOMEKEYRING GPHOTO GRAPHMAGICK	\
		LIBSECRET LUA NLS OPENEXR OPENJPEG PRINT RAWSPEED	\
		SLIDESHOW SQUISH WEBP

GEO_DESC=	Support geotagging
LIBSECRET_DESC=	Support libsecret as password backend
SQUISH_DESC=	Compress thumbnail via libsquish
RAWSPEED_DESC=	Compile with rawspeed backend
SLIDESHOW_DESC=	Build OpenGL/SDL slideshow viewer

OPTIONS_DEFAULT=COLORD FLICKR GEO GPHOTO LUA NLS OPENEXR OPENJPEG	\
		PRINT RAWSPEED SLIDESHOW SQUISH WEBP
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.rc/~rc/}

CMAKE_ARGS+=	-DBINARY_PACKAGE_BUILD=1
CMAKE_ARGS+=	-DBUILD_CMSTEST:BOOL=ON
CMAKE_ARGS+=	-DUSE_KWALLET:BOOL=ON

# darktable 1.4+ can use colord but provides its own libcolord,
# statically linked to libdarktable.so.
COLORD_LIB_DEPENDS=	libcolord-gtk.so:graphics/colord-gtk
COLORD_CMAKE_OFF=	-DUSE_COLORD:BOOL=OFF

FLICKR_LIB_DEPENDS=	libflickcurl.so:www/flickcurl
FLICKR_CMAKE_OFF=	-DUSE_FLICKR:BOOL=OFF

GEO_LIB_DEPENDS=	libosmgpsmap-1.0.so:x11-toolkits/osm-gps-map \
			libsoup-2.4.so:devel/libsoup
GEO_CMAKE_OFF=		-DUSE_GEO:BOOL=OFF

GNOMEKEYRING_LIB_DEPENDS=libgnome-keyring.so:security/libgnome-keyring
GNOMEKEYRING_CMAKE_OFF=	-DUSE_GNOME_KEYRING:BOOL=OFF

GPHOTO_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO_CMAKE_OFF=	-DUSE_CAMERA_SUPPORT:BOOL=OFF

GRAPHMAGICK_LIB_DEPENDS=libGraphicsMagick.so:graphics/GraphicsMagick
GRAPHMAGICK_CMAKE_OFF=	-DUSE_GRAPHICSMAGICK:BOOL=OFF

LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CMAKE_OFF=	-DUSE_LIBSECRET:BOOL=OFF

LUA_USES=		lua:52
LUA_CMAKE_OFF=		-DUSE_LUA:BOOL=OFF

NLS_USES=		gettext
NLS_CMAKE_OFF=		-DUSE_NLS:BOOL=OFF

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR
OPENEXR_CMAKE_OFF=	-DUSE_OPENEXR:BOOL=OFF

OPENJPEG_LIB_DEPENDS=	libopenjpeg.so:graphics/openjpeg15
OPENJPEG_CMAKE_OFF=	-DUSE_OPENJPEG:BOOL=OFF

PRINT_LIB_DEPENDS=	libcups.so:print/cups
PRINT_CMAKE_OFF=	-DBUILD_PRINT:BOOL=OFF

RAWSPEED_CMAKE_OFF=	-DDONT_USE_RAWSPEED:BOOL=ON

SLIDESHOW_USE=		GL=gl SDL=sdl
SLIDESHOW_CMAKE_OFF=	-DBUILD_SLIDESHOW:BOOL=OFF

SQUISH_BUILD_DEPENDS=	${LOCALBASE}/lib/libsquish.a:graphics/squish
SQUISH_CMAKE_OFF=	-DUSE_SQUISH:BOOL=OFF

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CMAKE_OFF=		-DUSE_WEBP:BOOL=OFF

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 && ${COMPILER_TYPE} == clang
# Enable OpenMP support with Clang 3.7.
BUILD_DEPENDS+=	clang37:devel/llvm37
RUN_DEPENDS+=	clang37:devel/llvm37

CPP=		clang-cpp37
CC=		clang37
CXX=		clang++37

# FIXME: At least in 3.7.0 and 3.7.1, Clang doesn't find libomp.so
# itself. Furthermore, there may be a regression in 3.7.1 because we now
# need to explicitely link to libm.so as well.
OPENMP_FLAGS=	-L${LOCALBASE}/llvm37/lib -lm -lomp
LDFLAGS+=	${OPENMP_FLAGS}

# Last but not least, there is a second change or regression in CMake
# 3.4.x: CMAKE_EXE_LINKER_FLAGS is not passed to TRY_COMPILE by default
# anymore. The CMP0056 policy must be explicitely set to NEW to ensure
# linker flags are passed.
# See: https://cmake.org/cmake/help/v3.4/policy/CMP0056.html
CMAKE_ARGS+=	-DCMAKE_POLICY_DEFAULT_CMP0056:STRING=NEW
.endif

# On FreeBSD 9.3-RELEASE, powl(3) is hidden behind the following
# define. So let's define it to fix the build. This is only needed on
# 9.3-RELEASE, but it's harmless on later branches because this define
# is not used.
CFLAGS+=	-D_DECLARE_C99_LDBL_MATH

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	RelWithDebInfo
STRIP=
.endif

post-patch:
	@${MV} ${WRKSRC}/data/darktableconfig.dtd ${WRKSRC}/data/darktableconfig.dtd.in

.include <bsd.port.post.mk>
