# New ports collection makefile for:	pgplot
# Version required:     5.1
# Date created:		21 December 1996
# Whom:			jmz
#
# $Id: Makefile,v 1.1.1.1 1996/12/22 04:36:42 jmz Exp $
#

DISTNAME=       pgplot5.1
PKGNAME=        pgplot-5.1
CATEGORIES=     graphics
MASTER_SITES=   ftp://astro.caltech.edu/pub/pgplot/

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/pgplot

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
