# ports collection makefile for:	xmagv
# Version required:	1.11
# Date created:		25 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

DISTNAME=	xmagv111
PKGNAME=	xmagv-1.11
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.vector.co.jp/pack/unix/art/graphics/loader/mag/
EXTRACT_SUFX=	.tgz

MAINTAINER=	flathill@FreeBSD.org

WRKSRC=		${WRKDIR}/xmagv
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
