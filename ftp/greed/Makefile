# New ports collection makefile for: 	greed
# Version required:	0.8
# Date created:		13 April 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.5 1999/05/01 02:12:32 steve Exp $
#

DISTNAME=	greed-0.8
CATEGORIES=	net
MASTER_SITES=	http://www.public.asu.edu/~arturner/

MAINTAINER=	cpiazza@home.net

MANCOMPRESSED=	yes
MAN1=		greed.1

ALL_TARGET=	freebsd
WRKSRC=		${WRKDIR}/greed

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/greed.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
