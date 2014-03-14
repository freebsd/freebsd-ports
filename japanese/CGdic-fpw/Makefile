# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGdic-fpw
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/CGdic1.5h/
DISTNAME=	CGdic1.5h-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese dictionary for CG (EPWING V1 format)

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/cg
EXTRACT_BEFORE_ARGS=	-qL

NO_STAGE=	yes
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
