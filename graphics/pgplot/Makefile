# New ports collection makefile for:	pgplot
# Version required:     5.2
# Date created:		21 December 1996
# Whom:			jmz
#
# $Id: Makefile,v 1.3 1997/07/17 15:12:44 max Exp $
#

DISTNAME=       pgplot5.2
PKGNAME=        pgplot-5.2
CATEGORIES=     graphics
MASTER_SITES=   ftp://astro.caltech.edu/pub/pgplot/

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/pgplot

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
