PORTNAME=	bzip
DISTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SOURCEWARE/bzip2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Block-sorting file compressor
WWW=		https://sourceware.org/bzip2/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CSTD=	gnu89

PLIST_FILES=	bin/bzip bin/bunzip \
		share/man/man1/bunzip.1.gz \
		share/man/man1/bzip.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bzip ${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${PREFIX}/bin/bzip ${STAGEDIR}${PREFIX}/bin/bunzip
	${INSTALL_MAN} ${WRKSRC}/bzip.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/bzip.1
	${INSTALL_MAN} ${WRKSRC}/bzip.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/bunzip.1

.include <bsd.port.mk>
