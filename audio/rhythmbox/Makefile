# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rhythmbox
PORTVERSION=	3.2.1
PORTREVISION=	4
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Audio player for GNOME

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		valac:lang/vala \
		gtkdoc-check:textproc/gtk-doc \
		itstool:textproc/itstool
LIB_DEPENDS=	libmusicbrainz5.so:audio/libmusicbrainz5 \
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libdbus-glib-1.so:devel/dbus-glib \
		libcheck.so:devel/check \
		libpeas-1.0.so:devel/libpeas \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libsecret-1.so:security/libsecret \
		libtdb.so:databases/tdb

USES=		desktop-file-utils gettext gmake gnome libtool localbase \
		pathfix pkgconfig tar:xz
USE_GNOME=	intlhack gnomeprefix gtk30 introspection:build \
		py3gobject3
USE_XORG=	ice xproto
GNU_CONFIGURE=	yes
USE_GSTREAMER1=	flac lame jpeg cdparanoia vorbis
CONFIGURE_ARGS=	--enable-vala \
		--without-gudev \
		--without-webkit \
		--enable-visualizer=no \
		--disable-browser-plugin \
		--with-libsecret=yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.rhythmbox.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	BRASERO DAAP GRILO IPOD NOTIFY PYTHON LIRC MTP
OPTIONS_DEFAULT=BRASERO NOTIFY PYTHON
BRASERO_DESC=	Brasero disc burning support
BRASERO_CONFIGURE_WITH=brasero
BRASERO_LIB_DEPENDS=	libbrasero-media3.so:sysutils/brasero
DAAP_DESC=	DAAP support
DAAP_CONFIGURE_ENABLE=	daap
DAAP_LIB_DEPENDS=	libdmapsharing-3.0.so:net/libdmapsharing
IPOD_DESC=	iPod support
IPOD_CONFIGURE_WITH=	ipod
IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod
GRILO_DESC=		Media discovery with Grilo
GRILO_CONFIGURE_ENABLE=	grilo
GRILO_BUILD_DEPENDS=	grilo-plugins2>=0:net/grilo-plugins2
GRILO_RUN_DEPENDS=	grilo-plugins2>=0:net/grilo-plugins2
LIRC_CONFIGURE_ENABLE=	lirc
LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
NOTIFY_CONFIGURE_ENABLE=	libnotify
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
MTP_CONFIGURE_WITH=	mtp
MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp \
			libhal.so:sysutils/hal
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_USES=		python:3.3+
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR}
# context plugin
# webkit is for the context plugin, which is broken because
# it needs textproc/py-mako@${PY_FLAVOR}
#WEBKIT_DESC=	HTML view support
#WEBKIT_CONFIGURE_WITH=	webkit
#WEBKIT_LIB_DEPENDS=	libwebkitgtk-3.0.so:www/webkit-gtk3

post-patch:
	@${REINPLACE_CMD} -e 's|{MOZILLA_PLUGINDIR|{MOZILLA_PLUGINDIR}|g' \
		${WRKSRC}/configure

# rbzeitgeist plugin needs py3-zeitgeist
post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/rhythmbox/plugins/rbzeitgeist

.include <bsd.port.mk>
