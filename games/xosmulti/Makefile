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
COMMENT=	Little girl cartoon on the top of the active window

WRKSRC=		${WRKDIR}/xosmulti
USE_XORG=	xbitmaps x11 xt xi

OPTIONS_DEFINE=	DOCS

DOCSDIR=	share/doc/ja/xosmulti
PORTDOCS=	README.jp

PLIST_FILES=	bin/xosmulti

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xosmulti ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ja/xosmulti
	${INSTALL_MAN} ${WRKSRC}/README.jp ${STAGEDIR}${PREFIX}/share/doc/ja/xosmulti

.include <bsd.port.mk>
