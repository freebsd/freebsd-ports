PORTREVISION=	1
CATEGORIES=	audio

COMMENT=	GStreamer OpenMPT audio decoder plugin

GST_PLUGIN=	openmpt
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=  libopenmpt.so:audio/libopenmpt

.include "${MASTERDIR}/Makefile"
