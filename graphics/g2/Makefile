# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	g2
PORTVERSION=	0.40
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use, portable, and powerful 2D graphics library

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

USE_XORG=	x11
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
do-build:
	cd ${WRKSRC} ; make depend ; make

.include <bsd.port.mk>
