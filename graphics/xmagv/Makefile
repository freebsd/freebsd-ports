# ports collection makefile for:	xmagv
# Date created:		25 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	xmagv
PORTVERSION=	1.11
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.vector.co.jp/pack/unix/art/graphics/loader/mag/
DISTFILES=	xmagv111.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer for X Window System

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USE_IMAKE=	yes
USE_XORG=	x11 xext
XMKMF=		xmkmf
MANLANG=	. ja
MAN1=		xmagv.1

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

PLIST_FILES=	bin/xmagv
PORTDOCS=	xmagv.doc

post-install:
	${INSTALL_MAN} ${WRKSRC}/xmagv.j ${PREFIX}/man/ja/man1
	${MV} ${PREFIX}/man/ja/man1/xmagv.j ${PREFIX}/man/ja/man1/xmagv.1
	${GZIP_CMD} ${PREFIX}/man/ja/man1/xmagv.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/xmagv.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
