PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer MPEG-2 and MPEG-4 AAC encoder plugin

GST_PLUGIN=	faac
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libfaac.so:audio/faac

.include "${MASTERDIR}/Makefile"
