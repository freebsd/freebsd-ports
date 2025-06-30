PORTNAME=	evince
DISTVERSION=	48.0
PORTREVISION=	1
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME multi-format document viewer
WWW=		https://gitlab.gnome.org/GNOME/evince

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVOR?=	full
FLAVORS=	full lite

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR} \
		itstool:textproc/itstool
LIB_DEPENDS=	libhandy-1.so:x11-toolkits/libhandy \
		libpoppler-glib.so:graphics/poppler-glib \
		libspectre.so:print/libspectre \
		libtiff.so:graphics/tiff \
		libdbus-1.so:devel/dbus
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		compiler:c++11-lib cpe desktop-file-utils gettext gnome \
		gstreamer libarchive localbase:ldflags meson pkgconfig \
		python:build tar:xz xorg
USE_GNOME=	cairo gdkpixbuf gnomedesktop3 gtk30 introspection:build libxml2
USE_LDCONFIG=	yes
USE_XORG=	ice
CPE_VENDOR=	gnome
MESON_ARGS=	-Dgtk_doc=false \
		-Duser_doc=true \
		-Dpdf=enabled \
		-Dps=enabled \
		-Dsystemduserunitdir=no

.if ${FLAVOR} == lite
MESON_ARGS+=		-Dintrospection=false \
			-Dpreviewer=false \
			-Dthumbnail_cache=disabled \
			-Dthumbnailer=false
USE_GNOME+=		libxml2
OPTIONS_EXCLUDE=	DBUS
PLIST=			${.CURDIR}/pkg-plist-lite
PKGNAMESUFFIX=		-lite
COMMENT+=		without GNOME dependencies
CONFLICTS_INSTALL=	evince
.else
USE_GNOME+=		introspection:build gnomedesktop3
MESON_ARGS+=		-Dintrospection=true
CONFLICTS_INSTALL=	evince-lite
.endif

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml

PLIST_SUB=	VERSION=3.0

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		COMICS DBUS DJVU DVI KEYRING SPELL XPS
OPTIONS_DEFAULT=	COMICS DBUS KEYRING SPELL XPS

COMICS_DESC=		Comic book archives support
COMICS_MESON_ENABLED=	comics

DBUS_MESON_TRUE=       dbus
DBUS_LIB_DEPENDS=      libdbus-1.so:devel/dbus

DJVU_DESC=		DJVU support
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_MESON_ENABLED=	djvu

DVI_DESC=		DVI viewer support
DVI_USES=		tex
DVI_USE=		TEX=kpathsea,latex
DVI_MESON_ENABLED=	dvi

KEYRING_DESC=		Keyring support
KEYRING_LIB_DEPENDS=	libsecret-1.so:security/libsecret
KEYRING_MESON_ENABLED=	keyring

SPELL_DESC=		Spell checking support
SPELL_MESON_ENABLED=	gspell
SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell

XPS_DESC=		XPS support
XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
XPS_MESON_ENABLED=	xps

.include <bsd.port.mk>
