# New ports collection makefile for:	foldoc - JIS X 4081 format version
# Date created:        	01/08/23
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	foldoc-fpw
PORTVERSION=	1.0.2
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/foldoc/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Free On-line Dictionary of Computing (EPWING V1 format)

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/foldoc
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/foldoc-fpw/foldoc/data
	${MKDIR} ${PREFIX}/share/dict/foldoc-fpw/foldoc/gaiji
	${INSTALL_DATA} ${WRKSRC}/foldoc/data/honmon ${PREFIX}/share/dict/foldoc-fpw/foldoc/data
	${INSTALL_DATA} ${WRKSRC}/foldoc/gaiji/gai16h ${PREFIX}/share/dict/foldoc-fpw/foldoc/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/foldoc-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
