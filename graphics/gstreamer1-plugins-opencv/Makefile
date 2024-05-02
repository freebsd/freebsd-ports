PORTREVISION=	1
CATEGORIES=	graphics

COMMENT=	GStreamer opencv real time computer vision plugin

GST_PLUGIN=	opencv
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

# Clang has issues with Overloaded stuff inside OpenCV
CXXFLAGS+=	-Wno-overloaded-virtual
LIB_DEPENDS=   libopencv_highgui.so:graphics/opencv
GST_PLUGIN_DIR=  gst-libs/gst/opencv ext/opencv

PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
