# $FreeBSD$

PORTNAME=	vulkan-tools
DISTVERSIONPREFIX=	sdk-
DISTVERSION=	1.2.135.0
CATEGORIES=	devel graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Tools and demos for the Vulkan graphics API

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:devel/vulkan-headers \
		glslangValidator:devel/glslang
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:c++11-lib pkgconfig python:3.4+,build

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Tools

CMAKE_OFF=	BUILD_ICD
CMAKE_ARGS=	-DGLSLANG_INSTALL_DIR=${LOCALBASE}

OPTIONS_DEFINE=		WAYLAND XCB XLIB
OPTIONS_DEFAULT=	WAYLAND XCB XLIB

WAYLAND_DESC=	Build Wayland WSI (Window System Integration) support
XCB_DESC=	Build XCB WSI (Window System Integration) support
XLIB_DESC=	Build Xlib WSI (Window System Integration) support

WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CMAKE_BOOL=	BUILD_WSI_WAYLAND_SUPPORT

XCB_CMAKE_BOOL=		BUILD_WSI_XCB_SUPPORT
XCB_LIB_DEPENDS=	libxcb.so:x11/libxcb

XLIB_CMAKE_BOOL=	BUILD_WSI_XLIB_SUPPORT
XLIB_LIB_DEPENDS=	libX11.so:x11/libX11 \
			libXext.so:x11/libXext \
			libICE.so:x11/libICE \
			libSM.so:x11/libSM

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXCB}
CMAKE_ARGS+=	-DCUBE_WSI_SELECTION:STRING="XCB"
.elif ${PORT_OPTIONS:MXLIB}
CMAKE_ARGS+=	-DCUBE_WSI_SELECTION:STRING="XLIB"
.elif ${PORT_OPTIONS:MWAYLAND}
CMAKE_ARGS+=	-DCUBE_WSI_SELECTION:STRING="WAYLAND"
.else
CMAKE_ARGS+=	-DCUBE_WSI_SELECTION:STRING="DISPLAY"
BROKEN=		fails to build
.endif

.include <bsd.port.mk>
