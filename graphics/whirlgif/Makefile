# New ports collection makefile for:   whirlgif
# Version required:     2.01
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	whirlgif
PKGNAME=	whirlgif-2.01
CATEGORIES=	graphics
MASTER_SITES=	http://www.msg.net/utility/whirlgif/

MAINTAINER=	nacai@iname.com

MAN1=		whirlgif.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whirlgif ${PREFIX}/bin/whirlgif
	${INSTALL_MAN} ${WRKSRC}/whirlgif.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
