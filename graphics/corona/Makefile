# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	corona
PORTVERSION=	1.0.2
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics library that supports most image formats

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USES=		libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
