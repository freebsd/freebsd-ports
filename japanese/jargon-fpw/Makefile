# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jargon-fpw
PORTVERSION=	2.0
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/jargon/
DISTNAME=	jargon-fpw${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The famous jargon file (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/jargon
EXTRACT_BEFORE_ARGS=	-qL


NO_STAGE=	yes
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
