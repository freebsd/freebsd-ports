# New ports collection makefile for:   xpuyo
# Version required:    0.0
# Date created:        12 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	xpuyo
PKGNAME=        xpuyo-0.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.huee.hokudai.ac.jp/pub/games/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_IMAKE=	yes
XMKMF=		xmkmf
NO_INSTALL_MANPAGES=yes

RESTRICTED=	the author ashames the quality of this version

post-install:
	@chmod 755 ${PREFIX}/bin/xpuyo
	@chown bin.bin ${PREFIX}/bin/xpuyo
	${MKDIR} ${PREFIX}/share/doc/xpuyo
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/xpuyo

.include <bsd.port.mk>
