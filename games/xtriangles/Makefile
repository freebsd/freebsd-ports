# New ports collection makefile for:   xtriangles
# Version required:    5.4.1
# Date created:        12 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.3 1997/06/13 17:47:24 max Exp $
#

DISTNAME=        xtriangles-5.4.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

WRKSRC=		${WRKDIR}/xtriangles
USE_IMAKE=	yes
MAN1=		xtriangles.1

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xtriangles ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/Triangles.ad \
		${PREFIX}/lib/X11/app-defaults/Triangles
	@${INSTALL_MAN} ${WRKSRC}/xtriangles.man ${PREFIX}/man/man1/xtriangles.1

.include <bsd.port.mk>
