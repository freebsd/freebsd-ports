# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evince
PORTVERSION=	3.18.2
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	GNOME 3 multi-format document viewer

BUILD_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		itstool:textproc/itstool \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libspectre.so:print/libspectre
RUN_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even
SLAVEPORT?=	no

USES=		compiler:c++11-lib desktop-file-utils gettext gmake \
		gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_XORG=	ice
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-format-nonliteral
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.if ${SLAVEPORT} == lite
CONFIGURE_ARGS+=--disable-introspection \
		--disable-libgnome-desktop \
		--disable-thumbnailer \
		--disable-previewer
.else
USE_GNOME+=	introspection:build
CONFIGURE_ARGS+=	--enable-introspection
.endif

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml

PLIST_SUB=	VERSION=3.0

OPTIONS_DEFINE=	COMICS DJVU DVI KEYRING NAUTILUS T1LIB XPS
OPTIONS_DEFAULT=COMICS DJVU KEYRING NAUTILUS XPS
DVI_DESC=	DVI viewer support
T1LIB_DESC=	T1LIB for TYPE1 fonts to DVI (Enables DVI)
NAUTILUS_DESC=	Nautilus plugin
KEYRING_DESC=	Keyring support
COMICS_DESC=	Comic book archives support
DJVU_DESC=	DJVU support
XPS_DESC=	XPS support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:NDBUS} && ${SLAVEPORT} == lite
CONFIGURE_ARGS+=--disable-dbus
.else
CONFIGURE_ARGS+=--enable-dbus
.endif

.if ${PORT_OPTIONS:MDVI} || ${PORT_OPTIONS:MT1LIB}
USE_TEX=	latex

CONFIGURE_ARGS+=	--enable-dvi
PLIST_SUB+=		DVI=""
. if ${PORT_OPTIONS:MT1LIB}
LIB_DEPENDS+=	libt1.so:devel/t1lib
CONFIGURE_ARGS+=	--enable-t1lib
. else
CONFIGURE_ARGS+=	--disable-t1lib
. endif
.else
CONFIGURE_ARGS+=	--disable-dvi
PLIST_SUB+=		DVI="@comment "
.endif

.if ${PORT_OPTIONS:MKEYRING}
LIB_DEPENDS+=	libsecret-1.so:security/libsecret
.else
CONFIGURE_ARGS+=--without-keyring
.endif

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=		nautilus3
CONFIGURE_ARGS+=	--enable-nautilus
PLIST_SUB+=		NAUTILUS=""
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:misc/gnome-icon-theme
RUN_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:misc/gnome-icon-theme
CONFIGURE_ARGS+=	--disable-nautilus
PLIST_SUB+=		NAUTILUS="@comment "
.endif

.if ${PORT_OPTIONS:MXPS}
LIB_DEPENDS+=		libgxps.so:graphics/libgxps
CONFIGURE_ARGS+=	--enable-xps
PLIST_SUB+=		XPS=""
.else
CONFIGURE_ARGS+=	--disable-xps
PLIST_SUB+=		XPS="@comment "
.endif

.if ${PORT_OPTIONS:MDJVU}
LIB_DEPENDS+=		libdjvulibre.so:graphics/djvulibre
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
