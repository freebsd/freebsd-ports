PORTNAME=	vulkan-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.294
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tools and demos for the Vulkan graphics API
WWW=		https://github.com/KhronosGroup/Vulkan-Tools

LICENSE=	APACHE20

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		vulkan-headers>0:graphics/vulkan-headers

USES=		alias cmake compiler:c++11-lib pkgconfig python:build
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Tools
GH_TUPLE=	zeux:volk:1.3.270-71-gd2d0cdd:volk/volk
CMAKE_OFF=	BUILD_CUBE BUILD_ICD
CMAKE_ARGS=	-DGLSLANG_INSTALL_DIR:PATH="${LOCALBASE}"

OPTIONS_DEFINE=		WAYLAND XCB XLIB
OPTIONS_DEFAULT=	WAYLAND XCB XLIB
OPTIONS_SLAVE=		DISPLAY
OPTIONS_SUB=		yes

WAYLAND_CATEGORIES=	wayland
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
XLIB_USE=		XORG=x11
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
