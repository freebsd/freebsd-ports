# New ports collection makefile for:	wdic - JIS X 4081 format version
# Date created:        	2000.07.12
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wdic-fpw
PORTVERSION=	1.4
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/wdic/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wired and Wireless Dictionary in Japanese (EPWING V1 format)

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/wdic
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/wdic-fpw/wdic/data
	${MKDIR} ${PREFIX}/share/dict/wdic-fpw/wdic/gaiji
	${INSTALL_DATA} ${WRKSRC}/wdic/data/honmon ${PREFIX}/share/dict/wdic-fpw/wdic/data
	${INSTALL_DATA} ${WRKSRC}/wdic/gaiji/gai16h ${PREFIX}/share/dict/wdic-fpw/wdic/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/wdic-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme.1st readme.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
