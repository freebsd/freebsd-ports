PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer Vulkan graphics plugin

BUILD_DEPENDS=	${LOCALBASE}/bin/glslc:graphics/shaderc \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		${LOCALBASE}/include/libdrm/drm_fourcc.h:graphics/libdrm \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		xorg
USE_GSTREAMER=	gl
USE_XORG=	xcb

MESON_ARGS+=	-Dwayland=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	vulkan

.include "${MASTERDIR}/Makefile"
