PORTREVISION=	1
CATEGORIES=	audio

COMMENT=	GStreamer OpenMPT audio decoder plugin

GST_PLUGIN=	openmpt
DIST=		bad

OPENMPT_GST_DIRS=	gst-libs/gst/audio

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

pre-build:
.for dir in ${OPENMPT_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

.include "${MASTERDIR}/Makefile"
