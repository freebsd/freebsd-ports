# New ports collection makefile for:   xrubik
# Version required:    V5.3.2
# Date created:        20 October 1996
# Whom:                Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id: porting.sgml,v 1.25 1996/08/01 00:12:11 asami Exp $
#

DISTNAME=	xrubik
PKGNAME=        xrubik-5.3.2
CATEGORIES+=    games x11
MASTER_SITES=	ftp://ftp.iis.u-tokyo.ac.jp/pub1/X/contrib/games/puzzles/

MAINTAINER=     nakai@mlab.t.u-tokyo.ac.jp

USE_X11=	yes
USE_IMAKE=      yes

post-install:
	@chmod 755 ${PREFIX}/bin/xrubik
	@chown bin.bin ${PREFIX}/bin/xrubik
	${INSTALL_DATA} ${WRKSRC}/Rubik.ad ${PREFIX}/lib/X11/app-defaults/Rubik

.include <bsd.port.mk>
