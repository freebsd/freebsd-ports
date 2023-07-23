PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer Bauer Stereophonic to Banaural BSP (bs2b) plugin

GST_PLUGIN=	bs2b
DIST=		bad

MASTERDIR=  ${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist
LIB_DEPENDS= libbs2b.so:audio/libbs2b

MESON_ARGS+= -Dgpl=enabled

.include "${MASTERDIR}/Makefile"
