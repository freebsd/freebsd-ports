#New ports collection makefile for:    xrubik
# Version required:     V5.3.2
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	xrubik
PKGNAME=        xrubik-5.3.2
CATEGORIES+=    games x11
MASTER_SITES=   ftp://ftp.iis.u-tokyo.ac.jp/pub1/X/contrib/games/puzzles/

MAINTAINER=     nakai@mlab.t.u-tokyo.ac.jp

USE_IMAKE=      yes
USE_X11=        yes

post-install:
	@chmod 755 ${PREFIX}/bin/xrubik
	@chown bin.bin ${PREFIX}/bin/xrubik

.include <bsd.port.mk>
