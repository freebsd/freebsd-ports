# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	roget-fpw
PORTVERSION=	1.0.2
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/roget/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Roget's Thesaurus (EPWING V1 format)

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/roget
EXTRACT_BEFORE_ARGS=	-qL

NO_STAGE=	yes
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
