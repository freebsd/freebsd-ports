# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/evince/Makefile 20078 2014-11-13 09:06:29Z gusi $

PORTNAME=	evince
PORTVERSION=	3.14.1
PORTREVISION=	2
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 multi-format document viewer

BUILD_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		itstool:${PORTSDIR}/textproc/itstool \
		adwaita-icon-theme>=0:${PORTSDIR}/x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
		libspectre.so:${PORTSDIR}/print/libspectre \
		libsecret-1.so:${PORTSDIR}/security/libsecret
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		adwaita-icon-theme>=0:${PORTSDIR}/x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICT_INSTALL=	evince-lite-*

USES=		compiler:c++11-lib desktop-file-utils gettext gmake libtool \
		pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_XORG=	ice
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-format-nonliteral
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-introspection

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml

PLIST_SUB=	VERSION=3.0

OPTIONS_DEFINE=	DVI XPS T1LIB NAUTILUS KEYRING COMICS IMPRESS DJVU
OPTIONS_DEFAULT=NAUTILUS KEYRING COMICS XPS
DVI_DESC=	DVI viewer support
T1LIB_DESC=	T1LIB for TYPE1 fonts to DVI (Enables DVI)
NAUTILUS_DESC=	Nautilus plugin
KEYRING_DESC=	Gnome-Keyring without Nautilus
COMICS_DESC=	Comic book archives support
IMPRESS_DESC=	Impress presentations support
DJVU_DESC=	DJVU support
XPS_DESC=	XPS support

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900000
BROKEN=		Fails to build
.endif

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

.if ${PORT_OPTIONS:MXPS}
LIB_DEPENDS+=		libgxps.so:${PORTSDIR}/graphics/libgxps
CONFIGURE_ARGS+=	--enable-xps
PLIST_SUB+=		XPS=""
.else
CONFIGURE_ARGS+=	--disable-xps
PLIST_SUB+=		XPS="@comment "
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
		-e 's|-Werror||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^DOC_MODULE_VERSION/d' \
		${WRKSRC}/help/reference/libdocument/Makefile.in \
		${WRKSRC}/help/reference/libview/Makefile.in

.include <bsd.port.mk>
