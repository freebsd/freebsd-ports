# New ports collection makefile for:	xwpick
# Date created:				24 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xwpick
PORTVERSION=	2.20
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=applications

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image pick up utility for X Window System

USE_IMAKE=	yes
USE_XORG=	x11 xext
MAN1=		xwpick.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/xwpick
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${PREFIX}/share/doc/xwpick
	${INSTALL_DATA} ${WRKSRC}/CNL_ARTICLE.PS ${PREFIX}/share/doc/xwpick
	${INSTALL_DATA} ${WRKSRC}/0README ${PREFIX}/share/doc/xwpick/README
.endif

.include <bsd.port.mk>
