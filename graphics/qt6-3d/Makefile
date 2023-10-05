PORTNAME=	3d
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ and QML APIs for easy inclusion of 3D graphics
WWW=		https://qt-project.org

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libassimp.so:multimedia/assimp \
		libdouble-conversion.so:devel/double-conversion \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2 \
		libharfbuzz.so:print/harfbuzz \
		libicudata.so:devel/icu \
		libminizip.so:archivers/minizip \
		libpcre.so:devel/pcre \
		libpcre2-16.so:devel/pcre2 \
		libpng16.so:graphics/png \
		libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang gettext-runtime gl gnome python:build \
		pkgconfig qt-dist:6
USE_GL=		gl
USE_GNOME=	glib20
USE_QT=		base declarative shadertools
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSIMD}
.  if !empty(MACHINE_CPU:Mavx2)
CMAKE_ARGS+=	-DINPUT_qt3d_simd=avx2
PLIST_SUB+=	AVX2="" SIMD=""
.  elif !empty(MACHINE_CPU:Msse2)
CMAKE_ARGS+=	-DINPUT_qt3d_simd=sse2
PLIST_SUB+=	AVX2="@comment " SIMD=""
.  else
CMAKE_ARGS+=	-DINPUT_qt3d_simd=no
PLIST_SUB+=	SIMD="@comment "
.  endif
.else
CMAKE_ARGS+=	-DINPUT_qt3d_simd=no
PLIST_SUB+=	SIMD="@comment "
.endif

.include <bsd.port.mk>
