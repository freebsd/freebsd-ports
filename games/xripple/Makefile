# new ports collection makefile for:	xripple
# Version:				1.0 <no version #>
# Date created:				6 Oct 1996
# Whom:					oly
#
# $Id: Makefile,v 1.4 1997/06/12 06:08:02 asami Exp $
#

DISTNAME=	xripple
PKGNAME=	xripple-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.easynet.net/pub/X/wm/enlightenment/enlightenment/misc/

MAINTAINER=	oly@world.std.com

USE_IMAKE=	yes
ALL_TARGET=	xripple

post-configure:
	cd ${WRKSRC}; make clean

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xripple ${PREFIX}/bin

.include <bsd.port.mk>
