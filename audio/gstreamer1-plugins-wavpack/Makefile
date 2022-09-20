PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer wavpack encode/decode plugin

GST_PLUGIN=	wavpack
DIST=		good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=  libwavpack.so:audio/wavpack

.include "${MASTERDIR}/Makefile"
