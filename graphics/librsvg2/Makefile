# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/librsvg2/Makefile,v 1.147 2012/10/16 08:58:47 kwm Exp $

PORTNAME=	librsvg
PORTVERSION=	2.36.4
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection		
LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		croco-${CROCO_VERSION}.3:${PORTSDIR}/textproc/libcroco
RUN_DEPENDS=	gtk-engines2>=2.7.5_1:${PORTSDIR}/x11-themes/gtk-engines2

USE_XZ=		yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehier gnomeprefix libgsf ltverhack gtk20
USES=		pathfix gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-svgz \
		--with-croco \
		--disable-Bsymbolic \
		--enable-gtk-theme
CROCO_VERSION=	0.6
MAN1=		rsvg-convert.1
MAKE_ENV+=	GI_SCANNER_DISABLE_CACHE=yes

post-patch:
	@${REINPLACE_CMD} -e 's|GTK3_REQUIRED=3.0.0|GTK3_REQUIRED=9.90.0|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
