# New ports collection makefile for:	ftpsearch
# Version required:	
# Date created:		07 Dec 1996
# Whom:			tegge@idt.ntnu.no
#
# $Id$
#

DISTNAME=	ftpsearch-19961208
CATEGORIES=	net
MASTER_SITES=	ftp://ftpsearch.ntnu.no/pub/ftpsearch/

MAINTAINER=	tegge@idt.ntnu.no

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	FTPSEARCHROOT=$(PREFIX)/ftpsearch

post-install:
	cp $(PREFIX)/ftpsearch/bin/gateway $(PREFIX)/bin/ftpsearch

.include <bsd.port.mk>
