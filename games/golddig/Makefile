# New ports collection makefile for:    golddig
# Version required:     2
# Date created:         20 November 1994
# Whom:                 jmz
#
# $FreeBSD$
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
	  done; ${MV} golddig2/* .)

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/golddig
	@${MKDIR} ${PREFIX}/man/man6

.include <bsd.port.mk>
