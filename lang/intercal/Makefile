# New ports collection makefile for:	intercal
# Version required:    0.18
# Date created:        20 March 1998
# Whom:                Matthew Hunt <mph@freebsd.org>
#
# $Id: Makefile,v 1.1.1.1 1998/04/17 21:52:16 mph Exp $
#

DISTNAME=	intercal-0.18
CATEGORIES=	lang
MASTER_SITES=	http://www.tuxedo.org/~esr/intercal/

MAINTAINER=	mph@freebsd.org

WRKSRC=		$(WRKDIR)/$(DISTNAME)/src

pre-install:
	${MKDIR} ${PREFIX}/share/intercal
	${MKDIR} ${PREFIX}/lib/intercal

post-install:
	${MKDIR} ${PREFIX}/share/intercal/pit
	${CP} -R $(WRKDIR)/$(DISTNAME)/pit/*  ${PREFIX}/share/intercal/pit

.include <bsd.port.mk>
