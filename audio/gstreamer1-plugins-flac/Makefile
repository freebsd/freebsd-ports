PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer free lossless audio encoder/decoder plugin

GST_PLUGIN=	flac
DIST=		good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libFLAC.so:audio/flac

.include "${MASTERDIR}/Makefile"
