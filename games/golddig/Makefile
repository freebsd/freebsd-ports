# New ports collection makefile for:    golddig
# Version required:     2
# Date created:         20 November 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.8 1998/11/28 00:44:33 asami Exp $
#

DISTNAME=	golddig2
PKGNAME=	golddig-2.0
CATEGORIES=	games
MASTER_SITES=	ftp://qiclab.scn.rain.com/pub/games/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

USE_XLIB=	yes
MAN6=		golddig.6

pre-patch:
	@(cd ${WRKSRC}; for i in 245 244 246 247; do \
	    ${AWK} '{if (/^#!/) x++} {if(x) print $$0'} $$i| /bin/sh; \
	  done; mv golddig2/* .)

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/golddig
	@${MKDIR} ${PREFIX}/man/man6

.include <bsd.port.mk>
