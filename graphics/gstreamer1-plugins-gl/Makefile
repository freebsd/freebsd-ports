# $FreeBSD$

PORTREVISION=	2
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

WAYLAND_CONFIGURE_ENABLE=	wayland
WAYLAND_LIB_DEPENDS=		libwayland-egl.so:graphics/wayland

pre-build:
.for dir in ${GL_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/pkgconfig/gstreamer-gl.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/gstreamer-gl-1.0.pc

.include "${MASTERDIR}/Makefile"
