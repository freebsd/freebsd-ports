# New ports collection makefile for:	Ryakugo Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ryaku-fpw
PORTVERSION=	1.0.1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/Ryaku/
DISTNAME=	Ryaku-${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ryaku
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/ryaku-fpw/ryaku/data
	${INSTALL_DATA} ${WRKSRC}/ryaku/data/honmon ${PREFIX}/share/dict/ryaku-fpw/ryaku/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/ryaku-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ryaku-fpw
.for i in readme
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/ryaku-fpw
.endfor
.endif

.include <bsd.port.mk>
