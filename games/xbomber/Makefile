# New ports collection makefile for:   xbomber
# Date created:        28 June 1998
# Whom:                marcus
#
# $FreeBSD$
#

PORTNAME=	xbomber
PORTVERSION=	0.8
CATEGORIES=     games
MASTER_SITES=   ftp://ftp.sonic.net/pub/users/nbs/unix/x/xbomber/
DISTNAME=       ${PORTNAME}.${PORTVERSION}

MAINTAINER=     jclarke@cisco.com

USE_X_PREFIX=	yes
WRKSRC=         ${WRKDIR}/xbomber
MAKEFILE=	makefile

do-install:
	${MKDIR} ${PREFIX}/lib/xbomber/
	${INSTALL_PROGRAM} ${WRKSRC}/xbomber ${PREFIX}/lib/xbomber/

	${MKDIR} ${PREFIX}/lib/xbomber/bitmaps/
	${INSTALL_DATA} ${WRKSRC}/bitmaps/* ${PREFIX}/lib/xbomber/bitmaps/

	${MKDIR} ${PREFIX}/lib/xbomber/jungle/
	${INSTALL_DATA} ${WRKSRC}/jungle/* ${PREFIX}/lib/xbomber/jungle/

	${MKDIR} ${PREFIX}/lib/xbomber/levels/
	${INSTALL_DATA} ${WRKSRC}/levels/* ${PREFIX}/lib/xbomber/levels/

	${MKDIR} ${PREFIX}/lib/xbomber/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${PREFIX}/lib/xbomber/pixmaps/

	${MKDIR} ${PREFIX}/lib/xbomber/sounds/
	${MKDIR} ${PREFIX}/lib/xbomber/sounds/numbers/
	${INSTALL_DATA} ${WRKSRC}/sounds/*.au ${PREFIX}/lib/xbomber/sounds/
	${INSTALL_DATA} ${WRKSRC}/sounds/numbers/*.au ${PREFIX}/lib/xbomber/sounds/numbers/
	${MKDIR} ${PREFIX}/share/xbomber/
.for file in README.txt LEVELS.txt SOUND.txt GRAPHICS.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/xbomber/
.endfor

	${MKDIR} ${PREFIX}/bin; \
	${ECHO} "#!/bin/sh" > ${PREFIX}/bin/xbomber; \
	${ECHO} "cd ${PREFIX}/lib/xbomber" >> ${PREFIX}/bin/xbomber; \
	${CAT} ${SCRIPTDIR}/xbomber.sh >> ${PREFIX}/bin/xbomber; \
	${CHMOD} 0755 ${PREFIX}/bin/xbomber

.include <bsd.port.mk>
