PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer ASCII art videosink plugin

GST_PLUGIN=	aalib
DIST=		good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=  libaa.so:graphics/aalib
USES=   ncurses

.include "${MASTERDIR}/Makefile"
