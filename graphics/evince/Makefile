# Created by: Adam Weinberger <adamw@FreeBSD.org>

PORTNAME=	evince
DISTVERSION=	3.38.2
PORTREVISION=	4
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 multi-format document viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVOR?=	full
FLAVORS=	full lite

BUILD_DEPENDS=	itstool:textproc/itstool \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libfribidi.so:converters/fribidi \
		libspectre.so:print/libspectre \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even
SLAVEPORT?=	no

USES=		compiler:c++11-lib desktop-file-utils gettext \
		gnome libarchive localbase:ldflags meson pkgconfig tar:xz xorg
USE_GNOME=	cairo gtk30
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
USE_XORG=	ice
INSTALLS_ICONS=	yes
MESON_ARGS=	-Dps=enabled \
		-Dsystemduserunitdir=no \
		-Dgtk_doc=false

.if ${FLAVOR} == lite
MESON_ARGS+=	-Dintrospection=false \
		-Dthumbnailer=false \
		-Dpreviewer=false \
		-Dthumbnail_cache=disabled
USE_GNOME+=	libxml2
OPTIONS_EXCLUDE=	NAUTILUS DBUS
PLIST=		${.CURDIR}/pkg-plist-lite
PKGNAMESUFFIX=	-lite
COMMENT+=	without GNOME dependencies
.else
USE_GNOME+=	introspection:build
MESON_ARGS+=	-Dintrospection=true
.endif

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml

PLIST_SUB=	VERSION=3.0

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	COMICS DBUS DJVU DVI KEYRING NAUTILUS T1LIB XPS SPELL
OPTIONS_DEFAULT=COMICS DBUS DJVU KEYRING NAUTILUS XPS SPELL

COMICS_DESC=			Comic book archives support
COMICS_MESON_ENABLED=	comics

DJVU_DESC=		DJVU support
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_MESON_ENABLED=	djvu

DBUS_MESON_TRUE=	dbus
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus

DVI_DESC=		DVI viewer support
DVI_USE=		tex=latex,kpathsea
DVI_MESON_ENABLED=	dvi

KEYRING_DESC=		Keyring support
KEYRING_LIB_DEPENDS=	libsecret-1.so:security/libsecret
KEYRING_MESON_ENABLED=	keyring

NAUTILUS_DESC=		Nautilus plugin
NAUTILUS_USE=		gnome=nautilus3
NAUTILUS_MESON_TRUE=	nautilus

SPELL_DESC=		spell checking support
SPELL_MESON_ENABLED=	gspell
SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell

T1LIB_DESC=		Support TYPE1 fonts to DVI (Enables DVI)
T1LIB_LIB_DEPENDS=	libt1.so:devel/t1lib
T1LIB_MESON_ENABLED=	t1lib
T1LIB_IMPLIES=		DVI

XPS_DESC=	XPS support
XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
XPS_MESON_ENABLED=	xps

.include <bsd.port.mk>
