# New ports collection makefile for:	Fumeikai Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fumeikai-fpw
PORTVERSION=	1.0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/Fumeikai/
DISTNAME=	Fumeikai-${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/fumeikai
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/fumeikai-fpw/fumeikai/data
	${INSTALL_DATA} ${WRKSRC}/fumeikai/data/honmon ${PREFIX}/share/dict/fumeikai-fpw/fumeikai/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/fumeikai-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fumeikai-fpw
.for i in readme
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/fumeikai-fpw
.endfor
.endif

.include <bsd.port.mk>
