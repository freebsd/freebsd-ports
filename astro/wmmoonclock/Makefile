# New ports collection makefile for:   wmMoonClock
# Version required:    1.24
# Date created:        14 March 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id$
#

DISTNAME=	wmMoonClock-1.24
CATEGORIES=	astro windowmaker
MASTER_SITES=	ftp://leadbelly.lanl.gov/pub/mgh/

MAINTAINER=	kris@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm/

WRKSRC=		${WRKDIR}/${PKGNAME}/wmMoonClock

USE_X_PREFIX=	yes
USE_XLIB=	yes
USE_GMAKE=	yes

ALL_TARGET=	clean all

MAN1=		wmmoonclock.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/wmMoonClock.1 ${PREFIX}/share/man/man1/wmmoonclock.1
	${INSTALL_PROGRAM} ${WRKSRC}/wmMoonClock ${PREFIX}/bin/wmmoonclock

.include <bsd.port.mk>
