PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	GStreamer ALSA plugin

LIB_DEPENDS=	libasound.so:audio/alsa-lib
RUN_DEPENDS=	alsa-plugins>=0:audio/alsa-plugins

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		base
GST_PLUGIN=	alsa

.include "${MASTERDIR}/Makefile"
