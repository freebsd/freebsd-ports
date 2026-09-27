PORTNAME=	magnum
DISTVERSIONPREFIX=	v
DISTVERSION=	2020.06-3685
DISTVERSIONSUFFIX=	-gf239823e
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Magnum Graphics: Graphics middleware for games and data visualization
WWW=		https://magnum.graphics/ \
		https://github.com/mosra/magnum

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_15_armv7=	build broken: Unsupported relocation type 160 in non-PLT relocations, see https://github.com/mosra/magnum/issues/657

LIB_DEPENDS=	libCorradeUtility.so:devel/corrade

USES=		cmake:testing compiler:c++11-lang gl
USE_GL=		opengl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mosra
GH_TUPLE=	mosra:toolchains:fa282e8:toolchains/toolchains

CMAKE_ARGS=	-DLIB_SUFFIX=""
CMAKE_OFF=	MAGNUM_BUILD_TESTS
CMAKE_TESTING_ON=	MAGNUM_BUILD_TESTS

# GL tests are disabled because several fail due to NVIDIA driver quirks
# (compressed cubemap/texture-array subimage uploads). Run tests serially
# in case GL tests are re-enabled, since shared GPU contexts segfault in parallel.
CMAKE_TESTING_JOBS=	1

APP_MODULES_STATIC?=	yes
.if "${APP_MODULES_STATIC}" == yes
CMAKE_ARGS+=	-DFREEBSD_APP_MODULES_LINK_TYPE=STATIC # users can only use the libs when staticakky linked (due to missing symbols)
PLIST_SUB+=	APP_MODULES_EXT=.a
.else # SHARED
CMAKE_ARGS+=	-DFREEBSD_APP_MODULES_LINK_TYPE=SHARED # needed to check that options' dependencies are correct
PLIST_SUB+=	APP_MODULES_EXT=.so
.endif

CXXFLAGS+=	-fPIC

OPTIONS_DEFINE=		GLXCONTEXT
OPTIONS_GROUP=		APPS PLUGINS
OPTIONS_GROUP_APPS=	AUDIO GLFW GLX SDL2 VULKAN XEGL # other application types are available
OPTIONS_GROUP_PLUGINS=	ANYAUDIOIMPORTER ANYIMAGEIMPORTER MAGNUMFONT MAGNUMFONTCONVERTER
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	${OPTIONS_DEFINE} ${OPTIONS_GROUP_APPS} ${OPTIONS_GROUP_PLUGINS}

# separate options

GLXCONTEXT_DESC=	Build GlxContext library
GLXCONTEXT_CMAKE_BOOL=	MAGNUM_WITH_GLXCONTEXT

# applicaton type options

APPS_DESC=		Application support to build
.for a in ${OPTIONS_GROUP_APPS}
${a}_DESC=		${a} applications
.endfor

AUDIO_CMAKE_BOOL=	MAGNUM_WITH_AUDIO
AUDIO_USES=		openal

GLFW_CMAKE_BOOL=	MAGNUM_WITH_GLFWAPPLICATION
GLFW_LIB_DEPENDS=	libglfw.so:graphics/glfw

GLX_CMAKE_BOOL=		MAGNUM_WITH_GLXAPPLICATION
GLX_USE=		XORG=ice,sm,x11,xext

SDL2_CMAKE_BOOL=	MAGNUM_WITH_SDL2APPLICATION
SDL2_USES=		sdl
SDL2_USE=		SDL=sdl2

VULKAN_CMAKE_BOOL=	MAGNUM_WITH_VK
VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

XEGL_CMAKE_BOOL=	MAGNUM_WITH_XEGLAPPLICATION
XEGL_USES=		xorg
XEGL_USE=		XORG=ice,sm,x11,xext

# plugin options

PLUGINS_DESC=			Build plugins:

ANYAUDIOIMPORTER_DESC=		Any audio importer plugin
ANYAUDIOIMPORTER_CMAKE_BOOL=	MAGNUM_WITH_ANYAUDIOIMPORTER
ANYAUDIOIMPORTER_USES=		openal

ANYIMAGEIMPORTER_DESC=		Any image importer plugin
ANYIMAGEIMPORTER_CMAKE_BOOL=	MAGNUM_WITH_ANYIMAGEIMPORTER

MAGNUMFONT_DESC=		MagnumFont plugin
MAGNUMFONT_CMAKE_BOOL=		MAGNUM_WITH_MAGNUMFONT

MAGNUMFONTCONVERTER_DESC=	MagnumFontConverter plugin
MAGNUMFONTCONVERTER_CMAKE_BOOL=	MAGNUM_WITH_MAGNUMFONTCONVERTER

.include <bsd.port.options.mk>

.if !empty(PORT_OPTIONS:MXEGL) || !empty(PORT_OPTIONS:MGLX)
PLIST_FILES=	include/Magnum/Platform/AbstractXApplication.h
.endif

# tests as of 2020.06.3685: 100% tests passed, 0 tests failed out of 294

.include <bsd.port.mk>
