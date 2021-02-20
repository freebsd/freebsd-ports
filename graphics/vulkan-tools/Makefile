# $FreeBSD$

PORTNAME=	vulkan-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.170
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tools and demos for the Vulkan graphics API

LICENSE=	APACHE20

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:c++11-lib pkgconfig python:3.4+,build
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Tools
CMAKE_OFF=	BUILD_CUBE BUILD_ICD
CMAKE_ARGS=	-DGLSLANG_INSTALL_DIR:PATH="${LOCALBASE}"

OPTIONS_DEFINE=		WAYLAND XCB XLIB
OPTIONS_DEFAULT=	WAYLAND XCB XLIB
OPTIONS_SLAVE=		DISPLAY
OPTIONS_SUB=		yes

WAYLAND_PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
WAYLAND_PATCHFILES=	ea2e75bea224.patch:-p1 # https://github.com/KhronosGroup/Vulkan-Tools/issues/469
WAYLAND_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CMAKE_BOOL=	BUILD_WSI_WAYLAND_SUPPORT

XCB_DESC=		${X11_DESC} via libxcb
XCB_USES=		xorg
XCB_USE=		XORG=xcb
XCB_CMAKE_BOOL=		BUILD_WSI_XCB_SUPPORT

XLIB_DESC=		${X11_DESC} via libX11
XLIB_USES=		xorg
XLIB_USE=		XORG=x11,xext,ice,sm
XLIB_CMAKE_BOOL=	BUILD_WSI_XLIB_SUPPORT

# https://github.com/KhronosGroup/Vulkan-Tools/issues/307
.for _wsi in display wayland xcb xlib
do-configure-${_wsi:tu}-on: ${_wsi}-configure
${_wsi}-configure:
	@${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_SOURCE_PATH} \
		-DBUILD_CUBE:BOOL=ON -DBUILD_VULKANINFO:BOOL=OFF \
		-DCUBE_WSI_SELECTION:STRING=${_wsi:tu} \
		-B${CONFIGURE_WRKSRC}-${_wsi}
do-build-${_wsi:tu}-on: ${_wsi}-build
${_wsi}-build:
	@${SETENV} ${MAKE_ENV} ${CMAKE_BIN} --build ${BUILD_WRKSRC}-${_wsi}
do-install-${_wsi:tu}-on: ${_wsi}-install
${_wsi}-install:
. for _file in vkcube vkcubepp
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}-${_wsi}/cube/${_file} \
		${STAGEDIR}${PREFIX}/bin/${_file}-${_wsi}
. endfor
.endfor

.include <bsd.port.mk>
