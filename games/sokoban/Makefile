# New ports collection makefile for:	sokoban
# Version required:			1.0 
# Date created:				2 July 1997
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		sokoban-src
PKGNAME=		sokoban-1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/sokoban
ALL_TARGET=

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/sokoban ${PREFIX}/bin/sokoban
	@ chown games:bin ${PREFIX}/bin/sokoban
	@ chmod 4555 ${PREFIX}/bin/sokoban
	@ ${MKDIR} ${PREFIX}/share/sokoban
	@ chown games:bin ${PREFIX}/share/sokoban
	@ ${MKDIR} ${PREFIX}/share/sokoban/screens
	@ chown games:bin ${PREFIX}/share/sokoban/screens
	@ ${INSTALL_DATA} ${WRKSRC}/screens/* ${PREFIX}/share/sokoban/screens
	@ if [ ! -f ${PREFIX}/share/sokoban/highscore ]; then \
		dd if=/dev/zero of=${PREFIX}/share/sokoban/highscore bs=1 count=2; \
	  fi
	@ chown games:bin ${PREFIX}/share/sokoban/highscore
	@ chmod 0600 ${PREFIX}/share/sokoban/highscore

.include <bsd.port.mk>
