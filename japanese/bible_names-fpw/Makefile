# New ports collection makefile for:	HITCHCOCK'S BIBLE NAMES Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bible_names-fpw
PORTVERSION=	1.1.2
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/bible_names/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/biblenam
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/bible_names-fpw/biblenam/data
	${INSTALL_DATA} ${WRKSRC}/biblenam/data/honmon ${PREFIX}/share/dict/bible_names-fpw/biblenam/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/bible_names-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bible_names-fpw
.for i in biblenam.txt readme
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/bible_names-fpw
.endfor
.endif

.include <bsd.port.mk>
