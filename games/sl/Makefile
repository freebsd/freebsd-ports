# New ports collection makefile for:    sl
# Date created:                17 Sep 1999
# Whom:                        HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	sl
PORTVERSION=	3.03${SLPATCHVERSION}
CATEGORIES=	games
MASTER_SITES=	http://www.tkl.iis.u-tokyo.ac.jp/~toyoda/sl/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar

.if defined(WITH_PERSISTENT)
SLPATCHVERSION=	.5p1
PATCH_SITES=	http://www.linet.gr.jp/~izumi/sl/
PATCHFILES=	sl5-1.patch
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	hym@cocoa.freemail.ne.jp
COMMENT=	A steam locomotive runs across the screen if you type "sl" instead of "ls"

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

ALL_TARGET=	sl
MAN1=		sl.1
MANLANG=	ja

pre-everything::
.if !defined(WITH_PERSISTENT)
	@${ECHO_MSG}
	@${ECHO_MSG} " If you want to apply additional patch to make sl more annoying,"
	@${ECHO_MSG} " hit Ctrl-C right now and use \"make WITH_PERSISTENT=yes\""
	@${ECHO_MSG}
.endif

do-build:
	@${CC} ${CFLAGS} -I${WRKSRC} -o ${WRKSRC}/sl ${WRKSRC}/sl.c -lcurses -ltermcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sl ${PREFIX}/bin
	${MV} ${WRKSRC}/sl.1 ${WRKSRC}/sl.man
	nkf -e ${WRKSRC}/sl.man > ${WRKSRC}/sl.1
	${INSTALL_MAN} ${WRKSRC}/sl.1 ${PREFIX}/man/ja/man1
	${MKDIR} ${PREFIX}/share/doc/sl
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sl
	${INSTALL_DATA} ${WRKSRC}/sl.txt ${PREFIX}/share/doc/sl

.include <bsd.port.mk>
