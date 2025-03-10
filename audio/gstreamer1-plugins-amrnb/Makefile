PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer OpenCore based Adaptive Multi-Rate Narrow-Band plugin

LIB_DEPENDS=	libopencore-amrnb.so:audio/opencore-amr

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		good
GST_PLUGIN=	amrnb

.include "${MASTERDIR}/Makefile"
