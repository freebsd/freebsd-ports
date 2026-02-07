PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer WebRTC Audio Processing plugin

LIB_DEPENDS=	libwebrtc-audio-processing-1.so:audio/webrtc-audio-processing

USES+=		compiler:c++11-lang

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	webrtcdsp

.include "${MASTERDIR}/Makefile"
