# New ports collection makefile for:   xcubes
# Version required:    V5.3
# Date created:        12 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/11/17 10:53:01 asami Exp $
#

DISTNAME=	xcubes
PKGNAME=        xcubes-5.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/puzzles

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_IMAKE=	yes

post-install:
	@chmod 755 ${PREFIX}/bin/xcubes
	@/usr/sbin/chown ${BINOWN}.${BINGRP} ${PREFIX}/bin/xcubes
	@${INSTALL_DATA} ${WRKSRC}/Cubes.ad ${PREFIX}/lib/X11/app-defaults/Cubes

.include <bsd.port.mk>
