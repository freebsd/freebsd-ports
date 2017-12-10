# Created by: kipz <somicide@gmail.com>
# $FreeBSD$

PORTNAME=	decibel-audio-player
PORTVERSION=	1.08
PORTREVISION=	5
CATEGORIES=	audio multimedia gnome python
MASTER_SITES=	http://decibel.silent-blade.org/uploads/Main/

MAINTAINER=	somicide@gmail.com
COMMENT=	Fast GTK+ audio player with an clean and user friendly interface

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.80:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.11:audio/py-mutagen@${PY_FLAVOR}

LICENSE=	GPLv2

USE_GNOME=	pygnome2 pygtk2
USE_GSTREAMER=	python good bad
USES=		gmake gettext desktop-file-utils python:2.7
NO_BUILD=	yes

#Audio gstreamer plugins
OPTIONS_DEFINE=	AUDIOCD FLAC MP3 MPEG4IP OGG VORBIS SPEEX WAVPACK EXTRAS
OPTIONS_DEFAULT=	AUDIOCD FLAC MP3 MPEG4IP OGG VORBIS WAVPACK EXTRAS
AUDIOCD_DESC=	AudioCD support
MPEG4IP_DESC=	AAC/MP4P support
#
##A few extra requirements if we want to use some nifty plugins in decibel
EXTRAS_DESC=	Extra dependencies for plugins

AUDIOCD_RUN_DEPENDS=	cd-discid>=0.9:audio/cd-discid \
		${PYTHON_PKGNAMEPREFIX}cddb>=1.4:audio/py-cddb@${PY_FLAVOR} \
		gstreamer-plugins-cdio>=0.10.16:sysutils/gstreamer-plugins-cdio
EXTRAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notify>=0.1.1:devel/py-notify@${PY_FLAVOR}
FLAC_USE=	GSTREAMER=flac
MP3_USE=	GSTREAMER=mp3
MPEG4IP_LIB_DEPENDS=	libmp4v2.so:multimedia/mp4v2
MPEG4IP_USE=	GSTREAMER=faad
OGG_USE=	GSTREAMER=ogg
SPEEX_USE=	GSTREAMER=speex
VORBIS_USE=	GSTREAMER=vorbis
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_USE=	GSTREAMER=wavpack

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|prefix|${PREFIX}|g' \
		${WRKSRC}/start.sh ${WRKSRC}/start-remote.sh

.include <bsd.port.mk>
