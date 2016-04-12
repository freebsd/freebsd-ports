# Created by: Alexandr Bechikov <goo@t72.ru>
# $FreeBSD$

PORTNAME=	gstreamer-plugins-moodbar
PORTVERSION=	0.1.2
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://pwsp.net/~qbob/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	moodbar-0.1.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows the "moods" of audio tracks in Amarok

LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libfftw3.so:math/fftw3

CFLAGS:=	${CFLAGS} -O2
USE_GSTREAMER=	yes good
USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MP3 OGG FLAC MP4 MUSEPACK WMA
OPTIONS_DEFAULT= MP3 OGG

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/gstreamer-${GST_VERSION}
PLIST_SUB+=	VERSION="${GST_VERSION}"

MP3_USE=	GSTREAMER=mp3
OGG_USE=	GSTREAMER=vorbis,ogg
FLAC_USE=	GSTREAMER=flac
MP4_USE=	GSTREAMER=faad,bad
MUSEPACK_USE=	GSTREAMER=musepack
WMA_USE=	GSTREAMER=ffmpeg

.include <bsd.port.mk>
