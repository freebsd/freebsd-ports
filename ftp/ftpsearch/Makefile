# New ports collection makefile for:	ftpsearch
# Version required:	
# Date created:		07 Dec 1996
# Whom:			tegge@idt.ntnu.no
#
# $Id: Makefile,v 1.1.1.1 1997/02/17 10:43:00 tg Exp $
#

DISTNAME=	ftpsearch-19961208
CATEGORIES=	net
MASTER_SITES=	ftp://ftpsearch.ntnu.no/pub/ftpsearch/

MAINTAINER=	tegge@idt.ntnu.no

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	FTPSEARCHROOT=${PREFIX}/ftpsearch

post-install:
	${CP} ${PREFIX}/ftpsearch/bin/gateway ${PREFIX}/bin/ftpsearch

.include <bsd.port.mk>
