# New ports collection makefile for:	CG Japanese Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGdic-fpw
PORTVERSION=	1.0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/CGdic1.5h/
DISTNAME=	CGdic1.5h-${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/cg
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/CGdic-fpw/cg/data
	${INSTALL_DATA} ${WRKSRC}/cg/data/honmon ${PREFIX}/share/dict/CGdic-fpw/cg/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/CGdic-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/CGdic-fpw
.for i in readme
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/CGdic-fpw
.endfor
.endif

.include <bsd.port.mk>
