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
MAN6=		scavenger.6

post-extract:
	(cd ${WRKSRC}; ${CP} scavenger.6 scavenger.man)

.include <bsd.port.mk>
