# New ports collection makefile for:	pejv 100 - JIS X 4081 format version
# Date created:        	2000.11.08
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pejv-fpw
PORTVERSION=	1.0.3
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/pejv/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/pejv
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/pejv-fpw/pejv/data
	${INSTALL_DATA} ${WRKSRC}/pejv/data/honmon ${PREFIX}/share/dict/pejv-fpw/pejv/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/pejv-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pejv-fpw
.for i in readme legumin.doc pejvo.doc
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/pejv-fpw
.endfor
.endif

.include <bsd.port.mk>
