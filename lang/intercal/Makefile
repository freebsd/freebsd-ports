# New ports collection makefile for:	intercal
# Version required:    0.17
# Date created:        20 March 1998
# Whom:                Matthew Hunt <mph@freebsd.org>
#
# $Id$
#

DISTNAME=	intercal-0.17
CATEGORIES=	lang
MASTER_SITES=	http://earthspace.net/~esr/

MAINTAINER=	mph@freebsd.org

WRKSRC=		$(WRKDIR)/$(DISTNAME)/src

pre-install:
	${MKDIR} ${PREFIX}/share/intercal
	${MKDIR} ${PREFIX}/lib/intercal

post-install:
	${MKDIR} ${PREFIX}/share/intercal/pit
	${CP} -R $(WRKDIR)/$(DISTNAME)/pit/*  ${PREFIX}/share/intercal/pit

.include <bsd.port.mk>
