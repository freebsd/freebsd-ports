# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flower-fpw
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/Flower/
DISTNAME=	Flower-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dictionary for flowers (EPWING V1 format)

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/flower
EXTRACT_BEFORE_ARGS=	-qL

NO_STAGE=	yes
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
