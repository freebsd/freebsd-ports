# New ports collection makefile for:   wmMoonClock
# Version required:    1.25
# Date created:        14 March 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id: Makefile,v 1.2 1999/04/19 13:56:27 kris Exp $
#

DISTNAME=	wmMoonClock-1.25
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	kris@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm/

WRKSRC=		${WRKDIR}/${PKGNAME}/Src

USE_X_PREFIX=	yes
USE_GMAKE=	yes

ALL_TARGET=	clean all

MAN1=		wmmoonclock.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/wmMoonClock.1 ${PREFIX}/man/man1/wmmoonclock.1
	${INSTALL_PROGRAM} ${WRKSRC}/wmMoonClock ${PREFIX}/bin/wmmoonclock

.include <bsd.port.mk>
