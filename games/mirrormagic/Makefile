# New ports collection makefile for:	mirrormagic
# Version required:			1.3
# Date created:				1 April 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		mirrormagic-1.3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=		yes

pre-build:
.for file in DoubleRayDoor DoubleRayFont DoubleRayFont2 DoubleRayScreen
	@ ${GUNZIP_CMD} ${WRKSRC}/graphics/${file}.xpm
.endfor
	@ (cd ${WRKDIR}; ${CP} ${FILESDIR}/RAY.* .; uudecode *.uu; ${RM} *.uu)

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/mirrormagic ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/mirrormagic/graphics
	@ ${INSTALL_DATA} ${WRKSRC}/graphics/* ${PREFIX}/share/mirrormagic/graphics
	@ ${MKDIR} ${PREFIX}/share/mirrormagic/sounds
	@ ${INSTALL_DATA} ${WRKSRC}/sounds/*.8svx ${PREFIX}/share/mirrormagic/sounds
	@ ${MKDIR} ${PREFIX}/share/mirrormagic/data
	@ ${INSTALL_DATA} ${WRKSRC}/RAY.level ${PREFIX}/share/mirrormagic/data
	@ ${INSTALL_DATA} ${WRKDIR}/RAY.* ${PREFIX}/share/mirrormagic/data
	@ ${MKDIR} ${PREFIX}/share/doc/mirrormagic
.for file in CHANGES COPYRIGHT DISCLAIMER README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/mirrormagic
.endfor
#	@ chmod a=rwx ${PREFIX}/share/mirrormagic/data
	@ chmod a=rw  ${PREFIX}/share/mirrormagic/data/RAY.*

.include <bsd.port.mk>
