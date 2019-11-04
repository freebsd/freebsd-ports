# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rhythmbox
PORTVERSION=	3.4.2
PORTREVISION=	6
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Audio player for GNOME

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		valac:lang/vala \
		gtkdoc-check:textproc/gtk-doc \
		itstool:textproc/itstool
LIB_DEPENDS=	libmusicbrainz5.so:audio/libmusicbrainz5 \
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libhal.so:sysutils/hal \
		libsoup-2.4.so:devel/libsoup \
		libcheck.so:devel/check \
		libpeas-1.0.so:devel/libpeas \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libsecret-1.so:security/libsecret \
		libtdb.so:databases/tdb

USES=		desktop-file-utils gmake gnome libtool localbase \
		pathfix pkgconfig tar:xz xorg
USE_GNOME=	cairo intlhack glib20 gnomeprefix gtk30 introspection \
		pygobject3 libxml2
USE_XORG=	ice x11 xorgproto
GNU_CONFIGURE=	yes
USE_GSTREAMER1=	flac lame jpeg cdparanoia vorbis
CONFIGURE_ARGS=	--enable-vala \
		--enable-visualizer=no \
		--with-python=yes \
		--disable-browser-plugin \
		--with-libsecret=yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.rhythmbox.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	BRASERO DAAP DOCS GRILO IPOD LIRC MTP NLS NOTIFY PYTHON
OPTIONS_DEFAULT=BRASERO NOTIFY PYTHON
BRASERO_DESC=	Brasero disc burning support
BRASERO_CONFIGURE_WITH=	brasero
BRASERO_LIB_DEPENDS=	libbrasero-media3.so:sysutils/brasero
DAAP_DESC=	DAAP support
DAAP_CONFIGURE_ENABLE=	daap
DAAP_LIB_DEPENDS=	libdmapsharing-3.0.so:net/libdmapsharing
GRILO_DESC=		Media discovery with Grilo
GRILO_CONFIGURE_ENABLE=	grilo
GRILO_BUILD_DEPENDS=	grilo>=0.3.1:net/grilo
GRILO_LIB_DEPENDS=	libgrilo-0.3.so:net/grilo
GRILO_RUN_DEPENDS=	grilo-plugins>=0.3.2:net/grilo-plugins
IPOD_DESC=		iPod support
IPOD_CONFIGURE_WITH=	ipod
IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod \
			libplist.so:devel/libplist \
			libimobiledevice.so:comms/libimobiledevice
LIRC_CONFIGURE_ENABLE=	lirc
LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
MTP_CONFIGURE_WITH=	mtp
MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp \
			libhal.so:sysutils/hal
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
NOTIFY_CONFIGURE_ENABLE=	libnotify
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_USES=		python:3.3+
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's|{MOZILLA_PLUGINDIR|{MOZILLA_PLUGINDIR}|g' \
		${WRKSRC}/configure

# rbzeitgeist plugin needs py3-zeitgeist
post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/rhythmbox/plugins/rbzeitgeist

.include <bsd.port.mk>
