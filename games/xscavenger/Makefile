# New ports collection makefile for:	xscavenger
# Date created:		19 Feb 1998
# Whom:			eivind
#
# $FreeBSD$
#

PORTNAME=	xscavenger
PORTVERSION=	1.3.5
CATEGORIES=	games
MASTER_SITES=	http://www.xdr.com/dash/
DISTNAME=	xscavenger-135
EXTRACT_SUFX=	.tgz

MAINTAINER=	eivind@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=yes
MAN6=		scavenger.6

post-install:
	@${INSTALL_MAN} ${WRKSRC}/scavenger.6 ${PREFIX}/man/man6/scavenger.6

.include <bsd.port.mk>
