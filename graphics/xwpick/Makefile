# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xwpick
PORTVERSION=	2.20
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	XCONTRIB/applications

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image pick up utility for X Window System

LICENSE=	xwpick
LICENSE_NAME=	xwpick license  # non-commercial
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		imake
USE_XORG=	x11 xext

OPTIONS_DEFINE=	DOCS

post-extract:
	@${SED} -ne '/COPYRIGHT NOTICE/,$$ p' ${WRKSRC}/0README >${WRKSRC}/COPYING

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CNL_ARTICLE.PS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/0README ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
