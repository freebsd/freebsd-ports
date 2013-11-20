# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/evince3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	evince
PORTVERSION=	3.6.1
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 multi-format document viewer

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		itstool:${PORTSDIR}/textproc/itstool \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
		libspectre.so:${PORTSDIR}/print/libspectre
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_LDCONFIG=	yes
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_XORG=	ice
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig
USE_GNOME=	intlhack gnomeprefix ltasneededhack introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-xps --enable-introspection

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml

PLIST_SUB=	VERSION=3.0

OPTIONS_DEFINE=	DVI T1LIB NAUTILUS KEYRING COMICS IMPRESS DJVU
OPTIONS_DEFAULT=NAUTILUS KEYRING COMICS
DVI_DESC=	DVI viewer support
T1LIB_DESC=	T1LIB for TYPE1 fonts to DVI (Enables DVI)
NAUTILUS_DESC=	Nautilus plugin
KEYRING_DESC=	Gnome-Keyring without Nautilus
COMICS_DESC=	Comic book archives support
IMPRESS_DESC=	Impress presentations support
DJVU_DESC=	DJVU support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDVI} || ${PORT_OPTIONS:MT1LIB}
USE_TEX=	latex

CONFIGURE_ARGS+=	--enable-dvi
PLIST_SUB+=		DVI=""
. if ${PORT_OPTIONS:MT1LIB}
LIB_DEPENDS+=	libt1.so:${PORTSDIR}/devel/t1lib
CONFIGURE_ARGS+=	--enable-t1lib
. else
CONFIGURE_ARGS+=	--disable-t1lib
. endif
.else
CONFIGURE_ARGS+=	--disable-dvi
PLIST_SUB+=		DVI="@comment "
.endif

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=		nautilus3
CONFIGURE_ARGS+=	--enable-nautilus
PLIST_SUB+=		NAUTILUS=""
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
RUN_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
.if ${PORT_OPTIONS:MKEYRING}
LIB_DEPENDS+=	libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
.else
CONFIGURE_ARGS+=	--without-keyring
.endif
CONFIGURE_ARGS+=	--disable-nautilus
PLIST_SUB+=		NAUTILUS="@comment "
.endif

.if ${PORT_OPTIONS:MIMPRESS}
CONFIGURE_ARGS+=	--enable-impress
PLIST_SUB+=		IMPRESS=""
.else
CONFIGURE_ARGS+=	--disable-impress
PLIST_SUB+=		IMPRESS="@comment "
.endif

.if ${PORT_OPTIONS:MDJVU}
LIB_DEPENDS+=		libdjvulibre.so:${PORTSDIR}/graphics/djvulibre
CONFIGURE_ARGS+=	--enable-djvu
PLIST_SUB+=		DJVU=""
.else
CONFIGURE_ARGS+=	--disable-djvu
PLIST_SUB+=		DJVU="@comment "
.endif

.if ${PORT_OPTIONS:MCOMICS}
CONFIGURE_ARGS+=	--enable-comics
PLIST_SUB+=		COMICS=""
.else
CONFIGURE_ARGS+=	--disable-comics
PLIST_SUB+=		COMICS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g' \
		-e 's|" == "|" = "|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^DOC_MODULE_VERSION/d' \
		${WRKSRC}/help/reference/libdocument/Makefile.in \
		${WRKSRC}/help/reference/libview/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libevdocument3.so.4
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evince/4/backends/lib*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libevview3.so.3
.if ${PORT_OPTIONS:MNAUTILUS}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nautilus/extensions-3.0/libevince-properties-page.so
.endif

.include <bsd.port.mk>
