PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer ATSC A/52 stream aka AC-3 (dvd audio) plugin

LIB_DEPENDS=	liba52.so:audio/liba52

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		ugly
GST_PLUGIN=	a52dec

.include "${MASTERDIR}/Makefile"
