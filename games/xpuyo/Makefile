# New ports collection makefile for:   xpuyo
# Version required:    0.0
# Date created:        12 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.4 1997/09/10 15:28:48 max Exp $
#

DISTNAME=	xpuyo
PKGNAME=	xpuyo-0.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.meme.hokudai.ac.jp/pub/games/

MAINTAINER=	nacai@iname.com

USE_IMAKE=	yes
XMKMF=		xmkmf
NO_INSTALL_MANPAGES=yes

RESTRICTED=	"The author ashames the quality of this version"

post-install:
	@chmod 755 ${PREFIX}/bin/xpuyo
	@/usr/sbin/chown ${BINOWN}.${BINGRP} ${PREFIX}/bin/xpuyo
	${MKDIR} ${PREFIX}/share/doc/xpuyo
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/xpuyo

.include <bsd.port.mk>
