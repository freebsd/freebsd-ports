PORTREVISION=	1
CATEGORIES=	audio

COMMENT=	GStreamer Opus audio encoder/decoder plugin

GST_PLUGIN=	opus
DIST=		base

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libopus.so:audio/opus

.include "${MASTERDIR}/Makefile"
