# new ports collection makefile for:	xripple
# Version:				1.0 <no version #>
# Date created:				6 Oct 1996
# Whom:					oly
#
# $Id$
#

DISTNAME=	xripple
PKGNAME=	xripple-1.0
MASTER_SITES=	ftp://www.cse.unsw.edu.au/pub/users/s2154962/
CATEGORIES+=	games

MAINTAINER=	oly@world.std.com

USE_IMAKE=	yes
ALL_TARGET=

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xripple ${PREFIX}/bin

.include <bsd.port.mk>
