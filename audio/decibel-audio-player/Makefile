# Created by: kipz <somicide@gmail.com>
# $FreeBSD$

PORTNAME=	decibel-audio-player
PORTVERSION=	1.08
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
USES=		gmake gettext
NO_BUILD=	yes
MAN1=		decibel-audio-player.1 decibel-audio-player-remote.1

#Audio gstreamer plugins
OPTIONS_DEFINE=	AUDIOCD FLAC MP3 MPEG4IP OGG VORBIS SPEEX WAVPACK EXTRAS
OPTIONS_DEFAULT=	AUDIOCD FLAC MP3 MPEG4IP OGG VORBIS WAVPACK EXTRAS
AUDIOCD_DESC=	AudioCD support
MPEG4IP_DESC=	AAC/MP4P support
#
##A few extra requirements if we want to use some nifty plugins in decibel
EXTRAS_DESC=	Extra dependencies for plugins

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAUDIOCD}
RUN_DEPENDS+=	cd-discid>=0.9:${PORTSDIR}/audio/cd-discid \
		py*-cddb>=1.4:${PORTSDIR}/audio/py-cddb \
		gstreamer-plugins-cdio>=0.10.16:${PORTSDIR}/sysutils/gstreamer-plugins-cdio
.endif

.if ${PORT_OPTIONS:MEXTRAS}
RUN_DEPENDS+=	py*-imaging>=1.1.6:${PORTSDIR}/graphics/py-imaging \
		py*-notify>=0.1.1:${PORTSDIR}/devel/py-notify
.endif

.if ${PORT_OPTIONS:MFLAC}
USE_GSTREAMER+=	flac
.endif

.if ${PORT_OPTIONS:MMP3}
USE_GSTREAMER+=	mp3
.endif

.if ${PORT_OPTIONS:MMPEG4IP}
LIB_DEPENDS+=	mp4v2.10:${PORTSDIR}/multimedia/mp4v2
USE_GSTREAMER+=	faad
.endif

.if ${PORT_OPTIONS:MOGG}
USE_GSTREAMER+=	ogg
.endif

.if ${PORT_OPTIONS:MSPEEX}
USE_GSTREAMER+=	speex
.endif

.if ${PORT_OPTIONS:MVORBIS}
USE_GSTREAMER+=	vorbis
.endif

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=	wavpack.2:${PORTSDIR}/audio/wavpack
USE_GSTREAMER+=	wavpack
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
