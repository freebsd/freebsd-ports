# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	edict-fpw
PORTVERSION=	1.2.2
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/edict/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese <-> English Dictionary (EPWING V1 format)

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/edict
EXTRACT_BEFORE_ARGS=	-qL

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/share/dict/edict-fpw/edict/data
	${INSTALL_DATA} ${WRKSRC}/edict/data/honmon ${PREFIX}/share/dict/edict-fpw/edict/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/edict-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme.pkg edict.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
