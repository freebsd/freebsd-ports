# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lsd-fpw
PORTVERSION=	3.0.1
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/lsd/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese - English Dictionary for Life Science (EPWING V1 format)

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/lsd
EXTRACT_BEFORE_ARGS=	-qL

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/share/dict/lsd-fpw/lsd/data
	${INSTALL_DATA} ${WRKSRC}/lsd/data/honmon ${PREFIX}/share/dict/lsd-fpw/lsd/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/lsd-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme.pkg readme.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
