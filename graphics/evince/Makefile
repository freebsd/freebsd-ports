# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evince
PORTVERSION=	3.28.5
PORTREVISION=	14
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	GNOME 3 multi-format document viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

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

USES=		compiler:c++11-lib desktop-file-utils gettext gmake \
		gnome libarchive libtool localbase pathfix pkgconfig tar:xz xorg
USE_GNOME=	cairo gtk30 intlhack
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_XORG=	ice
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=minimum \
		--enable-ps \
		--with-systemduserunitdir=no
INSTALL_TARGET=	install-strip

.if ${SLAVEPORT} == lite
CONFIGURE_ARGS+=--disable-introspection \
		--disable-libgnome-desktop \
		--disable-thumbnailer \
		--disable-previewer
USE_GNOME+=	libxml2
.else
USE_GNOME+=	introspection:build
CONFIGURE_ARGS+=	--enable-introspection
.endif

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml

PLIST_SUB=	VERSION=3.0

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	COMICS DBUS DJVU DVI KEYRING NAUTILUS T1LIB XPS
OPTIONS_DEFAULT=COMICS DBUS DJVU KEYRING NAUTILUS XPS

COMICS_DESC=			Comic book archives support
COMICS_CONFIGURE_ENABLE=	comics

DJVU_DESC=		DJVU support
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_CONFIGURE_ENABLE=	djvu

DBUS_CONFIGURE_ENABLE=	dbus
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus

DVI_DESC=		DVI viewer support
DVI_USE=		tex=latex,kpathsea
DVI_CONFIGURE_ENABLE=	dvi

KEYRING_DESC=			Keyring support
KEYRING_LIB_DEPENDS=		libsecret-1.so:security/libsecret
KEYRING_CONFIGURE_WITH=		keyring

NAUTILUS_DESC=			Nautilus plugin
NAUTILUS_USE=			gnome=nautilus3
NAUTILUS_CONFIGURE_ENABLE=	nautilus

T1LIB_DESC=		Support TYPE1 fonts to DVI (Enables DVI)
T1LIB_LIB_DEPENDS=	libt1.so:devel/t1lib
T1LIB_CONFIGURE_ENABLE=	t1lib
T1LIB_IMPLIES=		DVI

XPS_DESC=	XPS support
XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
XPS_CONFIGURE_ENABLE=	xps

post-patch:
	@${REINPLACE_CMD} -e '/^DOC_MODULE_VERSION/d' \
		${WRKSRC}/help/reference/libdocument/Makefile.in \
		${WRKSRC}/help/reference/libview/Makefile.in

.include <bsd.port.mk>
