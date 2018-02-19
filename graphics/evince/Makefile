# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evince
PORTVERSION=	3.26.0
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	GNOME 3 multi-format document viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		itstool:textproc/itstool \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libspectre.so:print/libspectre \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even
SLAVEPORT?=	no

USES=		compiler:c++11-lib desktop-file-utils gettext gmake \
		gnome libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_XORG=	ice
INSTALLS_ICONS=	yes
CFLAGS+=	-Wno-error=format-nonliteral
INSTALL_TARGET=	install-strip

.if ${SLAVEPORT} == lite
CONFIGURE_ARGS+=--disable-introspection \
		--disable-libgnome-desktop \
		--disable-thumbnailer \
		--disable-previewer
USE_GNOME+=	libxml2
.else
USE_GNOME+=	introspection:build
CONFIGURE_ARGS+=	--enable-introspection \
			--with-systemduserunitdir=no
.endif

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml

PLIST_SUB=	VERSION=3.0

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	COMICS DBUS DJVU DVI KEYRING NAUTILUS T1LIB XPS
OPTIONS_DEFAULT=COMICS DBUS DJVU KEYRING NAUTILUS XPS

DVI_DESC=	DVI viewer support
T1LIB_DESC=	T1LIB for TYPE1 fonts to DVI (Enables DVI)
NAUTILUS_DESC=	Nautilus plugin
KEYRING_DESC=	Keyring support
COMICS_DESC=	Comic book archives support
DJVU_DESC=	DJVU support
XPS_DESC=	XPS support

COMICS_USES=			libarchive
COMICS_CONFIGURE_ENABLE=	comics

DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_CONFIGURE_ENABLE=	djvu

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_ENABLE=	dbus

DVI_USE=		tex=latex
DVI_CONFIGURE_ENABLE=	dvi

KEYRING_LIB_DEPENDS=		libsecret-1.so:security/libsecret
KEYRING_CONFIGURE_OFF=		--without-keyring

NAUTILUS_USE=			gnome=nautilus3
NAUTILUS_CONFIGURE_ENABLE=	nautilus

T1LIB_LIB_DEPENDS=	libt1.so:devel/t1lib
T1LIB_IMPLIES=		DVI
T1LIB_CONFIGURE_ENABLE=	t1lib

XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
XPS_CONFIGURE_ENABLE=	xps

post-patch:
	@${REINPLACE_CMD} -e '/^DOC_MODULE_VERSION/d' \
		${WRKSRC}/help/reference/libdocument/Makefile.in \
		${WRKSRC}/help/reference/libview/Makefile.in

.include <bsd.port.mk>
