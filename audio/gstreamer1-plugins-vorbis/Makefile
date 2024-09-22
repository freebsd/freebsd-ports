PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer vorbis encoder/decoder plugin

LIB_DEPENDS=	libvorbis.so:audio/libvorbis

USE_GSTREAMER=	ogg

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		base
GST_PLUGIN=	vorbis

.include "${MASTERDIR}/Makefile"
