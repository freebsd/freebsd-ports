# New ports collection makefile for:	ztrack
# Version required:			1.0
# Date created:				1 May 1997
# Whom: Andrey Zakhvatov <andy@icc.surw.chel.su>
#
# $FreeBSD$
#

DISTNAME=	ztrack-1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/ztrack
ALL_TARGET=	ztrack
MAN6=		ztrack.6

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ztrack ${PREFIX}/bin/ztrack
	@${INSTALL_MAN} ${WRKSRC}/ztrack.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
