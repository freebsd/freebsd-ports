# New ports collection makefile for:	WordNet - JIS X 4081 format version
# Date created:        	00/06/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wordnet-fpw
PORTVERSION=	${WN_VER}.${WNFPW_VER}
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/wordnet/
DISTNAME=	wordnet-${WN_VER}-fpw${WNFPW_VER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A English - English Dictionary (EPWING V1 format)

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/wordnet
EXTRACT_BEFORE_ARGS=	-qL
WNFPW_VER=	1.1.3
WN_VER=		1.6


do-install:
	${MKDIR} ${PREFIX}/share/dict/wordnet-fpw/wordnet/data
	${INSTALL_DATA} ${WRKSRC}/wordnet/data/honmon ${PREFIX}/share/dict/wordnet-fpw/wordnet/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/wordnet-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
