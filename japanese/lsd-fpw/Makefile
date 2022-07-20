PORTNAME=	lsd-fpw
PORTVERSION=	3.0.1
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/lsd/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese - English Dictionary for Life Science (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/lsd
EXTRACT_BEFORE_ARGS=	-qL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/lsd-fpw/lsd/data
	${INSTALL_DATA} ${WRKSRC}/lsd/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/lsd-fpw/lsd/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${STAGEDIR}${PREFIX}/share/dict/lsd-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} readme.pkg readme.txt \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
