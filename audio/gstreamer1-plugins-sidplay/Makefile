PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer Commodore SID audio decoder plugin

GST_PLUGIN=	sidplay
DIST=		ugly

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=  libsidplay.so:audio/libsidplay

MESON_ARGS+= -Dgpl=enabled

.include "${MASTERDIR}/Makefile"
