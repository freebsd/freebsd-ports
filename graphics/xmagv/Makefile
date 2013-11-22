# Created by: Seiichirou Hiraoka
# $FreeBSD$

PORTNAME=	xmagv
PORTVERSION=	1.11
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://ftp.vector.co.jp/pack/unix/art/graphics/loader/mag/
DISTFILES=	xmagv111.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer for X Window System

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-12-22

BROKEN=		Does not build
USES=		imake:env
WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USE_XORG=	x11 xext
MANLANG=	. ja
MAN1=		xmagv.1

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

PLIST_FILES=	bin/xmagv
PORTDOCS=	xmagv.doc

NO_STAGE=	yes
post-install:
	${INSTALL_MAN} ${WRKSRC}/xmagv.j ${PREFIX}/man/ja/man1
	${MV} ${PREFIX}/man/ja/man1/xmagv.j ${PREFIX}/man/ja/man1/xmagv.1
	${GZIP_CMD} ${PREFIX}/man/ja/man1/xmagv.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/xmagv.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
