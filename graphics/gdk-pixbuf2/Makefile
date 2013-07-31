# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/gdk-pixbuf2/Makefile 18634 2013-07-26 10:42:35Z kwm $

PORTNAME=	gdk-pixbuf
PORTVERSION=	2.28.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphic library for GTK+

LATEST_LINK=	gdk-pixbuf2
USE_XZ=		yes
USE_XORG=	xt xi x11
USE_AUTOTOOLS=	libtool
USES=		gmake pathfix pkgconfig
USE_GNOME+=	gnomehier glib20 ltverhack introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-introspection=yes --with-x11

MAN1=		gdk-pixbuf-csource.1 gdk-pixbuf-query-loaders.1

OPTIONS_DEFINE=	JASPER JPEG PNG TIFF
OPTIONS_DEFAULT=JASPER JPEG PNG TIFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MJASPER}
LIB_DEPENDS+=	jasper:${PORTSDIR}/graphics/jasper
CONFIGURE_ARGS+=--with-libjasper
PLIST_SUB+=	JP2=""
.else
PLIST_SUB+=	JP2="@comment "
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=--without-libjpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=--without-libpng
PLIST_SUB+=	PNG="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=--without-libtiff
PLIST_SUB+=	TIFF="@comment "
.endif

post-install:
	@cd ${WRKSRC}/docs/reference/gdk-pixbuf && ${GMAKE} install-man1

.include <bsd.port.mk>
