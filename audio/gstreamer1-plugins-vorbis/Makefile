PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer vorbis encoder/decoder plugin

GST_PLUGIN=	vorbis
DIST=		base

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

USE_GSTREAMER= ogg
LIB_DEPENDS= libvorbis.so:audio/libvorbis

.include "${MASTERDIR}/Makefile"
