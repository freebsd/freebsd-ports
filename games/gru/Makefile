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

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/ja/gru
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.jp ${DOCSDIR}
.endif

.include <bsd.port.mk>
