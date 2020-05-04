# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	g2
PORTVERSION=	0.40
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/libs/graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use, portable, and powerful 2D graphics library

LIB_DEPENDS=	libgd.so:graphics/gd

USES=		xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -E 's,(INC|LIB)DIR),DESTDIR)$$(&,g' \
		${WRKSRC}/Makefile.in

do-build:
	cd ${WRKSRC} ; make depend ; make

.include <bsd.port.mk>
