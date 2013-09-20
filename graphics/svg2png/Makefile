# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/svg2png/Makefile,v 1.3 2005/08/06 02:21:48 marcus Exp $

PORTNAME=	svg2png
PORTVERSION=	0.1.3
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Render an SVG image to a PNG image (using cairo)

LIB_DEPENDS=	svg-cairo.1:${PORTSDIR}/graphics/libsvg-cairo

GNU_CONFIGURE=	yes
USES=		pkgconfig

MAN1=		svg2png.1
PLIST_FILES=	bin/svg2png

NO_STAGE=	yes
.include <bsd.port.mk>
