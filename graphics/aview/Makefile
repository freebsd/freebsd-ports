# New ports collection Makefile for: aview
# Version required:     1.2
# Date created:         Dec 18 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $Id: Makefile,v 1.1.1.1 1997/12/24 07:39:24 vanilla Exp $
#

DISTNAME=       aview-1.2
CATEGORIES=     graphics x11
MASTER_SITES=   ftp://ftp.ta.jcu.cz/pub/aa/

MAINTAINER=     frankch@waru.life.nthu.edu.tw

RUN_DEPENDS=	anytopnm:${PORTSDIR}/graphics/netpbm \
		convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	aa\\.1\\.:${PORTSDIR}/graphics/aalib

GNU_CONFIGURE=	YES

.include <bsd.port.mk>
