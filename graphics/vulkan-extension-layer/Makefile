PORTNAME=	vulkan-extension-layer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.326
CATEGORIES=	graphics

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Layer providing Vulkan features when native support is unavailable
WWW=		https://github.com/KhronosGroup/Vulkan-ExtensionLayer

LICENSE=			APACHE20 CC-BY-4.0 LLVM-exception MIT
LICENSE_COMB=			multi
LICENSE_NAME_LLVM-exception=	LLVM Exceptions to the Apache 2.0 License
LICENSE_FILE_APACHE20=		${WRKSRC}/LICENSES/Apache-2.0.txt
LICENSE_FILE_CC-BY-4.0=		${WRKSRC}/LICENSES/CC-BY-4.0.txt
LICENSE_FILE_LLVM-exception=	${WRKSRC}/LICENSES/LLVM-exception.txt
LICENSE_FILE_MIT=		${WRKSRC}/LICENSES/MIT.txt
LICENSE_PERMS_LLVM-exception=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
		vulkan-utility-libraries>0:graphics/vulkan-utility-libraries

USES=		cmake compiler:c++11-lib pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-ExtensionLayer
CMAKE_OFF=	BUILD_TESTS

OPTIONS_DEFINE=	WAYLAND XCB XLIB
OPTIONS_DEFAULT=WAYLAND XCB XLIB

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
