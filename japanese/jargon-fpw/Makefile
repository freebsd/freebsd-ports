# New ports collection makefile for:	The Jargon File - JIS X 4081 format version
# Date created:        	00/06/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jargon-fpw
PORTVERSION=	1.2a
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/jargon/
DISTNAME=	jarg-fpw${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org


USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/jargon
EXTRACT_BEFORE_ARGS=	-qL


do-install:
	${MKDIR} ${PREFIX}/share/dict/jargon-fpw/jargon/data
	${MKDIR} ${PREFIX}/share/dict/jargon-fpw/jargon/gaiji
	${INSTALL_DATA} ${WRKSRC}/jargon/data/honmon ${PREFIX}/share/dict/jargon-fpw/jargon/data
	${INSTALL_DATA} ${WRKSRC}/jargon/gaiji/gai16h ${PREFIX}/share/dict/jargon-fpw/jargon/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/jargon-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jargon-fpw
.for i in readme.1st readme.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/jargon-fpw
.endfor
.endif

.include <bsd.port.mk>
