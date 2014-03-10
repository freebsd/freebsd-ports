# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bible_names-fpw
PORTVERSION=	1.1.3
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/bible_names/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dictionary for HITCHCOCK'S BIBLE NAMES (EPWING V1 format)

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/biblenam
EXTRACT_BEFORE_ARGS=	-qL

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/share/dict/bible_names-fpw/biblenam/data
	${INSTALL_DATA} ${WRKSRC}/biblenam/data/honmon ${PREFIX}/share/dict/bible_names-fpw/biblenam/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/bible_names-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
