# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/gdk-pixbuf2/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	gdk-pixbuf
PORTVERSION=	2.31.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphic library for GTK+

LICENSE=	LGPL20 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XORG=	xt xi x11
USES=		cpe gmake libtool pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME+=	glib20 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-introspection=yes --with-x11
INSTALL_TARGET=	install-strip

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	JASPER JPEG PNG TIFF
OPTIONS_DEFAULT=JASPER JPEG PNG TIFF
JASPER_CONFIGURE_WITH=	libjasper
JASPER_LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper
JPEG_CONFIGURE_WITH=	libjpeg
JPEG_USES=		jpeg
PNG_CONFIGURE_WITH=	libpng
PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
TIFF_CONFIGURE_WITH=	libtiff
TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@cd ${WRKSRC}/docs/reference/gdk-pixbuf && env DESTDIR=${STAGEDIR} ${GMAKE} install-man1

.include <bsd.port.mk>
