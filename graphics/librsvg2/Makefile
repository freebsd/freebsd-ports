# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/librsvg2/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	librsvg
PORTVERSION=	2.40.2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libcroco-0.6.so:${PORTSDIR}/textproc/libcroco
RUN_DEPENDS=	gtk-engines2>=2.7.5_1:${PORTSDIR}/x11-themes/gtk-engines2

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehier gnomeprefix libgsf gtk20 introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-svgz \
		--disable-vala \
		--with-croco \
		--disable-Bsymbolic \
		--enable-gtk-theme

post-patch:
	@${REINPLACE_CMD} -e 's|GTK3_REQUIRED=3.[0-9].[0-9]|GTK3_REQUIRED=9.90.0|g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*/*/*/*.so

.include <bsd.port.mk>
