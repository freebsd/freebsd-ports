# New ports collection makefile for:   whirlgif
# Version required:     3.04
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	whirlgif304
PKGNAME=	whirlgif-3.04
CATEGORIES=	graphics
MASTER_SITES=	http://www.danbbs.dk/~dino/whirlgif/

MAINTAINER=	nakai@FreeBSD.org

NO_WRKSUBDIR=	yes

MAN1=		whirlgif.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whirlgif ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/whirlgif.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
