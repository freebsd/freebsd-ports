# New ports collection makefile for:	Hex
# Version required:	0.0.2
# Date created:		9 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	hex-0.0.2
CATEGORIES=	games
MASTER_SITES=	http://www.nott.ac.uk/~psystrj/ \
		http://www.psn.net/~andrews/dist/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	YES

USE_GMAKE=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}

pre-install:
	@${MKDIR} ${PREFIX}/share/hex
	@${MKDIR} ${PREFIX}/share/hex/levels
	@${MKDIR} ${PREFIX}/share/hex/graphics

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/hex ${PREFIX}/bin/hex
	@${INSTALL_DATA} ${WRKSRC}/HISTORY ${PREFIX}/share/hex/HISTORY
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/hex/README
	@${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/hex/TODO
.for i in 0 1 2 3 4 5 6 7 8
	@${INSTALL_DATA} ${WRKSRC}/graphics/ball${i}.png \
			 ${PREFIX}/share/hex/graphics/ball${i}.png
.endfor
	@${INSTALL_DATA} ${WRKSRC}/levels/Level1 \
			 ${PREFIX}/share/hex/levels/Level1

.include <bsd.port.mk>
