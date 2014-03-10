# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	web1913-fpw
PORTVERSION=	${WEBFPW_VER}
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/web1913/
DISTNAME=	${PORTNAME}${WEBFPW_VER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webster's Revised Unabridged Dictionary (1913) (EPWING V1 format)

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/web
EXTRACT_BEFORE_ARGS=	-qL
WEBFPW_VER=	1.1.2

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/share/dict/web-fpw/web/data
	${INSTALL_DATA} ${WRKSRC}/web/data/honmon ${PREFIX}/share/dict/web-fpw/web/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/web-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
