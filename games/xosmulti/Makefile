# ports collection makefile for:   xosmulti
# Date created:        17 February 1999
# Whom:                Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	xosmulti
PORTVERSION=	1.00
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flathill
DISTNAME=	${PORTNAME}_${PORTVERSION}_tar
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A little girl cartoon on the top of the active window

WRKSRC=		${WRKDIR}/xosmulti
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xosmulti ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xosmulti
	${INSTALL_MAN} ${WRKSRC}/README.jp ${PREFIX}/share/doc/ja/xosmulti
.endif

.include <bsd.port.mk>
