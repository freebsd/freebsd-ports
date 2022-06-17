PORTNAME=	vulkan-validation-layers
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.218
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Validation layers for the Vulkan graphics API

LICENSE=	APACHE20

BUILD_DEPENDS=	spirv-tools>0:graphics/spirv-tools \
		vulkan-headers>0:graphics/vulkan-headers

USES=		alias cmake compiler:c++11-lib pkgconfig python:3.4+,build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-ValidationLayers
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-168-g5a12186:headers/external/spirv-headers \
		martinus:robin-hood-hashing:3.11.5:robin_hood/external/robin-hood-hashing
CMAKE_OFF=	BUILD_TESTS
CMAKE_ON=	BUILD_LAYER_SUPPORT_FILES
CMAKE_ARGS=	-DROBIN_HOOD_HASHING_INSTALL_DIR:PATH="${WRKSRC_robin_hood}" \
		-DSPIRV_HEADERS_INSTALL_DIR:PATH="${WRKSRC_headers}"
CFLAGS+=	${WITH_DEBUG:U-DNDEBUG}

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
