# New ports collection makefile for:	agm
# Version required:			1.1
# Date created:				4 July 1997
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		agm-1.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/amusements

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}
MAN6=			agm.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/agm ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/agm.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
