# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wordnet-fpw
PORTVERSION=	${WN_VER}.${WNFPW_VER}
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/wordnet/
DISTNAME=	wordnet-${WN_VER}-fpw${WNFPW_VER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A English - English Dictionary (EPWING V1 format)

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/wordnet
EXTRACT_BEFORE_ARGS=	-qL
WNFPW_VER=	1.1.3
WN_VER=		1.6


NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/share/dict/wordnet-fpw/wordnet/data
	${INSTALL_DATA} ${WRKSRC}/wordnet/data/honmon ${PREFIX}/share/dict/wordnet-fpw/wordnet/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/wordnet-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
