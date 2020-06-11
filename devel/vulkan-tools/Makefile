# $FreeBSD$

PORTNAME=	vulkan-tools
DISTVERSIONPREFIX=	sdk-
DISTVERSION=	1.2.135.0
PORTREVISION=	1
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

CMAKE_OFF=	BUILD_CUBE BUILD_ICD
CMAKE_ARGS=	-DGLSLANG_INSTALL_DIR=${LOCALBASE}

OPTIONS_DEFINE=		WAYLAND XCB XLIB
OPTIONS_DEFAULT=	WAYLAND XCB XLIB
OPTIONS_SLAVE=		DISPLAY
OPTIONS_SUB=		yes

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

# https://github.com/KhronosGroup/Vulkan-Headers/issues/122
display-build:		.IGNORE
display-install:	.IGNORE

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
