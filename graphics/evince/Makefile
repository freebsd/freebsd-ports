# Created by: Adam Weinberger <adamw@FreeBSD.org>

PORTNAME=	evince
DISTVERSION=	42.3
PORTREVISION=	2
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME multi-format document viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVOR?=	full
FLAVORS=	full lite

BUILD_DEPENDS=	adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libhandy-1.so:x11-toolkits/libhandy \
		libpoppler-glib.so:graphics/poppler-glib \
		libspectre.so:print/libspectre \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even
SLAVEPORT?=	no

USES=		compiler:c++11-lib cpe desktop-file-utils gettext gnome gstreamer libarchive \
		localbase:ldflags meson pkgconfig tar:xz xorg
USE_GNOME=	cairo gtk30
USE_LDCONFIG=	yes
USE_XORG=	ice
CPE_VENDOR=	gnome
MESON_ARGS=	-Dgtk_doc=false \
		-Dpdf=enabled \
		-Dps=enabled \
		-Dsystemduserunitdir=no

.if ${FLAVOR} == lite
MESON_ARGS+=		-Dintrospection=false \
			-Dpreviewer=false \
			-Dthumbnail_cache=disabled \
			-Dthumbnailer=false
USE_GNOME+=		libxml2
OPTIONS_EXCLUDE=	DBUS NAUTILUS
PLIST=			${.CURDIR}/pkg-plist-lite
PKGNAMESUFFIX=		-lite
COMMENT+=		without GNOME dependencies
CONFLICTS_INSTALL=	evince
.else
USE_GNOME+=		introspection:build
MESON_ARGS+=		-Dintrospection=true
CONFLICTS_INSTALL=	evince-lite
.endif

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml

PLIST_SUB=	VERSION=3.0

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		COMICS DBUS DJVU DVI KEYRING NAUTILUS SPELL XPS
OPTIONS_DEFAULT=	COMICS DBUS DJVU KEYRING NAUTILUS SPELL XPS

COMICS_DESC=		Comic book archives support
COMICS_MESON_ENABLED=	comics

DJVU_DESC=		DJVU support
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_MESON_ENABLED=	djvu

DBUS_MESON_TRUE=	dbus
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus

DVI_DESC=		DVI viewer support
DVI_USE=		TEX=kpathsea,latex
DVI_MESON_ENABLED=	dvi

KEYRING_DESC=		Keyring support
KEYRING_LIB_DEPENDS=	libsecret-1.so:security/libsecret
KEYRING_MESON_ENABLED=	keyring

NAUTILUS_DESC=		Nautilus plugin
NAUTILUS_USE=		GNOME=nautilus3
NAUTILUS_MESON_TRUE=	nautilus

SPELL_DESC=		spell checking support
SPELL_MESON_ENABLED=	gspell
SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell

XPS_DESC=		XPS support
XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
XPS_MESON_ENABLED=	xps

.include <bsd.port.mk>
