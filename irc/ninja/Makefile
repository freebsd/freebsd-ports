# New ports collection makefile for: 	Ninja-irc
# Version required: 	1.1
# Date created:	 	10 April 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.3 1999/05/16 23:44:01 steve Exp $
#

DISTNAME= 	ninja-src
PKGNAME=	ninja-1.1
CATEGORIES=	net
MASTER_SITES=	http://ninja.pimped.org/

MAINTAINER=	cpiazza@home.net

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

pre-patch:
	@${CP} ${WRKSRC}/config/configure ${WRKSRC}

post-patch:
	@${SED} -e s#__PREFIX__#$(PREFIX)#g $(WRKSRC)/include/config.h.dist > $(WRKSRC)/include/config.h.dist.new
	@${MV} $(WRKSRC)/include/config.h.dist.new $(WRKSRC)/include/config.h.dist

.include <bsd.port.mk>
