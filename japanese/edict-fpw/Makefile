# New ports collection makefile for:	EDICT - JIS X 4081 format version
# Date created:        	00/01/14
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edict-fpw
PORTVERSION=	1.2.1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/edict/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/edict
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/edict-fpw/edict/data
	${INSTALL_DATA} ${WRKSRC}/edict/data/honmon ${PREFIX}/share/dict/edict-fpw/edict/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/edict-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/edict-fpw
.for i in readme.pkg edict.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/edict-fpw
.endfor
.endif

.include <bsd.port.mk>
