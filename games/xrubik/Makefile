# New ports collection makefile for:   xrubik
# Version required:	5.4.4
# Date created:		20 October 1996
# Whom:			Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.9 1998/08/25 00:44:14 asami Exp $
#

DISTNAME=	xrubik-5.4.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	nacai@iname.com

WRKSRC=		${WRKDIR}/xrubik
USE_IMAKE=	yes
MAN1=		xrubik.1
MANCOMPRESSED=	no

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrubik ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Rubik.ad ${PREFIX}/lib/X11/app-defaults/Rubik
	${INSTALL_MAN} ${WRKSRC}/xrubik.man ${PREFIX}/man/man1/xrubik.1

.include <bsd.port.mk>
