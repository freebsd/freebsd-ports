# New ports collection makefile for:	Devil's Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	devil-fpw
PORTVERSION=	1.0.2
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/devil/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/devil
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/devil-fpw/devil/data
	${INSTALL_DATA} ${WRKSRC}/devil/data/honmon ${PREFIX}/share/dict/devil-fpw/devil/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/devil-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/devil-fpw
.for i in readme.pkg readme.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/devil-fpw
.endfor
.endif

.include <bsd.port.mk>
