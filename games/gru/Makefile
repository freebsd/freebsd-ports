# New ports collection makefile for:	gru
# Date created:				21 Sep 1999
# Whom:					HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gru
PORTVERSION=	8087
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://hp.vector.co.jp/authors/VA004959/gru/

MAINTAINER=	hym@cocoa.freemail.ne.jp

USE_IMAKE=	yes

MAN1=		gru.1
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gru ${PREFIX}/bin
	@cp ${WRKSRC}/gru.man ${WRKSRC}/gru.1
	@${INSTALL_MAN} ${WRKSRC}/gru.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/gru.1.html ${PREFIX}/lib/X11/doc/html
	@install -d ${PREFIX}/share/doc/gru_8087
	@install -c -m 444 ${WRKSRC}/README.jp ${PREFIX}/share/doc/gru_8087

.include <bsd.port.mk>
