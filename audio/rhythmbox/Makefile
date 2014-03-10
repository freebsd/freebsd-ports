# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/rhythmbox/Makefile,v 1.115 2011/05/04 18:44:36 kwm Exp $

PORTNAME=	rhythmbox
PORTVERSION=	0.12.8
PORTREVISION=	10
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Audio player for GNOME

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libmusicbrainz3.so:${PORTSDIR}/audio/libmusicbrainz3 \
		libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libsexy.so:${PORTSDIR}/x11-toolkits/libsexy \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libgnome-media-profiles.so:${PORTSDIR}/audio/gnome-media \
		libbrasero-media.so:${PORTSDIR}/sysutils/brasero

CONFLICTS=	rhythmbox-2.[0-9]* rhythmbox-3.[0-9]*

USE_BZIP2=	yes
NO_STAGE=	yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_OMF=	yes
USE_GNOME=	intlhack gnomeprefix gtk20 nautilus2
WANT_GNOME=	yes
USE_GSTREAMER=	flac mp3 gnomevfs gconf jpeg
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-vala --with-libbrasero-media \
		--without-libnautilus-burn
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LIBS="-lm"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	rhythmbox.schemas

OPTIONS_DEFINE=	DAAP IPOD FAAD NOTIFY VORBIS LIRC MTP ITMS_PLUGIN
OPTIONS_DEFAULT=	IPOD NOTIFY VORBIS ITMS_PLUGIN
DAAP_DESC=		iTunes music sharing
IPOD_DESC=		iPod support
ITMS_PLUGIN_DESC=	iTunes browser plugin

MAN1=		rhythmbox-client.1 rhythmbox.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVORBIS}
USE_GSTREAMER+=		vorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis --disable-vorbistest
.endif

.if ${PORT_OPTIONS:MFAAD}
USE_GSTREAMER+=		faad
.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=	liblirc_client.so${PORTSDIR}/comms/lirc
PLIST_SUB+=	LIRC=""
CONFIGURE_ARGS+=--enable-lirc
.else
CONFIGURE_ARGS+=--disable-lirc
PLIST_SUB+=	LIRC="@comment "
.endif

.if ${PORT_OPTIONS:MMTP}
LIB_DEPENDS+=		libmtp.so:${PORTSDIR}/multimedia/libmtp
PLIST_SUB+=		MTP=""
CONFIGURE_ARGS+=	--with-mtp
.else
CONFIGURE_ARGS+=	--without-mtp
PLIST_SUB+=		MTP="@comment "
.endif

.if ${PORT_OPTIONS:MDAAP}
CONFIGURE_ARGS+=	--enable-daap  --with-mdns=avahi
LIB_DEPENDS+=		libavahi-client.so:${PORTSDIR}/net/avahi-app \
    			gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
PLIST_SUB+=		DAAP=""
.else
.if exists(${LOCALBASE}/lib/libavahi-client.a)
LIB_DEPENDS+=		libavahi-client.so:${PORTSDIR}/net/avahi-app
.endif
CONFIGURE_ARGS+=	--disable-daap
PLIST_SUB+=		DAAP="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=		libnotify.so:${PORTSDIR}/devel/libnotify
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

.if ${PORT_OPTIONS:MIPOD}
LIB_DEPENDS+=	libgpod.so:${PORTSDIR}/audio/libgpod
CONFIGURE_ARGS+=--with-ipod
PLIST_SUB+=	IPOD=""
.else
CONFIGURE_ARGS+=--without-ipod
PLIST_SUB+=	IPOD="@comment "
.endif

.if ${PORT_OPTIONS:MITMS_PLUGIN}
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

.include <bsd.port.mk>
