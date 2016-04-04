# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/svg2pdf/Makefile,v 1.2 2005/08/08 02:09:09 marcus Exp $

PORTNAME=	svg2pdf
PORTVERSION=	0.1.3
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Render an SVG image to a PDF file (using cairo)

LIB_DEPENDS=	libsvg-cairo.so:graphics/libsvg-cairo

GNU_CONFIGURE=	yes
USES=		pkgconfig

PLIST_FILES=	bin/svg2pdf \
		man/man1/svg2pdf.1.gz

.include <bsd.port.mk>
