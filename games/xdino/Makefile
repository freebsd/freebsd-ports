# New ports collection makefile for:   xdino
# Version required:    5.4.4
# Date created:        12 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.6 1998/08/25 00:43:52 asami Exp $
#

DISTNAME=	xdino-5.4.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	nacai@iname.com

WRKSRC=		${WRKDIR}/xdino
USE_IMAKE=	yes
MAN1=		xdino.1
MANCOMPRESSED=	no

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xdino ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/Dino.ad ${PREFIX}/lib/X11/app-defaults/Dino
	@${INSTALL_MAN} ${WRKSRC}/xdino.man ${PREFIX}/man/man1/xdino.1

.include <bsd.port.mk>
