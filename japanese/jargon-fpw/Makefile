# New ports collection makefile for:	The Jargon File - JIS X 4081 format version
# Date created:        	00/06/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jargon-fpw
PORTVERSION=	2.0
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/jargon/
DISTNAME=	jargon-fpw${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The famous jargon file (EPWING V1 format)


USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/jargon
EXTRACT_BEFORE_ARGS=	-qL


do-install:
	${MKDIR} ${PREFIX}/share/dict/jargon-fpw/jargon/data
	${MKDIR} ${PREFIX}/share/dict/jargon-fpw/jargon/gaiji
	${INSTALL_DATA} ${WRKSRC}/jargon/data/honmon ${PREFIX}/share/dict/jargon-fpw/jargon/data
	${INSTALL_DATA} ${WRKSRC}/jargon/gaiji/gai16f ${PREFIX}/share/dict/jargon-fpw/jargon/gaiji
	${INSTALL_DATA} ${WRKSRC}/jargon/gaiji/gai16h ${PREFIX}/share/dict/jargon-fpw/jargon/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/jargon-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme.1st readme.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
