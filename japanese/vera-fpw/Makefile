# New ports collection makefile for:	V.E.R.A - JIS X 4081 format version
# Date created:        	00/06/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vera-fpw
PORTVERSION=	${VERA_VER}.${VERAFPW_VER}
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/vera/
DISTNAME=	vera-${VERA_VER}-fpw${VERAFPW_VER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual Entity of Relevant Aconyms (EPWING V1 format)

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/vera
EXTRACT_BEFORE_ARGS=	-qL
VERA_VER=	1.8
VERAFPW_VER=	1.0.3

do-install:
	${MKDIR} ${PREFIX}/share/dict/vera-fpw/vera/data
	${MKDIR} ${PREFIX}/share/dict/vera-fpw/vera/gaiji
	${INSTALL_DATA} ${WRKSRC}/vera/data/honmon ${PREFIX}/share/dict/vera-fpw/vera/data
	${INSTALL_DATA} ${WRKSRC}/vera/gaiji/gai16h ${PREFIX}/share/dict/vera-fpw/vera/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/vera-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme.txt vera.tex
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
