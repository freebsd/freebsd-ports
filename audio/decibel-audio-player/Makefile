# New ports collection makefile for:	decibel-audio-player
# Date created:		2010-03-17
# Whom:			kipz <somicide@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	decibel-audio-player
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	audio multimedia gnome python
MASTER_SITES=	http://decibel.silent-blade.org/uploads/Main/

MAINTAINER=	somicide@gmail.com
COMMENT=	A fast GTK+ audio player with an clean and user friendly interface

RUN_DEPENDS=	py*-dbus>=0.80:${PORTSDIR}/devel/py-dbus \
		py*-mutagen>=1.11:${PORTSDIR}/audio/py-mutagen

LICENSE=	GPLv2

USE_PYTHON=	2.5+
USE_GNOME=	pygnome2 pygtk2
USE_GSTREAMER=	python good bad
USE_GETTEXT=	yes
USE_GMAKE=	yes
NO_BUILD=	yes
MAN1=		decibel-audio-player.1 decibel-audio-player-remote.1

#Audio gstreamer plugins
OPTIONS=	AUDIOCD "AudioCD support" on \
		FLAC "FLAC support" on \
		MP3 "MP3 support" on \
		MPEG4IP "AAC/MP4P support" on \
		OGG "OGG support" on \
		SPEEX "OGG/Speex support" off \
		VORBIS "OGG/Vorbis support" on \
		WAVPACK "Wavpack support" on

#A few extra requirements if we want to use some nifty plugins in decibel
OPTIONS+=	EXTRAS "Extra dependencies for plugins" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_AUDIOCD)
RUN_DEPENDS+=	cd-discid>=0.9:${PORTSDIR}/audio/cd-discid \
		py*-cddb>=1.4:${PORTSDIR}/audio/py-cddb \
		gstreamer-plugins-cdio>=0.10.16:${PORTSDIR}/sysutils/gstreamer-plugins-cdio
.endif

.if !defined(WITHOUT_EXTRAS)
RUN_DEPENDS+=	py*-imaging>=1.1.6:${PORTSDIR}/graphics/py-imaging \
		py*-notify>=0.1.1:${PORTSDIR}/devel/py-notify
.endif

.if !defined(WITHOUT_FLAC)
USE_GSTREAMER+=	flac
.endif

.if !defined(WITHOUT_MP3)
USE_GSTREAMER+=	mp3
.endif

.if !defined(WITHOUT_MPEG4IP)
LIB_DEPENDS+=	mp4v2.10:${PORTSDIR}/multimedia/mp4v2
USE_GSTREAMER+=	faad
.endif

.if !defined(WITHOUT_OGG)
USE_GSTREAMER+=	ogg
.endif

.if !defined(WITHOUT_SPEEX)
USE_GSTREAMER+=	speex
.endif

.if !defined(WITHOUT_VORBIS)
USE_GSTREAMER+=	vorbis
.endif

.if !defined(WITHOUT_WAVPACK)
LIB_DEPENDS+=	wavpack.2:${PORTSDIR}/audio/wavpack
USE_GSTREAMER+=	wavpack
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
