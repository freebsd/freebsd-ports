PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer Bauer Stereophonic to Banaural BSP (bs2b) plugin

LIB_DEPENDS=	libbs2b.so:audio/libbs2b

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	bs2b

.include "${MASTERDIR}/Makefile"
