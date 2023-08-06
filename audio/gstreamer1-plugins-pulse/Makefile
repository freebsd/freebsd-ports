PORTREVISION=	1
CATEGORIES=	audio

COMMENT=	GStreamer pulseaudio plugin

GST_PLUGIN=	pulse
DIST=		good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=  libpulse.so:audio/pulseaudio

.include "${MASTERDIR}/Makefile"
