# New ports collection makefile for:	Web1913 - JIS X 4081 format version
# Date created:        	00/06/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	web1913-fpw
PORTVERSION=	${WEBFPW_VER}
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/web1913/
DISTNAME=	${PORTNAME}${WEBFPW_VER}

MAINTAINER=	taoka@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/web
EXTRACT_BEFORE_ARGS=	-qL
WEBFPW_VER=	1.1.1

do-install:
	${MKDIR} ${PREFIX}/share/dict/web-fpw/web/data
	${INSTALL_DATA} ${WRKSRC}/web/data/honmon ${PREFIX}/share/dict/web-fpw/web/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/web-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/web-fpw
	${INSTALL_DATA} ${WRKSRC}/readme ${PREFIX}/share/doc/web-fpw
.endif

.include <bsd.port.mk>
