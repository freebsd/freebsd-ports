PORTREVISION=	1
CATEGORIES=	audio

COMMENT=	GStreamer low-latency audio server plugin

GST_PLUGIN=	jack
DIST=		good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libjack.so:audio/jack

.include "${MASTERDIR}/Makefile"
