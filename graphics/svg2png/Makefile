# New ports collection makefile for:	svg2png
# Date created:		2005-03-10
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	svg2png
PORTVERSION=	0.1.2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Render an SVG image to a PNG image (using cairo)

LIB_DEPENDS=	svg-cairo.1:${PORTSDIR}/graphics/libsvg-cairo

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes

MAN1=		svg2png.1
PLIST_FILES=	bin/svg2png

.include <bsd.port.mk>
