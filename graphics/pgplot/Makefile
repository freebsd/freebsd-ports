# New ports collection makefile for:	pgplot
# Version required:     5.1
# Date created:		21 December 1996
# Whom:			jmz
#
# $Id: Makefile,v 1.2 1997/01/05 12:39:15 asami Exp $
#

DISTNAME=       pgplot5.1
PKGNAME=        pgplot-5.1
CATEGORIES=     graphics
MASTER_SITES=   ftp://astro.caltech.edu/pub/pgplot/

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/pgplot

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
