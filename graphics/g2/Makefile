# New ports collection makefile for:	g2
# Date created:	16 July 1998
# Whom:		Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	g2
PORTVERSION=	0.40
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An easy to use, portable and powerful 2D graphics library

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

do-build:
	cd ${WRKSRC} ; make depend ; make

.include <bsd.port.mk>
