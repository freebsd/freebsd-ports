# Created by: Seiichirou Hiraoka
# $FreeBSD$

PORTNAME=	xosmulti
PORTVERSION=	1.00
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	LOCAL/flathill
DISTNAME=	${PORTNAME}_${PORTVERSION}_tar
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Little girl cartoon on the top of the active window

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/README.jp

WRKSRC=		${WRKDIR}/xosmulti
USES=		xorg
USE_XORG=	x11 xbitmaps xext

OPTIONS_DEFINE=	DOCS

DOCSDIR=	share/doc/ja/xosmulti
PORTDOCS=	README.jp

PLIST_FILES=	bin/xosmulti

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xosmulti ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ja/xosmulti
	${INSTALL_DATA} ${WRKSRC}/README.jp ${STAGEDIR}${PREFIX}/share/doc/ja/xosmulti

.include <bsd.port.mk>
