# New ports collection makefile for:   xtriangles
# Version required:    V5.3
# Date created:        12 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	xtriangles
PKGNAME=        xtriangles-5.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/puzzles

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_IMAKE=	yes

post-install:
	@chmod 755 ${PREFIX}/bin/xtriangles
	@chown bin.bin ${PREFIX}/bin/xtriangles
	@${INSTALL_DATA} ${WRKSRC}/Triangles.ad \
		${PREFIX}/lib/X11/app-defaults/Triangles

.include <bsd.port.mk>
