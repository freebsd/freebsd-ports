# New ports collection makefile for:	A Flower Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flower-fpw
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/Flower/
DISTNAME=	Flower-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dictionary for flowers (EPWING V1 format)

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/flower
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/flower-fpw/flower/data
	${INSTALL_DATA} ${WRKSRC}/flower/data/honmon ${PREFIX}/share/dict/flower-fpw/flower/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/flower-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
