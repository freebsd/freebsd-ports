# New ports collection makefile for:	pgplot
# Version required:     5.1
# Date created:		21 December 1996
# Whom:			jmz
#
# $Id$
#

DISTNAME=       pgplot5.1
CATEGORIES=     graphics
MASTER_SITES=   ftp://astro.caltech.edu/pub/pgplot/

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/pgplot

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
