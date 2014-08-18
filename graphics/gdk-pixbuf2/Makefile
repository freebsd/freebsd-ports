# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/gdk-pixbuf2/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	gdk-pixbuf
PORTVERSION=	2.30.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphic library for GTK+

USE_XORG=	xt xi x11
USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME+=	gnomehier glib20 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-introspection=yes --with-x11
INSTALL_TARGET=	install-strip

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

.include <bsd.port.mk>
