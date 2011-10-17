# New ports collection makefile for:	gstreamer-plugins-moodbar
# Date created:			Sat Mar 24 17:20:02 YEKT 2007
# Whom:				Alexandr Bechikov <goo@t72.ru>
#
# $FreeBSD$
#

PORTNAME=	gstreamer-plugins-moodbar
PORTVERSION=	0.1.2
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://pwsp.net/~qbob/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	moodbar-0.1.2

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Shows the "moods" of audio tracks in Amarok

LIB_DEPENDS=	fftw3f:${PORTSDIR}/math/fftw3-float \
		fftw3:${PORTSDIR}/math/fftw3

CFLAGS:=	${CFLAGS} -O2
USE_GSTREAMER=	yes good
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

OPTIONS=	MP3 "mp3 files support" on \
		OGG "ogg files support" on \
		FLAC "flac files support" off \
		MP4 "mp4 files support" off \
		MUSEPACK "musepack files support" off \
		WMA "wma files support" off

CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/gstreamer-${GST_VERSION}
PLIST_SUB+=	VERSION="${GST_VERSION}"

.include <bsd.port.pre.mk>

.if defined(WITH_MP3)
USE_GSTREAMER+=	mp3
.endif

.if defined(WITH_OGG)
USE_GSTREAMER+=	vorbis ogg
.endif

.if defined(WITH_FLAC)
USE_GSTREAMER+=	flac
.endif

.if defined(WITH_MP4)
USE_GSTREAMER+=	faad bad
.endif

.if defined(WITH_MUSEPACK)
USE_GSTREAMER+=	musepack
.endif

.if defined(WITH_WMA)
USE_GSTREAMER+=	ffmpeg
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
