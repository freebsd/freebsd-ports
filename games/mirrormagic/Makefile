# New ports collection makefile for:	mirrormagic
# Date created:				1 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	mirrormagic
PORTVERSION=	1.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An arcade style game with stereo sound for X Window System

USE_X_PREFIX=	yes
USE_XPM=	yes

post-extract:
.for file in DoubleRayDoor DoubleRayFont DoubleRayFont2 DoubleRayScreen
	@${GUNZIP_CMD} ${WRKSRC}/graphics/${file}.xpm
.endfor
	@(cd ${WRKDIR}; ${CP} ${FILESDIR}/RAY.* .; uudecode *.uu; ${RM} *.uu)

do-install:
	${INSTALL_PROGRAM} -m 2755 -o root -g games ${WRKSRC}/mirrormagic ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/mirrormagic/graphics
	${INSTALL_DATA} ${WRKSRC}/graphics/* ${PREFIX}/share/mirrormagic/graphics
	@${MKDIR} ${PREFIX}/share/mirrormagic/sounds
	${INSTALL_DATA} ${WRKSRC}/sounds/*.8svx ${PREFIX}/share/mirrormagic/sounds
	@${MKDIR} ${PREFIX}/share/mirrormagic/data
	${INSTALL_DATA} ${WRKSRC}/RAY.level ${PREFIX}/share/mirrormagic/data
	${INSTALL_DATA} ${WRKDIR}/RAY.* ${PREFIX}/share/mirrormagic/data
	@${MKDIR} ${PREFIX}/share/doc/mirrormagic
.for file in CHANGES COPYRIGHT DISCLAIMER README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/mirrormagic
.endfor
#	@${CHMOD} 664 ${PREFIX}/share/mirrormagic/data
	@${CHOWN} root:games ${PREFIX}/share/mirrormagic/data/RAY.*
	@${CHMOD} 664 ${PREFIX}/share/mirrormagic/data/RAY.*

.include <bsd.port.mk>
