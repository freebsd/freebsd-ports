# New ports collection makefile for:	A Biographical Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wwasw-fpw
PORTVERSION=	1.0.1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/wwasw/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/wwasw
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/wwasw-fpw/wwasw/data
	${INSTALL_DATA} ${WRKSRC}/wwasw/data/honmon ${PREFIX}/share/dict/wwasw-fpw/wwasw/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/wwasw-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/wwasw-fpw
.for i in readme.pkg readme.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/wwasw-fpw
.endfor
.endif

.include <bsd.port.mk>
