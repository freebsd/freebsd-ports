# New ports collection Makefile for: aview
# Version required:     1.2
# Date created:         Dec 18 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

DISTNAME=       aview-1.2
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.ta.jcu.cz/pub/aa/

MAINTAINER=     frankch@waru.life.nthu.edu.tw

RUN_DEPENDS=	anytopnm:${PORTSDIR}/graphics/netpbm \
		convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	aa.1:${PORTSDIR}/graphics/aalib

GNU_CONFIGURE=	YES

.include <bsd.port.mk>
