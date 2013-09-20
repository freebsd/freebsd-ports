# Created by: Seiichirou Hiraoka
# $FreeBSD$

PORTNAME=	xosmulti
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flathill
DISTNAME=	${PORTNAME}_${PORTVERSION}_tar
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A little girl cartoon on the top of the active window

WRKSRC=		${WRKDIR}/xosmulti
USE_XORG=	xbitmaps x11 xt xi

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xosmulti ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xosmulti
	${INSTALL_MAN} ${WRKSRC}/README.jp ${PREFIX}/share/doc/ja/xosmulti
.endif

.include <bsd.port.mk>
