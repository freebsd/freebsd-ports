# New ports collection makefile for:   xsokoban
# Version required:    3.3b
# Date created:        16 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	xsokoban-3.3b
CATEGORIES=	games x11
MASTER_SITES=   ftp://ftp.pmg.lcs.mit.edu/pub/xsokoban/

MAINTAINER=     Nakai@Mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=	yes
USE_IMAKE=	yes
XMKMF=		xmkmf
WRKSRC=		${WRKDIR}/xsokoban
ALL_TARGET=	xsokoban	

post-install:
	@mkdir -p ${PREFIX}/lib/X11/xsokoban/scores \
		${PREFIX}/lib/X11/xsokoban/bitmaps/defaults \
		${PREFIX}/lib/X11/xsokoban/saves \
		${PREFIX}/lib/X11/xsokoban/screens
	@chmod 777 ${PREFIX}/lib/X11/xsokoban/scores
	@chmod 775 ${PREFIX}/lib/X11/xsokoban/saves
	@${INSTALL_DATA} ${WRKSRC}/screens/* ${PREFIX}/lib/X11/xsokoban/screens
	@${INSTALL_DATA} ${WRKSRC}/bitmaps/defaults/* \
		${PREFIX}/lib/X11/xsokoban/bitmaps/defaults
	@echo "First, type: 'xsokoban -c' to make score files."
	@echo "You must be the superuser 'root', and enter password 'score'."
	@echo

.include <bsd.port.mk>
