# New ports collection makefile for:	Roget's Thesaurus - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	roget-fpw
PORTVERSION=	1.0.2
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/roget/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Roget's Thesaurus (EPWING V1 format)

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/roget
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/roget-fpw/roget/data
	${MKDIR} ${PREFIX}/share/dict/roget-fpw/roget/gaiji
	${INSTALL_DATA} ${WRKSRC}/roget/data/honmon ${PREFIX}/share/dict/roget-fpw/roget/data
	${INSTALL_DATA} ${WRKSRC}/roget/gaiji/gai16h ${PREFIX}/share/dict/roget-fpw/roget/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/roget-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme.pkg readme.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
