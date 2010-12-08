# New ports collection makefile for: flam3
# Date created:  21 Mar 2010
# Whom:          John Prather
#
# $FreeBSD$
#

PORTNAME=	flam3
PORTVERSION=	2.7.18
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://flam3.com/ \
		http://interwebfun.org/distfiles/

MAINTAINER=	john.c.prather@gmail.com
COMMENT=	A Flame Renderer

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg

MAN1=		flam3-animate.1 flam3-genome.1 flam3-render.1 flam3-convert.1
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes
USE_GZIP=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack

CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
