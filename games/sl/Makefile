# New ports collection makefile for:    sl
# Date created:                17 Sep 1999
# Whom:                        HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	sl
PORTVERSION=	3.03
CATEGORIES=	games
MASTER_SITES=	http://www.tkl.iis.u-tokyo.ac.jp/~toyoda/sl/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar

MAINTAINER=	hym@cocoa.freemail.ne.jp

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

ALL_TARGET=	sl
MAN1=		sl.1
MANLANG=	ja

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sl ${PREFIX}/bin
	${MV} ${WRKSRC}/sl.1 ${WRKSRC}/sl.man
	nkf -e ${WRKSRC}/sl.man > ${WRKSRC}/sl.1
	${INSTALL_MAN} ${WRKSRC}/sl.1 ${PREFIX}/man/ja/man1
	${MKDIR} ${PREFIX}/share/doc/sl
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sl
	${INSTALL_DATA} ${WRKSRC}/sl.txt ${PREFIX}/share/doc/sl

.include <bsd.port.mk>
