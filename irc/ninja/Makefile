# New ports collection makefile for: 	Ninja-irc
# Version required: 	1.0.9
# Date created:	 	10 April 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.2 1999/04/21 00:33:34 mharo Exp $
#

DISTNAME= 	ninja-src
PKGNAME=	ninja-1.0.9
CATEGORIES=	net
MASTER_SITES=	http://ninja.pimped.org/

MAINTAINER=	cpiazza@home.net

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

post-patch:
	@${SED} -e s#__PREFIX__#$(PREFIX)#g $(WRKSRC)/include/config.h.dist > $(WRKSRC)/include/config.h.dist.new
	@${MV} $(WRKSRC)/include/config.h.dist.new $(WRKSRC)/include/config.h.dist

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/ninja ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/wserv ${PREFIX}/bin

.include <bsd.port.mk>
