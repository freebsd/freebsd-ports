PORTNAME=	vulkan-validation-layers
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.273
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Validation layers for the Vulkan graphics API
WWW=		https://github.com/KhronosGroup/Vulkan-ValidationLayers

LICENSE=	APACHE20

BUILD_DEPENDS=	robin-hood-hashing>0:devel/robin-hood-hashing \
		spirv-tools>0:graphics/spirv-tools \
		vulkan-headers>0:graphics/vulkan-headers

USES=		alias cmake compiler:c++11-lib pkgconfig python:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-ValidationLayers
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-332-g1c6bb27:headers/SPIRV-Headers \
		KhronosGroup:Vulkan-Utility-Libraries:${DISTVERSIONPREFIX}${DISTVERSION}:utils/Vulkan-Utility-Libraries
CMAKE_OFF=	BUILD_TESTS

OPTIONS_DEFINE=	WAYLAND XCB XLIB
OPTIONS_DEFAULT=WAYLAND XCB XLIB

WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland
WAYLAND_CMAKE_BOOL=	BUILD_WSI_WAYLAND_SUPPORT

XCB_DESC=		${X11_DESC} via libxcb
XCB_USES=		xorg
XCB_USE=		XORG=xcb
XCB_CMAKE_BOOL=		BUILD_WSI_XCB_SUPPORT

XLIB_DESC=		${X11_DESC} via libX11
XLIB_USES=		xorg
XLIB_USE=		XORG=x11,xrandr
XLIB_CMAKE_BOOL=	BUILD_WSI_XLIB_SUPPORT

.include <bsd.port.mk>
