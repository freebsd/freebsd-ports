# New ports collection makefile for:	ebd - JIS X 4081 format version
# Date created:        	01/08/23
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ebd-fpw
PORTVERSION=	1.0
PORTREVISON=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/ebd/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easton's 1897 Bible Dictionary (EPWING V1 format)

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ebd
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/ebd-fpw/ebd/data
	${INSTALL_DATA} ${WRKSRC}/ebd/data/honmon ${PREFIX}/share/dict/ebd-fpw/ebd/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/ebd-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme.1st readme.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
