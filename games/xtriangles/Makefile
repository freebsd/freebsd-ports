# New ports collection makefile for:   xtriangles
# Version required:    5.4.4
# Date created:        12 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.6 1998/08/25 00:44:17 asami Exp $
#

DISTNAME=	xtriangles-5.4.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	nacai@iname.com

WRKSRC=		${WRKDIR}/xtriangles
USE_IMAKE=	yes
MAN1=		xtriangles.1
MANCOMPRESSED=	no

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xtriangles ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/Triangles.ad \
		${PREFIX}/lib/X11/app-defaults/Triangles
	@${INSTALL_MAN} ${WRKSRC}/xtriangles.man ${PREFIX}/man/man1/xtriangles.1

.include <bsd.port.mk>
