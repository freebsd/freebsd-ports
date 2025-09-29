PORTNAME=	vulkan-validation-layers
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.327
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Validation layers for the Vulkan graphics API
WWW=		https://github.com/KhronosGroup/Vulkan-ValidationLayers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	robin-hood-hashing>0:devel/robin-hood-hashing \
		spirv-tools>0:graphics/spirv-tools \
		vulkan-headers>0:graphics/vulkan-headers \
		vulkan-utility-libraries>0:graphics/vulkan-utility-libraries

USES=		alias cmake compiler:c++11-lib pkgconfig python:build
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-ValidationLayers
# for GH_TAGNAME in GH_TUPLE
# git clone --quiet https://github.com/KhronosGroup/SPIRV-Headers.git && git -C SPIRV-Headers describe <COMMIT_HASH>
# for COMMIT_HASH see ${WRKSRC}/scripts/known_good.json
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-444-g402d0b3:headers/SPIRV-Headers
CMAKE_OFF=	BUILD_TESTS

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
