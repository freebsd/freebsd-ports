# ports collection makefile for:	xmagv
# Date created:		25 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	xmagv
PORTVERSION=	1.11
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.vector.co.jp/pack/unix/art/graphics/loader/mag/
DISTFILES=	xmagv111.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USE_IMAKE=	yes
XMKMF=		xmkmf
MANLANG=	. ja
MAN1=		xmagv.1

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/xmagv.j ${PREFIX}/man/ja/man1
	${MV} ${PREFIX}/man/ja/man1/xmagv.j ${PREFIX}/man/ja/man1/xmagv.1
	${GZIP_CMD} ${PREFIX}/man/ja/man1/xmagv.1
	${MKDIR} ${PREFIX}/share/doc/ja/xmagv
	${INSTALL_MAN} ${WRKSRC}/xmagv.doc ${PREFIX}/share/doc/ja/xmagv
.endif

.include <bsd.port.mk>
