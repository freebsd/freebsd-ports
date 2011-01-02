# New ports collection makefile for:	jokosher
# Date created:				13 Aug 2009
# Whom:					Anonymous
#
# $FreeBSD$
#

PORTNAME=	jokosher
PORTVERSION=	0.11.5
CATEGORIES=	audio
MASTER_SITES=	http://launchpadlibrarian.net/43860543/

MAINTAINER=	swell.k@gmail.com
COMMENT=	Multi-track non-linear audio editing

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		easy_install:${PORTSDIR}/devel/py-setuptools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GNOME=	gnomehier
USE_GSTREAMER=	gnonlin good python
INSTALLS_ICONS=	yes

OPTIONS=	DBUS	"D-Bus extension" on \
		FLAC	"Flac export/import" on \
		GCONF	"Gnome Audio playback/record" on \
		JACK	"Jack audio playback/record" off \
		LADSPA	"Instrument effects" on \
		LAME	"Mp3 export" off \
		MP3	"Mp3 import" off \
		PIDGIN	"Pidgin status extension" off \
		PROFILES "Gnome Audio Profiles extension" off \
		PULSE	"PulseAudio playback/record" off \
		VORBIS	"Ogg Vorbis export/import" on

.include <bsd.port.pre.mk>

.if defined(WITH_DBUS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
.endif

.if defined(WITH_GNOME) || defined(WITH_PROFILES) \
	|| ${HAVE_GNOME:Mpygnome2}!=""
USE_GNOME+=	pygnome2
.endif

.if defined(WITH_PIDGIN)
. if defined(WITHOUT_DBUS)
IGNORE=		requires DBUS support
. endif
RUN_DEPENDS+=	pidgin:${PORTSDIR}/net-im/pidgin
.endif

.if !defined(WITHOUT_OMF) || exists(${LOCALBASE}/bin/scrollkeeper-update)
RUN_DEPENDS+=	scrollkeeper-update:${PORTSDIR}/textproc/scrollkeeper
INSTALLS_OMF=	yes
PLIST_SUB+=	OMF=""
.else
PLIST_SUB+=	OMF="@comment "
.endif

.for plugin in flac gconf jack ladspa lame mp3 pulse vorbis
. if defined(WITH_${plugin:U})
USE_GSTREAMER+=${plugin}
. endif
.endfor

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' -e \
		'\|scrollkeeper-preinstall|s|HELPURI\[fileNum]|"file://" + &|' -e \
		's|"update-desktop-database"|&, "${PREFIX}/share/applications"|' \
		${WRKSRC}/bin/${PORTNAME} ${WRKSRC}/${PYSETUP}

.include <bsd.port.post.mk>
