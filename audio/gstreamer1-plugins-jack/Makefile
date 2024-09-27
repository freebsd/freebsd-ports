PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer low-latency audio server plugin

LIB_DEPENDS=	libjack.so:audio/jack

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		good
GST_PLUGIN=	jack

.include "${MASTERDIR}/Makefile"
