# $FreeBSD$

PORTNAME=	vulkan-loader
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.172
CATEGORIES=	graphics devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Driver loader for the Vulkan graphics API

LICENSE=	APACHE20

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:${ARCH:Mi386:C/.+/gcc-/}c++11-lib pkgconfig python:3.4+,build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Loader
CMAKE_ON=	CMAKE_SKIP_RPATH
CMAKE_OFF=	BUILD_TESTS

OPTIONS_DEFINE=	WAYLAND XCB XLIB
OPTIONS_DEFAULT=WAYLAND XCB XLIB

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CMAKE_BOOL=	BUILD_WSI_WAYLAND_SUPPORT

XCB_DESC=		${X11_DESC} via libxcb
XCB_USES=		xorg
XCB_USE=		XORG=xcb
XCB_CMAKE_BOOL=		BUILD_WSI_XCB_SUPPORT

XLIB_DESC=		${X11_DESC} via libX11
XLIB_USES=		xorg
XLIB_USE=		XORG=x11,xrandr
XLIB_CMAKE_BOOL=	BUILD_WSI_XLIB_SUPPORT

post-patch:
# _XOPEN_SOURCE enforces X/Open-compliance but alloca isn't there
	@${REINPLACE_CMD} '/_XOPEN_SOURCE/d' ${WRKSRC}/loader/CMakeLists.txt

.include <bsd.port.mk>
