# New ports collection makefile for:   xcubes
# Version required:    V5.4.4
# Date created:        12 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.6 1998/08/25 00:43:47 asami Exp $
#

DISTNAME=	xcubes-5.4.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	nacai@iname.com

WRKSRC=		${WRKDIR}/xcubes
USE_IMAKE=	yes
MAN1=		xcubes.1
MANCOMPRESSED=	no

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xcubes ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/Cubes.ad ${PREFIX}/lib/X11/app-defaults/Cubes
	@${INSTALL_MAN} ${WRKSRC}/xcubes.man ${PREFIX}/man/man1/xcubes.1

.include <bsd.port.mk>
