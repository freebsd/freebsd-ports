PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer opencv real time computer vision plugin

LIB_DEPENDS=	libopencv_highgui.so:graphics/opencv

# Clang has issues with Overloaded stuff inside OpenCV
CXXFLAGS+=	-Wno-overloaded-virtual

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	opencv
GST_PLUGIN_DIR=	gst-libs/gst/opencv ext/opencv

.include "${MASTERDIR}/Makefile"
