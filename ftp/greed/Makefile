# New ports collection makefile for: 	greed
# Version required:	0.801
# Date created:		13 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id: Makefile,v 1.9 1999/06/19 08:25:44 cpiazza Exp $
#

DISTNAME=	greed-0.801
CATEGORIES=	ftp
MASTER_SITES=	http://www.public.asu.edu/~arturner/greed/

MAINTAINER=	cpiazza@FreeBSD.org

MANCOMPRESSED=	yes
MAN1=		greed.1

ALL_TARGET=	freebsd
WRKSRC=		${WRKDIR}/greed

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/greed.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
