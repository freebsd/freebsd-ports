# $FreeBSD$

PORTNAME=	vulkan-loader
DISTVERSIONPREFIX=sdk-
DISTVERSION=	1.2.135.0
CATEGORIES=	graphics devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Driver loader for the Vulkan graphics API

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:devel/vulkan-headers

USES=		cmake compiler:c++11-lib pkgconfig python:3.4+,build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Loader

CMAKE_ON=	CMAKE_SKIP_RPATH
CMAKE_OFF=	BUILD_TESTS

OPTIONS_DEFINE=	XLIB XCB WAYLAND
OPTIONS_DEFAULT=XLIB XCB WAYLAND

XLIB_DESC=	Build Xlib WSI (Window System Integration) support
XCB_DESC=	Build XCB WSI (Window System Integration) support
WAYLAND_DESC=	Build Wayland WSI (Window System Integration) support

XLIB_CMAKE_BOOL=	BUILD_WSI_XLIB_SUPPORT
XLIB_LIB_DEPENDS=	libX11.so:x11/libX11 \
			libXrandr.so:x11/libXrandr
XCB_CMAKE_BOOL=		BUILD_WSI_XCB_SUPPORT
XCB_LIB_DEPENDS=	libX11-xcb.so:x11/libX11 \
			libxcb.so:x11/libxcb
WAYLAND_CMAKE_BOOL=	BUILD_WSI_WAYLAND_SUPPORT
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland

.include <bsd.port.pre.mk>

# XXX Drop after FreeBSD 11.3/12.1 EOL
.if ${ARCH} == i386 && ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 100
. if ${LLVM_DEFAULT:C/[1-5]./&0/:S,-devel,990,} < 100
LLVM_DEFAULT=	10
. endif
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
.endif

.include <bsd.port.post.mk>
