# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#
# Please update update atril-lite also

PORTNAME=	atril
PORTVERSION=	1.22.3
PORTREVISION=	6
CATEGORIES=	graphics print mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE multi-format document viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libsoup-2.4.so:devel/libsoup \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libtiff.so:graphics/tiff \
		libspectre.so:print/libspectre

PORTSCOUT=	limitw:1,even
SLAVEPORT?=	no

USES=		compiler:c11 desktop-file-utils gettext gmake gnome libarchive \
		libtool mate pathfix pkgconfig tar:xz xorg
USE_MATE=	icontheme
USE_XORG=	ice sm x11
USE_GNOME=	cairo gtk30 intlhack libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-gtk=3.0
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.if ${SLAVEPORT} == lite
CONFIGURE_ARGS+=--disable-thumbnailer \
		--without-matedesktop \
		--disable-previewer
.else
USE_MATE+=	desktop
.endif

GLIB_SCHEMAS=	org.mate.Atril.gschema.xml

OPTIONS_DEFINE=	CAJA COMICS DBUS DJVU DVI EPUB KEYRING T1LIB XPS
OPTIONS_DEFAULT=CAJA COMICS DBUS DJVU EPUB KEYRING XPS

OPTIONS_SUB=	yes

CAJA_DESC=		Caja plugin
CAJA_CONFIGURE_ENABLE=	caja
CAJA_USE=		MATE=caja

DJVU_DESC=		DJVU support
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_CONFIGURE_ENABLE=	djvu

COMICS_DESC=			Comic book archives support
COMICS_CONFIGURE_ENABLE=	comics

DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
DBUS_CONFIGURE_ENABLE=	dbus

KEYRING_DESC=		Keyring support
KEYRING_CONFIGURE_WITH=	keyring
KEYRING_LIB_DEPENDS=	libsecret-1.so:security/libsecret

XPS_DESC=		XPS support
XPS_CONFIGURE_ENABLE=	xps
XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps

EPUB_DESC=		Epub support
EPUB_CONFIGURE_ENABLE=	epub
EPUB_LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3

DVI_DESC=		DVI viewer support
DVI_USE=		tex=base
DVI_CONFIGURE_ENABLE=	dvi

T1LIB_DESC=		T1LIB for TYPE1 fonts to DVI (Enables DVI)
T1LIB_LIB_DEPENDS=	libt1.so:devel/t1lib
T1LIB_CONFIGURE_ENABLE=	t1lib
T1LIB_IMPLIES=		DVI

.include <bsd.port.mk>
