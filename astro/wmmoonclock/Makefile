# New ports collection makefile for:   wmMoonClock
# Date created:        14 March 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

PORTNAME=	wmMoonClock
PORTVERSION=	1.27
PORTREVISION=	1
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	kris@FreeBSD.org
COMMENT=	Displays the phase of the moon, plus orbital data

WRKSRC=		${WRKDIR}/${DISTNAME}/Src

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes

MAN1=		wmmoonclock.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmMoonClock ${PREFIX}/bin/wmmoonclock
	${INSTALL_MAN} ${WRKSRC}/wmMoonClock.1 ${PREFIX}/man/man1/wmmoonclock.1

.include <bsd.port.mk>
