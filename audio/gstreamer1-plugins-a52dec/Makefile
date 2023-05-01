PORTREVISION=	1
CATEGORIES=	audio

COMMENT=	GStreamer ATSC A/52 stream aka AC-3 (dvd audio) plugin

GST_PLUGIN=	a52dec
DIST=		ugly

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

MESON_ARGS+= -Dgpl=enabled

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= liba52.so:audio/liba52

.include "${MASTERDIR}/Makefile"
