# New ports collection makefile for:	ftpsearch
# Version required:	
# Date created:		07 Dec 1996
# Whom:			tegge@idt.ntnu.no
#
# $Id: Makefile,v 1.2 1997/02/18 10:08:23 obrien Exp $
#

DISTNAME=	ftpsearch-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftpsearch.ntnu.no/pub/ftpsearch/

MAINTAINER=	tegge@idt.ntnu.no

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	FTPSEARCHROOT=${PREFIX}/ftpsearch

post-install:
	ln -sf ${PREFIX}/ftpsearch/bin/gateway ${PREFIX}/bin/ftpsearch

.include <bsd.port.mk>
