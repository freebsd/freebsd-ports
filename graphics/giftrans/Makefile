# New ports collection makefile for:   giftrans
# Version required:    v1.12
# Date created:        14 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.3 1999/01/05 06:00:08 simokawa Exp $
#

DISTNAME=	giftrans
PKGNAME=	giftrans-1.12
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/infosystems/misc/tools/

MAINTAINER=	nacai@iname.com

CONFIGURE_ENV=	X11BASE=${X11BASE}
MAN1=		giftrans.1

do-build:
	(cd ${WRKSRC}; cc -O2 giftrans.c -o giftrans)

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/giftrans ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/giftrans.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
