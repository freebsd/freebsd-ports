PORTNAME=	vulkan-loader
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.295
CATEGORIES=	graphics devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Driver loader for the Vulkan graphics API
WWW=		https://github.com/KhronosGroup/Vulkan-Loader

LICENSE=	APACHE20

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		alias cmake compiler:c++11-lib pkgconfig python:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Loader
CMAKE_ON=	CMAKE_SKIP_RPATH
CMAKE_OFF=	BUILD_TESTS
PLIST_SUB=	VERSION=${DISTVERSION:C/-.*//}

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
# Extract (snapshot) version from the port
# Respect PREFIX when XDG_CONFIG_DIRS and XDG_DATA_DIRS are unset
	@${REINPLACE_CMD} -e '/find_.*Git/d' \
		-e '/BRANCH/s/--unknown--/main/' \
		-e '/TAG/s/--unknown--/${DISTVERSIONFULL}/' \
		-e '/FALLBACK/s,/etc,${PREFIX}&,' \
		-e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/CMakeLists.txt
# https://github.com/llvm/llvm-project/issues/46692
	@if [ "${CHOSEN_COMPILER_TYPE}-${ARCH}-${_OSRELEASE:C/.*-//}" = "clang-i386-CURRENT" ]; then \
		${ECHO} "disabled" >${WRKSRC}/loader/asm_test_x86.S; \
	fi

.include <bsd.port.mk>
