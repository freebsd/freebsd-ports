# New ports collection makefile for:   xdino
# Version required:    V5.3
# Date created:        12 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/11/16 12:49:18 asami Exp $
#

DISTNAME=	xdino
PKGNAME=        xdino-5.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/puzzles

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_IMAKE=	yes

post-install:
	@chmod 755 ${PREFIX}/bin/xdino
	@/usr/sbin/chown ${BINOWN}.${BINGRP} ${PREFIX}/bin/xdino
	@${INSTALL_DATA} ${WRKSRC}/Dino.ad ${PREFIX}/lib/X11/app-defaults/Dino

.include <bsd.port.mk>
