# New ports collection makefile for: 	greed
# Date created:		13 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	greed
PORTVERSION=	0.81p
CATEGORIES=	ftp www
MASTER_SITES=	http://www.public.asu.edu/~arturner/greed/
DISTNAME=	greed.81p

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	freebsd
WRKSRC=		${WRKDIR}/greed.81p

MANCOMPRESSED=	yes
MAN1=		greed.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/greed.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
