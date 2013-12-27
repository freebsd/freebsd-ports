# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/evince/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	evince
PORTVERSION=	2.32.0
PORTREVISION=	12
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 multi-format document viewer

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		spectre:${PORTSDIR}/print/libspectre
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		yelp:${PORTSDIR}/x11/yelp

CONFLICTS=	evince-3.[0-9]*

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USES=		desktop-file-utils gettext pathfix gmake pkgconfig
USE_GNOME=	intlhack gnomeprefix gnomedocutils ltasneededhack gconf2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml
GCONF_SCHEMAS=	\
		evince-thumbnailer.schemas \
		evince-thumbnailer-ps.schemas

PLIST_SUB+=	VERSION=2.32

MAN1=		evince.1

OPTIONS_DEFINE=	DVI T1LIB NAUTILUS KEYRING COMICS IMPRESS DJVU
OPTIONS_DEFAULT=NAUTILUS KEYRING COMICS
DVI_DESC=	DVI viewer support
T1LIB_DESC=	T1LIB for TYPE1 fonts to DVI (Enables DVI)
NAUTILUS_DESC=	Nautilus plugin
KEYRING_DESC=	Gnome-Keyring without Nautilus
COMICS_DESC=	Comic book archives support
IMPRESS_DESC=	Impress presentations support
DJVU_DESC=	DJVU support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDVI} || ${PORT_OPTIONS:MT1LIB}
USE_TEX=	latex

CONFIGURE_ARGS+=	--enable-dvi
GCONF_SCHEMAS+=	evince-thumbnailer-dvi.schemas
PLIST_SUB+=		DVI=""

. if ${PORT_OPTIONS:MT1LIB}
LIB_DEPENDS+=	t1:${PORTSDIR}/devel/t1lib
CONFIGURE_ARGS+=	--enable-t1lib
. else
CONFIGURE_ARGS+=	--disable-t1lib
. endif

.else
CONFIGURE_ARGS+=	--disable-dvi
PLIST_SUB+=		DVI="@comment "
.endif

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=		nautilus2
CONFIGURE_ARGS+=	--enable-nautilus
PLIST_SUB+=		NAUTILUS=""
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
RUN_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
.if ${PORT_OPTIONS:MKEYRING}
LIB_DEPENDS+=	gnome-keyring:${PORTSDIR}/security/libgnome-keyring
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
LIB_DEPENDS+=		djvulibre:${PORTSDIR}/graphics/djvulibre
CONFIGURE_ARGS+=	--enable-djvu
GCONF_SCHEMAS+=		evince-thumbnailer-djvu.schemas
PLIST_SUB+=		DJVU=""
.else
CONFIGURE_ARGS+=	--disable-djvu
PLIST_SUB+=		DJVU="@comment "
.endif

.if ${PORT_OPTIONS:MCOMICS}
CONFIGURE_ARGS+=	--enable-comics
GCONF_SCHEMAS+=		evince-thumbnailer-comics.schemas
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

.include <bsd.port.mk>
