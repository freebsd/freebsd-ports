# New ports collection makefile for: 	Ninja-irc
# Version required: 	1.1
# Date created:	 	10 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id: Makefile,v 1.6 1999/06/28 02:20:50 billf Exp $
#

DISTNAME= 	ninja-1.1-src
PKGNAME=	ninja-1.1
CATEGORIES=	irc
MASTER_SITES=	http://ninja.pimped.org/ftp/unstable/ \
		ftp://ninja.qoop.org/unstable/

MAINTAINER=	cpiazza@FreeBSD.org

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

pre-patch:
	@${CP} ${WRKSRC}/config/configure ${WRKSRC}

post-patch:
	@${SED} -e s#__PREFIX__#$(PREFIX)#g $(WRKSRC)/include/config.h.dist > $(WRKSRC)/include/config.h.dist.new
	@${MV} $(WRKSRC)/include/config.h.dist.new $(WRKSRC)/include/config.h.dist

.include <bsd.port.mk>
