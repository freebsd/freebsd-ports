# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer GL graphics plugin

GST_PLUGIN=	gl
DIST=		bad

GL_GST_DIRS=	gst-libs/gst/allocators
PLIST=		${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

pre-build:
.for dir in ${GL_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/pkgconfig/gstreamer-gl.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/gstreamer-gl-1.0.pc

.include "${MASTERDIR}/Makefile"
