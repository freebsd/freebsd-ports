# Created by: ijliao
# $FreeBSD$

PORTNAME=	nomarch
PORTVERSION=	1.4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Extracts files from the old '.arc' archive format

PLIST_FILES=	bin/nomarch man/man1/nomarch.1.gz
PORTDOCS=	COPYING ChangeLog NEWS README TODO
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomarch ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nomarch.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
