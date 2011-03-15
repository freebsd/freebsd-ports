# New ports collection makefile for:	rhythmbox
# Date created:		17 August 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/rhythmbox/Makefile,v 1.111 2010/09/28 15:55:46 kwm Exp $
#

PORTNAME=	rhythmbox
PORTVERSION=	0.12.8
PORTREVISION=	4
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Audio player for GNOME

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
    		musicbrainz3.6:${PORTSDIR}/audio/libmusicbrainz3 \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		totem-plparser.17:${PORTSDIR}/multimedia/totem-pl-parser \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		sexy.2:${PORTSDIR}/x11-toolkits/libsexy \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		gnome-media-profiles.0:${PORTSDIR}/audio/gnome-media \
		brasero-media.3:${PORTSDIR}/sysutils/brasero

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gtk20 nautilus2
WANT_GNOME=	yes
USE_GSTREAMER=	flac mp3 gnomevfs gconf jpeg
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-vala --with-libbrasero-media \
		--without-libnautilus-burn
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
		MTP "Enable MS Media Transfer Protocol support" off \
		ITMS_PLUGIN "Enable iTunes browser plugin" on

MAN1=		rhythmbox-client.1 rhythmbox.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_VORBIS)
USE_GSTREAMER+=		vorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis --disable-vorbistest
.endif

.if defined(WITH_FAAD)
USE_GSTREAMER+=		faad
.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.2:${PORTSDIR}/comms/lirc
PLIST_SUB+=	LIRC=""
CONFIGURE_ARGS+=--enable-lirc
.else
CONFIGURE_ARGS+=--disable-lirc
PLIST_SUB+=	LIRC="@comment "
.endif

.if defined(WITH_MTP)
LIB_DEPENDS+=		mtp.11:${PORTSDIR}/audio/libmtp
PLIST_SUB+=		MTP=""
CONFIGURE_ARGS+=	--with-mtp
.else
CONFIGURE_ARGS+=	--without-mtp
PLIST_SUB+=		MTP="@comment "
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
LIB_DEPENDS+=	gpod.7:${PORTSDIR}/audio/libgpod
CONFIGURE_ARGS+=--with-ipod
PLIST_SUB+=	IPOD=""
.else
CONFIGURE_ARGS+=--without-ipod
PLIST_SUB+=	IPOD="@comment "
.endif

.if !defined(WITHOUT_ITMS_PLUGIN)
USE_WEBPLUGINS=	gecko18
WEBPLUGINS_FILES=librhythmbox-itms-detection-plugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

CONFIGURE_ARGS+=--enable-browser-plugin
CONFIGURE_ENV+=	MOZILLA_PLUGINDIR=${WEBPLUGINS_DIR}
PLIST_SUB+=	ITMS_PLUGIN=""
.else
CONFIGURE_ARGS+=--disable-browser-plugin
PLIST_SUB+=	ITMS_PLUGIN="@comment "
.endif

.include <bsd.port.post.mk>
