# New ports collection makefile for: 	greed
# Version required:	0.81+
# Date created:		13 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	greed.81p
PKGNAME=	greed-0.81p
CATEGORIES=	ftp www
MASTER_SITES=	http://www.public.asu.edu/~arturner/greed/

MAINTAINER=	cpiazza@FreeBSD.org

ALL_TARGET=	freebsd
WRKSRC=		${WRKDIR}/greed.81p

MANCOMPRESSED=	yes
MAN1=		greed.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/greed.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
