# ports collection makefile for:	xpx
# Date created:		25 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	xpx
PORTVERSION=	1.41
CATEGORIES=	graphics
MASTER_SITES=	http://www.oersted.co.jp/~yav/soft/xpx/
DISTNAME=	xpx141

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple pixel editing tool to make datas for KISS

WRKSRC=		${WRKDIR}/xpx
USE_IMAKE=	yes
XMKMF=		xmkmf

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xpx
	${INSTALL_MAN} ${WRKSRC}/xpx.doc ${WRKSRC}/xpxrc.eg ${PREFIX}/share/doc/ja/xpx
.endif

.include <bsd.port.mk>
