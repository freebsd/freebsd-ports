# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/audio/rhythmbox3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	rhythmbox
PORTVERSION=	2.90.1.1
PORTREVISION=	1
CATEGORIES=	audio gnome
#MASTER_SITES=	GNOME
MASTER_SITES=	LOCAL/kwm
DIST_SUBDIR=	gnome3

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Audio player for GNOME

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libmusicbrainz3.so:${PORTSDIR}/audio/libmusicbrainz3 \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpeas-1.0.so:${PORTSDIR}/devel/libpeas \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		libgnome-media-profiles-3.0.so:${PORTSDIR}/multimedia/libgnome-media-profiles \
		libbrasero-media3.so:${PORTSDIR}/sysutils/brasero

USE_BZIP2=	yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_OMF=	yes
USE_XORG=	ice xproto
USE_GNOME=	intlhack gnomeprefix gtk30 introspection:build
WANT_GNOME=	yes
USE_GSTREAMER=	flac mp3 jpeg cdparanoia vorbis
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-vala
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.rhythmbox.gschema.xml

OPTIONS_DEFINE=	IPOD FAAD NOTIFY PYTHON LIRC MTP WEBKIT ITMS_PLUGIN
OPTIONS_DEFAULT=NOTIFY PYTHON 
IPOD_DESC=	iPod support
ITMS_PLUGIN_DESC=iTunes browser plugin
WEBKIT_DESC=	HTML view support
#DAAP "Enable iTunes music sharing" off \
#VISUAL "Enable clutter visualizer plugin" on \

MAN1=		rhythmbox-client.1 rhythmbox.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFAAD}
USE_GSTREAMER+=	faad
.endif

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	liblirc_client.so:${PORTSDIR}/comms/lirc
PLIST_SUB+=	LIRC=""
CONFIGURE_ARGS+=--enable-lirc
.else
CONFIGURE_ARGS+=--disable-lirc
PLIST_SUB+=	LIRC="@comment "
.endif

.if ${PORT_OPTIONS:MMTP}
LIB_DEPENDS+=	libmtp.so:${PORTSDIR}/multimedia/libmtp \
		libhal.so:${PORTSDIR}/sysutils/hal
PLIST_SUB+=	MTP=""
CONFIGURE_ARGS+=--with-mtp
.else
CONFIGURE_ARGS+=--without-mtp
PLIST_SUB+=	MTP="@comment "
.endif

#.if defined(WITH_DAAP)
# needs http://www.flyn.org/projects/libdmapsharing/
#CONFIGURE_ARGS+=--enable-daap  --with-mdns=avahi
#LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app \
#    		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
#PLIST_SUB+=	DAAP=""
#.else
#.if exists(${LOCALBASE}/lib/libavahi-client.a)
#LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
#.endif
CONFIGURE_ARGS+=--disable-daap
PLIST_SUB+=	DAAP="@comment "
#.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
PLIST_SUB+=	NOTIFY=""
.else
CONFIGURE_ARGS+=--disable-libnotify
PLIST_SUB+=	NOTIFY="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
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
# see if we can run this plugin from mozilla ..
USE_WEBPLUGINS=	webkit-gtk3
WEBPLUGINS_FILES=librhythmbox-itms-detection-plugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

CONFIGURE_ARGS+=--enable-browser-plugin
CONFIGURE_ENV+=	MOZILLA_PLUGINDIR=${WEBPLUGINS_DIR}
PLIST_SUB+=	ITMS_PLUGIN=""
.else
CONFIGURE_ARGS+=--disable-browser-plugin
PLIST_SUB+=	ITMS_PLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MWEBKIT}
LIB_DEPENDS+=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3
CONFIGURE_ARGS+=--with-webkit
PLIST_SUB+=	WEBKIT=""
.else
CONFIGURE_ARGS+=--without-webkit
PLIST_SUB+=	WEBKIT="@comment "
.endif

#.if defined(WITH_VISUAL)
#LIB_DEPENDS+=	mx-1.0.2:${PORTSDIR}/x11-toolkits/mx \
#		clutter-gtk-1.0.0:${PORTSDIR}/graphics/clutter-gtk3 \
#		clutter-gst-1.0.0:${PORTSDIR}/multimedia/clutter-gst
#CONFIGURE_ARGS+=--enable-visualizer
#PLIST_SUB+=	VISUAL=""
#.else
CONFIGURE_ARGS+=--enable-visualizer=no
PLIST_SUB+=	VISUAL="@comment "
#.endif

.include <bsd.port.mk>
