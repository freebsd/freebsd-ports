# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-document-viewer
PORTVERSION=	1.6.1
CATEGORIES=	graphics print mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE multi-format document viewer

BUILD_DEPENDS=	gtkdoc-scan:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
		libspectre.so:${PORTSDIR}/print/libspectre \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build docutils icontheme intlhack \
		ltasneededhack ltverhack
USE_XORG=	sm
USE_GNOME=	cairo glib20 gnomehier gtk20 libxml2
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.*

GLIB_SCHEMAS=	org.mate.Atril.gschema.xml

OPTIONS_DEFINE=	DVI T1LIB CAJA KEYRING COMICS DJVU
OPTIONS_DEFAULT=CAJA KEYRING COMICS
DVI_DESC=	DVI viewer support
T1LIB_DESC=	T1LIB for TYPE1 fonts to DVI (Enables DVI)
CAJA_DESC=	Caja plugin
KEYRING_DESC=	Gnome-Keyring without Nautilus
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

.if ${PORT_OPTIONS:MKEYRING}
USE_MATE+=	libmatekeyring
. else
CONFIGURE_ARGS+=--without-keyring
. endif

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

post-patch:
	@${REINPLACE_CMD} -e 's|AC_CHECK_HEADERS([execinfo.h])||g' \
		-e 's|" == "|" = "|g' \
			${WRKSRC}/configure.ac

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libatrildocument.so.3
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/atril/3/backends/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libatrilview.so.3
.if ${PORT_OPTIONS:MCAJA}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/caja/extensions-2.0/libatril-properties-page.so
.endif

.include <bsd.port.mk>
