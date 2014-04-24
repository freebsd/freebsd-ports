# Created by: John Prather
# $FreeBSD$

PORTNAME=	flam3
PORTVERSION=	2.7.18
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://flam3.com/ \
		http://interwebfun.org/distfiles/

MAINTAINER=	john.c.prather@gmail.com
COMMENT=	A Flame Renderer

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig

CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${LOCALBASE}/include/libpng15 -I${LOCALBASE}/include

.include <bsd.port.mk>
