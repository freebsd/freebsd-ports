# New ports collection makefile for:   xsokoban
# Version required:    3.3b
# Date created:        16 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	xsokoban-3.3c
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.pmg.lcs.mit.edu/pub/xsokoban/

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xsokoban
ALL_TARGET=	xsokoban
MAN1=		xsokoban.1

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/xsokoban/scores \
		${PREFIX}/lib/X11/xsokoban/bitmaps/defaults \
		${PREFIX}/lib/X11/xsokoban/saves \
		${PREFIX}/lib/X11/xsokoban/screens
	@${CHMOD} 777 ${PREFIX}/lib/X11/xsokoban/scores
	@${CHMOD} 775 ${PREFIX}/lib/X11/xsokoban/saves
	@${INSTALL_DATA} ${WRKSRC}/screens/* ${PREFIX}/lib/X11/xsokoban/screens
	@${INSTALL_DATA} ${WRKSRC}/bitmaps/defaults/* \
		${PREFIX}/lib/X11/xsokoban/bitmaps/defaults
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
