PORTNAME=	magnum
DISTVERSIONPREFIX=	v
DISTVERSION=	v2020.06-2037
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gb6a31a0af
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++11 graphics middleware for games and data visualization
WWW=		https://magnum.graphics/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libCorradeUtility.so:devel/corrade

USES=		cmake:testing compiler:c++11-lang gl
USE_GL=		opengl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mosra
GH_TUPLE=	mosra:toolchains:65568a9:toolchains/toolchains

CMAKE_ARGS=	-DLIB_SUFFIX=""

APP_MODULES_STATIC?=	yes
.if "${APP_MODULES_STATIC}" == yes
CMAKE_ARGS+=	-DFREEBSD_APP_MODULES_LINK_TYPE=STATIC # users can only use the libs when staticakky linked (due to missing symbols)
PLIST_SUB+=	APP_MODULES_EXT=.a
.else # SHARED
CMAKE_ARGS+=	-DFREEBSD_APP_MODULES_LINK_TYPE=SHARED # needed to check that options' dependencies are correct
PLIST_SUB+=	APP_MODULES_EXT=.so
.endif

CXXFLAGS+=	-fPIC

OPTIONS_GROUP=		APPS PLUGINS
OPTIONS_GROUP_APPS=	GLFW GLX SDL2 XEGL # other application types are available
OPTIONS_GROUP_PLUGINS=	ANYAUDIOIMPORTER ANYIMAGEIMPORTER
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	${OPTIONS_GROUP_APPS} ${OPTIONS_GROUP_PLUGINS}

# applicaton type options

APPS_DESC=		Application support to build
.for a in ${OPTIONS_GROUP_APPS}
${a}_DESC=		${a} applications
.endfor

GLFW_CMAKE_BOOL=	MAGNUM_WITH_GLFWAPPLICATION
GLFW_LIB_DEPENDS=	libglfw.so:graphics/glfw

GLX_CMAKE_BOOL=		MAGNUM_WITH_GLXAPPLICATION
XEGL_USES=		xorg
GLX_USE=		XORG=ice,sm,x11,xext

SDL2_CMAKE_BOOL=	MAGNUM_WITH_SDL2APPLICATION
SDL2_USES=		sdl
SDL2_USE=		SDL=sdl2

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

.include <bsd.port.mk>
