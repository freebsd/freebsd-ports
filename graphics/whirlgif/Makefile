# New ports collection makefile for:   whirlgif
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	whirlgif
PORTVERSION=	3.04
CATEGORIES=	graphics
MASTER_SITES=	http://www.danbbs.dk/~dino/whirlgif/
DISTNAME=	whirlgif304

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for making GIF animations

NO_WRKSUBDIR=	yes

MAN1=		whirlgif.1
PLIST_FILES=	bin/whirlgif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whirlgif ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/whirlgif.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
