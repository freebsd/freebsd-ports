# New ports collection makefile for:   xbakuzan
# Version required:    1.0
# Date created:        11 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/11/29 07:20:58 tg Exp $
#

DISTNAME=	xbakuzan
PKGNAME=        xbakuzan-1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xwin/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

ALL_TARGET=	xbakuzan
USE_X11=	yes

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xbakuzan ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/X11/xbakuzan
	${INSTALL_DATA} ${WRKSRC}/sakana.xbm ${PREFIX}/lib/X11/xbakuzan
	${INSTALL_DATA} ${WRKSRC}/xbakuzan.doc ${PREFIX}/lib/X11/xbakuzan

.include <bsd.port.mk>
