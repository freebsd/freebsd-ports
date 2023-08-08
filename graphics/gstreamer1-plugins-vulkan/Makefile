PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer Vulkan graphics plugin

GST_PLUGIN=	vulkan
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

USE_GSTREAMER= gl
BUILD_DEPENDS= ${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
	${LOCALBASE}/include/libdrm/drm_fourcc.h:graphics/libdrm \
	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
	wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=   libvulkan.so:graphics/vulkan-loader \
	libwayland-client.so:graphics/wayland \
	libshaderc_shared.so:graphics/shaderc

MESON_ARGS+=  -Dwayland=enabled

.include "${MASTERDIR}/Makefile"
