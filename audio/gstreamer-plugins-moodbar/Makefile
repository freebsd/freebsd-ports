# Created by: Alexandr Bechikov <goo@t72.ru>
# $FreeBSD$

PORTNAME=	gstreamer-plugins-moodbar
PORTVERSION=	0.1.2
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://pwsp.net/~qbob/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	moodbar-0.1.2

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Shows the "moods" of audio tracks in Amarok

LIB_DEPENDS=	libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libfftw3.so:${PORTSDIR}/math/fftw3

CFLAGS:=	${CFLAGS} -O2
USE_GSTREAMER=	yes good
NO_STAGE=	yes
USES=		gmake pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MP3 OGG FLAC MP4 MUSEPACK WMA
OPTIONS_DEFAULT= MP3 OGG

CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/gstreamer-${GST_VERSION}
PLIST_SUB+=	VERSION="${GST_VERSION}"

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMP3}
USE_GSTREAMER+=	mp3
.endif

.if ${PORT_OPTIONS:MOGG}
USE_GSTREAMER+=	vorbis ogg
.endif

.if ${PORT_OPTIONS:MFLAC}
USE_GSTREAMER+=	flac
.endif

.if ${PORT_OPTIONS:MMP4}
USE_GSTREAMER+=	faad bad
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
USE_GSTREAMER+=	musepack
.endif

.if ${PORT_OPTIONS:MWMA}
USE_GSTREAMER+=	ffmpeg
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
