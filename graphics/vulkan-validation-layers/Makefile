# $FreeBSD$

PORTNAME=	vulkan-validation-layers
DISTVERSIONPREFIX=	sdk-
DISTVERSION=	1.2.170.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Validation layers for the Vulkan graphics API

LICENSE=	APACHE20

BUILD_DEPENDS=	glslang>0:graphics/glslang \
		spirv-tools>0:graphics/spirv-tools \
		vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++11-lib pkgconfig python:3.4+,build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-ValidationLayers
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-29-g75b30a6:headers/external/spirv-headers
CMAKE_OFF=	BUILD_TESTS
CMAKE_ON=	BUILD_LAYER_SUPPORT_FILES
CMAKE_ARGS=	-DGLSLANG_INSTALL_DIR:PATH="${LOCALBASE}" \
		-DSPIRV_HEADERS_INSTALL_DIR:PATH="${WRKSRC_headers}"

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
