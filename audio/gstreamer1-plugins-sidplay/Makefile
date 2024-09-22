PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer Commodore SID audio decoder plugin

LIB_DEPENDS=	libsidplay.so:audio/libsidplay

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		ugly
GST_PLUGIN=	sidplay

.include "${MASTERDIR}/Makefile"
