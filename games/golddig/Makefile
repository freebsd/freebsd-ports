# New ports collection makefile for:    golddig
# Version required:     2
# Date created:         20 November 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	golddig2
PKGNAME=	golddig-2.0
CATEGORIES+=	games
MASTER_SITES=	ftp://qiclab.scn.rain.com/pub/games/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

pre-patch:
	@(cd ${WRKSRC}; for i in 245 244 246 247; do \
	    awk '{if (/^#!/) x++} {if(x) print $$0'} $$i| /bin/sh; \
	  done; mv golddig2/* .)

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib/golddig
	@mkdir -p ${PREFIX}/man/man6

.include <bsd.port.mk>
