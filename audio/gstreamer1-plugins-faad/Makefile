PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer MPEG-2 and MPEG-4 AAC decoder plugin

GST_PLUGIN=	faad
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libfaad.so:audio/faad

MESON_ARGS+= -Dgpl=enabled

.include "${MASTERDIR}/Makefile"
