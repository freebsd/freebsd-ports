# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	atril
PORTVERSION=	1.12.2
PORTREVISION?=	0
CATEGORIES=	graphics print mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	MATE multi-format document viewer

BUILD_DEPENDS=	itstool:textproc/itstool

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libspectre.so:print/libspectre

PORTSCOUT=	limitw:1,even
SLAVEPORT?=	no

USES=		desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig tar:xz
USE_MATE=	icontheme
USE_XORG=	sm
USE_GNOME=	cairo gtk20 intlhack libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0 \
		--disable-static
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

OPTIONS_DEFINE=	CAJA COMICS DJVU DVI EPUB KEYRING T1LIB XPS
OPTIONS_DEFAULT=CAJA COMICS DJVU EPUB KEYRING XPS
DVI_DESC=	DVI viewer support
T1LIB_DESC=	T1LIB for TYPE1 fonts to DVI (Enables DVI)
CAJA_DESC=	Caja plugin
KEYRING_DESC=	Keyring support
COMICS_DESC=	Comic book archives support
DJVU_DESC=	DJVU support
XPS_DESC=	XPS support
EPUB_DESC=	Epub support

OPTIONS_SUB=	yes

CAJA_CONFIGURE_ENABLE=	caja
CAJA_USE=		MATE=caja
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_CONFIGURE_ENABLE=	djvu
COMICS_CONFIGURE_ENABLE=	comics
KEYRING_CONFIGURE_WITH=	keyring
KEYRING_LIB_DEPENDS=	libsecret-1.so:security/libsecret
XPS_CONFIGURE_ENABLE=	xps
XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
EPUB_CONFIGURE_ENABLE=	epub
EPUB_LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2

.include <bsd.port.options.mk>

.if ${SLAVEPORT} == lite
CONFIGURE_ARGS+=--disable-dbus
.else
CONFIGURE_ARGS+=--enable-dbus
LIB_DEPENDS+=	libdbus-glib-1.so:devel/dbus-glib
.endif

.if ${PORT_OPTIONS:MDVI} || ${PORT_OPTIONS:MT1LIB}
USE_TEX=	base
CONFIGURE_ARGS+=--enable-dvi
PLIST_SUB+=	DVI=""

. if ${PORT_OPTIONS:MT1LIB}
LIB_DEPENDS+=	libt1.so:devel/t1lib
CONFIGURE_ARGS+=--enable-t1lib
.else
CONFIGURE_ARGS+=--disable-t1lib
. endif

.else
CONFIGURE_ARGS+=--disable-dvi
PLIST_SUB+=	DVI="@comment "
.endif

.include <bsd.port.mk>
