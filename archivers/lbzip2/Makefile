# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lbzip2
PORTVERSION=	0.23
CATEGORIES=	archivers
MASTER_SITES=	http://lacos.web.elte.hu/pub/lbzip2/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Multi-threaded bzip2/bunzip2 filter

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/lbzip2 \
		man/man1/lbzip2.1.gz

PORTDOCS=	ChangeLog README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lbzip2 ${STAGEDIR}${PREFIX}/bin/lbzip2
	${INSTALL_MAN} ${WRKSRC}/lbzip2.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
