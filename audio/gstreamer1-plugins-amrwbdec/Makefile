PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer OpenCore based Adaptive Multi-Rate Wide-Band Decoder plugin

LIB_DEPENDS=	libopencore-amrwb.so:audio/opencore-amr

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		good
GST_PLUGIN=	amrwbdec

.include "${MASTERDIR}/Makefile"
