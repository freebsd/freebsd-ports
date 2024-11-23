PORTREVISION=	1
CATEGORIES=	audio

COMMENT=	GStreamer pulseaudio plugin

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		good
GST_PLUGIN=	pulse

.include "${MASTERDIR}/Makefile"
