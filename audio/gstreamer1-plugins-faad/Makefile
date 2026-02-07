PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer MPEG-2 and MPEG-4 AAC decoder plugin

LIB_DEPENDS=	libfaad.so:audio/faad

MESON_ARGS+=	-Dgpl=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	faad

.include "${MASTERDIR}/Makefile"
