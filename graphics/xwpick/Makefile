# New ports collection makefile for:	xwpick
# Version required:			2.20
# Date created:				24 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		xwpick-2.20
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=		ports@FreeBSD.org

USE_IMAKE=		yes
MAN1=			xwpick.1
MANCOMPRESSED=		no

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xwpick ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/xwpick.man ${PREFIX}/man/man1/xwpick.1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/xwpick
	@ ${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${PREFIX}/share/doc/xwpick
	@ ${INSTALL_DATA} ${WRKSRC}/CNL_ARTICLE.PS ${PREFIX}/share/doc/xwpick
	@ ${INSTALL_DATA} ${WRKSRC}/0README ${PREFIX}/share/doc/xwpick/README
.endif

.include <bsd.port.mk>
