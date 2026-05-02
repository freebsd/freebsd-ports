PORTNAME=	vulkan-validation-layers
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.349
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Validation layers for the Vulkan graphics API
WWW=		https://github.com/KhronosGroup/Vulkan-ValidationLayers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	robin-hood-hashing>0:devel/robin-hood-hashing \
		spirv-tools>0:graphics/spirv-tools \
		vulkan-headers>0:graphics/vulkan-headers \
		vulkan-utility-libraries>0:graphics/vulkan-utility-libraries

USES=		cmake compiler:c++11-lib localbase pkgconfig python:build
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-ValidationLayers
GH_TUPLE=	KhronosGroup:SPIRV-Headers:39e5d40a325973b9204d1b660eb3e026cd75fc3f:headers/SPIRV-Headers
CMAKE_OFF=	BUILD_TESTS UPDATE_DEPS

PLIST_FILES=	lib/libVkLayer_khronos_validation.so \
		share/vulkan/explicit_layer.d/VkLayer_khronos_validation.json

OPTIONS_DEFINE=		WAYLAND XCB XLIB
OPTIONS_DEFAULT=	WAYLAND XCB XLIB

XCB_DESC=		${X11_DESC} via libxcb
XLIB_DESC=		${X11_DESC} via libX11

WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland
WAYLAND_CMAKE_BOOL=	BUILD_WSI_WAYLAND_SUPPORT

XCB_USES=		xorg
XCB_USE=		XORG=xcb
XCB_CMAKE_BOOL=		BUILD_WSI_XCB_SUPPORT

XLIB_USES=		xorg
XLIB_USE=		XORG=x11,xrandr
XLIB_CMAKE_BOOL=	BUILD_WSI_XLIB_SUPPORT

.include <bsd.port.mk>
