# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librsvg
PORTVERSION=	2.40.17
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

PORTSCOUT=	limit:^2\.40\.

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libcroco-0.6.so:textproc/libcroco

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gnomeprefix libgsf gdkpixbuf2 introspection:build \
		libxml2 pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-vala \
		--disable-Bsymbolic

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|GTK3_REQUIRED=3.[0-9][0-9].[0-9]|GTK3_REQUIRED=9.90.0|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
