# New ports collection makefile for:	Fumeikai Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fumeikai-fpw
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/Fumeikai/
DISTNAME=	Fumeikai-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An abbreviation (alphabet-->Japanese) dictionary (EPWING V1 format)

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/fumeikai
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/fumeikai-fpw/fumeikai/data
	${INSTALL_DATA} ${WRKSRC}/fumeikai/data/honmon ${PREFIX}/share/dict/fumeikai-fpw/fumeikai/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/fumeikai-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
