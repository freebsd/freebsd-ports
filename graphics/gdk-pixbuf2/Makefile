# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/gdk-pixbuf2/Makefile 18692 2013-09-22 00:45:30Z kwm $

PORTNAME=	gdk-pixbuf
PORTVERSION=	2.28.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphic library for GTK+

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
LIB_DEPENDS+=	libjasper.so:${PORTSDIR}/graphics/jasper
CONFIGURE_ARGS+=--with-libjasper
PLIST_SUB+=	JP2=""
.else
PLIST_SUB+=	JP2="@comment "
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=--without-libjpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=--without-libpng
PLIST_SUB+=	PNG="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	libtiff.so:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=--without-libtiff
PLIST_SUB+=	TIFF="@comment "
.endif

post-install:
	@cd ${WRKSRC}/docs/reference/gdk-pixbuf && env DESTDIR=${STAGEDIR} ${GMAKE} install-man1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdk_pixbuf*-2.0.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gdk-pixbuf-2.0/${GTK2_VERSION}/loaders/lib*.so

.include <bsd.port.mk>
