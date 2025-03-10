PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer CDDA extraction (aka audio ripping) plugin

LIB_DEPENDS=	libcdda_interface.so:audio/cdparanoia

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		base
GST_PLUGIN=	cdparanoia

.include "${MASTERDIR}/Makefile"
