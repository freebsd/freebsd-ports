PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer CDDA extraction (aka audio ripping) plugin

GST_PLUGIN=	cdparanoia
DIST=		base

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libcdda_interface.so:audio/cdparanoia

.include "${MASTERDIR}/Makefile"
