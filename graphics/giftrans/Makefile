# New ports collection makefile for:   giftrans
# Version required:    v1.12
# Date created:        14 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	giftrans
PKGNAME=        giftrans-1.12
CATEGORIES+=	graphics
MASTER_SITES=   ftp://ftp.lab.kdd.co.jp/infosystems/misc/tools/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

CONFIGURE_ENV+=	X11BASE=${X11BASE}

do-build:
	(cd ${WRKSRC}; cc -O2 -m486 giftrans.c -o giftrans)

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/giftrans ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/giftrans.1 ${PREFIX}/man/man1

.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/giftrans.1
.endif

.include <bsd.port.mk>
