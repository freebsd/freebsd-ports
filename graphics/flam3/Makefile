# Created by: John Prather
# $FreeBSD$

PORTNAME=	flam3
PORTVERSION=	2.7.18
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://flam3.com/ \
		http://interwebfun.org/distfiles/

MAINTAINER=	john.c.prather@gmail.com
COMMENT=	Flame Renderer

LIB_DEPENDS=	libpng.so:graphics/png \
		libxml2.so:textproc/libxml2

GNU_CONFIGURE=	yes
USES=		gmake jpeg libtool pathfix pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.mk>
