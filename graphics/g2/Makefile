# New ports collection makefile for:	g2
# Version required:	0.23
# Date created:	16 July 1998
# Whom:		Bill Fumerola <billf@chc-chimes.com>
#
# $Id$
#

DISTNAME=	g2-0.23
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	billf@chc-chimes.com

BUILD_DEPENDS=  ${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

USE_AUTOCONF=	yes

do-build:
	cd ${WRKSRC} ; make depend ; make

.include <bsd.port.mk>
