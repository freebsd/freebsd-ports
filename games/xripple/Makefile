# new ports collection makefile for:	xripple
# Version:				1.0 <no version #>
# Date created:				6 Oct 1996
# Whom:					oly
#
# $Id: Makefile,v 1.3 1996/11/18 11:26:48 asami Exp $
#

DISTNAME=	xripple
PKGNAME=	xripple-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://www.cse.unsw.edu.au/pub/users/s2154962/

MAINTAINER=	oly@world.std.com

USE_IMAKE=	yes
ALL_TARGET=	xripple

post-configure:
	cd ${WRKSRC}; make clean

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xripple ${PREFIX}/bin

.include <bsd.port.mk>
