# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xwpick
PORTVERSION=	2.20
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=applications

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image pick up utility for X Window System

USES=		imake
USE_XORG=	x11 xext

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/xwpick
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${PREFIX}/share/doc/xwpick
	${INSTALL_DATA} ${WRKSRC}/CNL_ARTICLE.PS ${STAGEDIR}${PREFIX}/share/doc/xwpick
	${INSTALL_DATA} ${WRKSRC}/0README ${STAGEDIR}${PREFIX}/share/doc/xwpick/README

.include <bsd.port.mk>
