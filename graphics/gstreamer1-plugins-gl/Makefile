PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer GL graphics plugin

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libpng16.so:graphics/png

USES=		gl jpeg
USE_GL=		gl glesv2 egl
USE_XORG+=	x11 xext xcb

MESON_ARGS+=	--wrap-mode=nodownload \
		-Dgl=enabled \
		-Dgl_winsys=${_GL_WINSYS:ts,} \
		-Dgl_api=opengl,gles2 \
		-Dgl_platform=glx,egl

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

OPTIONS_DEFINE=	WAYLAND
OPTIONS_DEFAULT=WAYLAND
OPTIONS_SUB=	yes

WAYLAND_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland
WAYLAND_VARS=		_GL_WINSYS+=wayland

DIST=		base
GST_PLUGIN=	gl
GST_PLUGIN_DIR=	gst-libs/gst/gl ext/gl

_GL_WINSYS=	x11 egl

.include "${MASTERDIR}/Makefile"
