# $FreeBSD$

PORTNAME=	jokosher
PORTVERSION=	0.11.5
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://launchpadlibrarian.net/43860543/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-track non-linear audio editing

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR}

USES=		desktop-file-utils python:2.7 shared-mime-info
USE_PYTHON=	distutils
USE_GSTREAMER=	gnonlin good python
INSTALLS_ICONS=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DBUS FLAC GCONF GNOME JACK LADSPA LAME MP3 PIDGIN PULSEAUDIO VORBIS
OPTIONS_DEFAULT=	DBUS FLAC GCONF LADSPA VORBIS

DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}
FLAC_USE=	GSTREAMER=flac
GCONF_USE=	GSTREAMER=gconf
JACK_USE=	GSTREAMER=jack
LADSPA_USE=	GSTREAMER=ladspa
LAME_USE=	GSTREAMER=lame
MP3_DESC=	MP3 import
MP3_USE=	GSTREAMER=mp3
GNOME_USE=	GNOME=pygnome2
PIDGIN_DESC=	Pidgin status extension
PIDGIN_IMPLIES=	DBUS
PIDGIN_RUN_DEPENDS=	pidgin:net-im/pidgin
PULSEAUDIO_USE=	GSTREAMER=pulse
VORBIS_USE=	GSTREAMER=vorbis

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' -e \
		's|scrollkeeper-config||' -e \
		's|"update-desktop-database"|&, "${PREFIX}/share/applications"|' \
		${WRKSRC}/bin/${PORTNAME} ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
