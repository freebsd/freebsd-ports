# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/svg2png/Makefile,v 1.3 2005/08/06 02:21:48 marcus Exp $

PORTNAME=	svg2png
PORTVERSION=	0.1.3
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Render an SVG image to a PNG image (using cairo)

LIB_DEPENDS=	libsvg-cairo.so:graphics/libsvg-cairo

GNU_CONFIGURE=	yes
USES=		pkgconfig

LDFLAGS+=	/usr/lib/libm.so # Was labeled broken when ${/usr/bin/ld:L:tA}==/usr/bin/ld.lld: ld: error: /usr/local/lib/libsvg-cairo.so: undefined reference to atan2

PLIST_FILES=	bin/svg2png \
		man/man1/svg2png.1.gz

.include <bsd.port.mk>
