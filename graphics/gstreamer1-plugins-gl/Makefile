PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer GL graphics plugin

GST_PLUGIN=	gl
DIST=		base

GL_GST_DIRS=	gst-libs/gst/allocators gst-libs/gst/video
PLIST=		${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

OPTIONS_DEFINE=	WAYLAND
OPTIONS_DEFAULT=WAYLAND
OPTIONS_SUB=	yes

GL_WINSYS=	x11 egl

WAYLAND_VARS=			GL_WINSYS+=wayland
WAYLAND_BUILD_DEPENDS=		wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=		libwayland-egl.so:graphics/wayland

USES=		gl
USE_GL=		gl glu glesv2 egl
USE_XORG+=	x11 \
		xext \
		xcb
BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libpng16.so:graphics/png

MESON_ARGS+=	-Dgl=enabled \
		-Dgl_winsys=${GL_WINSYS:ts,} \
		-Dgl_api=opengl,gles2 \
		-Dgl_platform=glx,egl

GST_PLUGIN_DIR=	gst-libs/gst/gl ext/gl

.include "${MASTERDIR}/Makefile"
