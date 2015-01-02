# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/librsvg2/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	librsvg
PORTVERSION=	2.40.6
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libcroco-0.6.so:${PORTSDIR}/textproc/libcroco
RUN_DEPENDS=	gtk-engines2>=2.7.5_1:${PORTSDIR}/x11-themes/gtk-engines2

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix libgsf gtk20 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-svgz \
		--disable-vala \
		--with-croco \
		--disable-Bsymbolic \
		--enable-gtk-theme

post-patch:
	@${REINPLACE_CMD} -e 's|GTK3_REQUIRED=3.[0-9].[0-9]|GTK3_REQUIRED=9.90.0|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
