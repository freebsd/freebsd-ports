# New ports collection makefile for:	g2
# Version required:	0.40
# Date created:	16 July 1998
# Whom:		Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

DISTNAME=	g2-0.40
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	billf@FreeBSD.org

BUILD_DEPENDS=  ${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CFLAGS="${CFLAGS} -I${PREFIX}/include/gd"

do-build:
	cd ${WRKSRC} ; make depend ; make

.include <bsd.port.mk>
