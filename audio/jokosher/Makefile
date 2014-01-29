# $FreeBSD$

PORTNAME=	jokosher
PORTVERSION=	0.11.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://launchpadlibrarian.net/43860543/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-track non-linear audio editing

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>0:${PORTSDIR}/devel/py-xdg

USE_PYTHON=	2
NO_STAGE=	yes
USE_PYDISTUTILS=yes
USE_GNOME=	gnomehier
USE_GSTREAMER=	gnonlin good python
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DBUS FLAC GCONF JACK LADSPA LAME MP3 PIDGIN PROFILES PULSE VORBIS
OPTIONS_DEFAULT=	DBUS FLAC GCONF LADSPA VORBIS
MP3_DESC=	MP3 import
PIDGIN_DESC=	Pidgin status extension
PROFILES_DESC=	Gnome Audio Profiels extension
PULSE_DESC=	${PULSEAUDIO_DESC}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDBUS}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
.endif

.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MPROFILES}
	|| ${HAVE_GNOME:Mpygnome2}!=""
USE_GNOME+=	pygnome2
.endif

.if ${PORT_OPTIONS:MPIDGIN}
.if empty(PORT_OPTIONS:MDBUS)
IGNORE=		requires DBUS support
. endif
RUN_DEPENDS+=	pidgin:${PORTSDIR}/net-im/pidgin
.endif

.if ${PORT_OPTIONS:MOMF} || exists(${LOCALBASE}/bin/scrollkeeper-update)
RUN_DEPENDS+=	scrollkeeper-update:${PORTSDIR}/textproc/scrollkeeper
INSTALLS_OMF=	yes
PLIST_SUB+=	OMF=""
.else
PLIST_SUB+=	OMF="@comment "
.endif

.for plugin in flac gconf jack ladspa lame mp3 pulse vorbis
. if ${PORT_OPTIONS:M${plugin:U}}
USE_GSTREAMER+=${plugin}
. endif
.endfor

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' -e \
		'\|scrollkeeper-preinstall|s|HELPURI\[fileNum]|"file://" + &|' -e \
		's|"update-desktop-database"|&, "${PREFIX}/share/applications"|' \
		${WRKSRC}/bin/${PORTNAME} ${WRKSRC}/${PYSETUP}

.include <bsd.port.post.mk>
