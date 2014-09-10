# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	atril
PORTVERSION=	1.8.0
CATEGORIES=	graphics print mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE multi-format document viewer

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
		libspectre.so:${PORTSDIR}/print/libspectre \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig tar:xz
USE_MATE=	icontheme caja
USE_XORG=	sm
USE_GNOME=	cairo gnomehier gtk20 intlhack libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0 \
		--disable-xps \
		--disable-static
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.Atril.gschema.xml

OPTIONS_DEFINE=	DVI T1LIB CAJA COMICS DJVU
OPTIONS_DEFAULT=CAJA COMICS
DVI_DESC=	DVI viewer support
T1LIB_DESC=	T1LIB for TYPE1 fonts to DVI (Enables DVI)
CAJA_DESC=	Caja plugin
COMICS_DESC=	Comic book archives support
DJVU_DESC=	DJVU support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDVI} || ${PORT_OPTIONS:MT1LIB}

USE_TEX=	base
CONFIGURE_ARGS+=--enable-dvi
PLIST_SUB+=	DVI=""

. if ${PORT_OPTIONS:MT1LIB}
LIB_DEPENDS+=	libt1.so:${PORTSDIR}/devel/t1lib
CONFIGURE_ARGS+=--enable-t1lib
.else
CONFIGURE_ARGS+=--disable-t1lib
. endif

.else
CONFIGURE_ARGS+=--disable-dvi
PLIST_SUB+=	DVI="@comment "
.endif

.if ${PORT_OPTIONS:MCAJA}
USE_MATE+=	caja
CONFIGURE_ARGS+=--enable-caja
PLIST_SUB+=	CAJA=""
.else
CONFIGURE_ARGS+=--disable-caja
PLIST_SUB+=	CAJA="@comment "
.endif

.if ${PORT_OPTIONS:MDJVU}
LIB_DEPENDS+=	libdjvulibre.so:${PORTSDIR}/graphics/djvulibre
CONFIGURE_ARGS+=--enable-djvu
PLIST_SUB+=	DJVU=""
.else
CONFIGURE_ARGS+=--disable-djvu
PLIST_SUB+=	DJVU="@comment "
.endif

.if ${PORT_OPTIONS:MCOMICS}
CONFIGURE_ARGS+=--enable-comics
PLIST_SUB+=	COMICS=""
.else
CONFIGURE_ARGS+=--disable-comics
PLIST_SUB+=	COMICS="@comment "
.endif

.include <bsd.port.mk>
