# New ports collection makefile for:   giftool
# Version required:    0.9
# Date created:        14 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/10/30 13:44:05 jfitz Exp $
#

DISTNAME=	giftool
PKGNAME=        giftool-0.9
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.huie.hokudai.ac.jp/pub/tool/graphics/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

NO_CDROM=	yes	#shareware

NO_WRKSUBDIR=	yes
ALL_TARGET=	giftool

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/giftool ${PREFIX}/bin
	@ ${MKDIR} -p ${PREFIX}/share/doc/giftool
	@ for file in COPYRIGHT README; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/giftool; \
	done
	@ ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/share/doc/giftool

post-install:
.if !defined(BATCH)
	@ more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>
