# New ports collection makefile for:	intercal
# Date created:        20 March 1998
# Whom:                Matthew Hunt <mph@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	intercal
PORTVERSION=	0.20
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	mph@freebsd.org
COMMENT=	The C-INTERCAL compiler, ick, and supporting libraries

WRKSRC=		$(WRKDIR)/$(DISTNAME)/src

pre-install:
	${MKDIR} ${PREFIX}/share/intercal
	${MKDIR} ${PREFIX}/lib/intercal

post-install:
	${MKDIR} ${PREFIX}/share/intercal/pit
	${CP} -R $(WRKDIR)/$(DISTNAME)/pit/*  ${PREFIX}/share/intercal/pit

.include <bsd.port.mk>
