PORTREVISION=	1
CATEGORIES=	audio

COMMENT=	GStreamer free lossless audio encoder/decoder plugin

LIB_DEPENDS=	libFLAC.so:audio/flac

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		good
GST_PLUGIN=	flac

.include "${MASTERDIR}/Makefile"
