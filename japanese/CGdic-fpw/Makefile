# New ports collection makefile for:	CG Japanese Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGdic-fpw
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/CGdic1.5h/
DISTNAME=	CGdic1.5h-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese dictionary for CG (EPWING V1 format)

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/cg
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/CGdic-fpw/cg/data
	${INSTALL_DATA} ${WRKSRC}/cg/data/honmon ${PREFIX}/share/dict/CGdic-fpw/cg/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/CGdic-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
