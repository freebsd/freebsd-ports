PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer taglib plugin for adding APEv2 and ID3v2 headers

BROKEN_armv6=	fails to compile: textidentificationframe.h file not found
BROKEN_armv7=	fails to compile: textidentificationframe.h file not found

LIB_DEPENDS=	libtag.so:audio/taglib

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		good
GST_PLUGIN=	taglib

.include "${MASTERDIR}/Makefile"
