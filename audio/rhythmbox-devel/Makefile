# New ports collection makefile for:	rhythmbox
# Date created:		17 August 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/rhythmbox-devel/Makefile,v 1.90 2008/03/17 04:31:25 marcus Exp $
#

PORTNAME=	rhythmbox
PORTVERSION=	0.11.6
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.11
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Audio player for GNOME

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		totem-plparser.10:${PORTSDIR}/multimedia/totem-pl-parser \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		sexy.2:${PORTSDIR}/x11-toolkits/libsexy \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		gnome-media-profiles.0:${PORTSDIR}/audio/gnome-media

NO_LATEST_LINK=	yes

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui nautiluscdburner
WANT_GNOME=	yes
USE_GSTREAMER=	flac mp3 gnomevfs gconf jpeg
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--enable-nautilus-menu --with-playback=gstreamer-0-10 \
		--disable-vala
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LIBS="-lm" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

GCONF_SCHEMAS=	rhythmbox.schemas

OPTIONS=	DAAP "Enable iTunes music sharing" off \
		IPOD "Enable iPod support" on \
		FAAD "Enable FAAD decoder support" off \
		NOTIFY "Enable libnotify support" on \
		VORBIS "Enable Ogg/Vorbis support" on \
		LIRC "Enable Infrared syncing support" off \
		GECKO_PLUGIN "Enable iTunes browser plugin" on
#		GDA "Enable GDA database storage" off

CONFLICTS=	rhythmbox-0.10.[0-9]*

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_VORBIS)
USE_GSTREAMER+=		vorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis --disable-vorbistest
.endif

.if defined(WITH_FAAD)
USE_GSTREAMER+=		faad
.endif

#.if defined(WITH_GDA)
#USE_GNOME+=	libgda2
#CONFIGURE_ARGS+=--with-database=libgda
#.else
CONFIGURE_ARGS+=--with-database=tree
#.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.1:${PORTSDIR}/comms/lirc
PLIST_SUB+=	LIRC=""
CONFIGURE_ARGS+=--enable-lirc
.else
CONFIGURE_ARGS+=--disable-lirc
PLIST_SUB+=	LIRC="@comment "
.endif

.if defined(WITH_DAAP)
CONFIGURE_ARGS+=	--enable-daap  --with-mdns=avahi
LIB_DEPENDS+=		avahi-client:${PORTSDIR}/net/avahi-app \
    			gnome-keyring:${PORTSDIR}/security/gnome-keyring
PLIST_SUB+=		DAAP=""
.else
.if exists(${LOCALBASE}/lib/libavahi-client.a)
LIB_DEPENDS+=		avahi-client:${PORTSDIR}/net/avahi-app
.endif
CONFIGURE_ARGS+=	--disable-daap
PLIST_SUB+=		DAAP="@comment "
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=		notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS+=		${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.if exists(${LOCALBASE}/libdata/pkgconfig/gst-python-0.10.pc)
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GSTREAMER+=	python
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if !defined(WITHOUT_IPOD)
LIB_DEPENDS+=	gpod.3:${PORTSDIR}/audio/libgpod
CONFIGURE_ARGS+=--with-ipod
PLIST_SUB+=	IPOD=""
.else
CONFIGURE_ARGS+=--without-ipod
PLIST_SUB+=	IPOD="@comment "
.endif

.if !defined(WITHOUT_GECKO_PLUGIN)
USE_GECKO=	firefox mozilla seamonkey xulrunner<->firefox firefox-devel<->firefox
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
CONFIGURE_ARGS+=--enable-browser-plugin \
		--with-gecko=${GECKO}
CONFIGURE_ENV+=	MOZILLA_PLUGINDIR=${BROWSER_PLUGINS_DIR}
PLIST_SUB+=	GECKO_PLUGIN=""
.else
CONFIGURE_ARGS+=--disable-browser-plugin
PLIST_SUB+=	GECKO_PLUGIN="@comment "
.endif

.include <bsd.port.post.mk>
