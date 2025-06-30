PORTNAME=	rhythmbox
PORTVERSION=	3.4.8
PORTREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Audio player for GNOME
WWW=		https://wiki.gnome.org/Apps/Rhythmbox

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		itstool:textproc/itstool
LIB_DEPENDS=	libtotem-plparser.so:multimedia/totem-pl-parser \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libsoup-3.0.so:devel/libsoup3 \
		libpeas-1.0.so:devel/libpeas1 \
		libjson-glib-1.0.so:devel/json-glib \
		libsecret-1.so:security/libsecret \
		libgudev-1.0.so:devel/libgudev \
		libtdb.so:databases/tdb

USES=		desktop-file-utils gettext gnome gstreamer localbase:ldflags meson \
		pkgconfig tar:xz vala:build xorg
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 introspection libxml2
USE_XORG=	ice x11 xorgproto
USE_GSTREAMER=	flac lame jpeg cdparanoia vorbis
MESON_ARGS=	-Dapidoc=false \
		-Dtests=disabled
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.rhythmbox.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	BRASERO DAAP DOCS GRILO IPOD LIRC MTP NLS NOTIFY PYTHON
OPTIONS_DEFAULT=BRASERO NOTIFY PYTHON
BRASERO_DESC=	Brasero disc burning support
BRASERO_MESON_ENABLED=	brasero
BRASERO_LIB_DEPENDS=	libbrasero-media3.so:sysutils/brasero
DAAP_DESC=	DAAP support
DAAP_MESON_ENABLED=	daap
DAAP_LIB_DEPENDS=	libdmapsharing-4.0.so:net/libdmapsharing
GRILO_DESC=		Media discovery with Grilo
GRILO_MESON_ENABLED=	grilo
GRILO_BUILD_DEPENDS=	grilo>=0.3.1:net/grilo
GRILO_LIB_DEPENDS=	libgrilo-0.3.so:net/grilo
GRILO_RUN_DEPENDS=	grilo-plugins>=0.3.2:net/grilo-plugins
IPOD_DESC=		iPod support
IPOD_MESON_ENABLED=	ipod
IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod \
			libplist-2.0.so:devel/libplist \
			libimobiledevice-1.0.so:comms/libimobiledevice
LIRC_MESON_ENABLED=	lirc
LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
MTP_MESON_ENABLED=	mtp
MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
NOTIFY_MESON_ENABLED=	libnotify
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
PYTHON_MESON_ENABLED=	plugins_python
PYTHON_USES=		python
PYTHON_USE=		gnome=pygobject3
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libpeas1>=0:devel/py-libpeas1@${PY_FLAVOR}
PYTHON_BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
