# New ports collection Makefile for: aview
# Version required:     1.2
# Date created:         Dec 18 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $Id: Makefile,v 1.3 1998/09/22 16:19:12 asami Exp $
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
