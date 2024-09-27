PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer Opus audio encoder/decoder plugin

LIB_DEPENDS=	libopus.so:audio/opus

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		base
GST_PLUGIN=	opus

.include "${MASTERDIR}/Makefile"
