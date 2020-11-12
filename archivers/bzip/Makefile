# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	bzip
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	https://BSDforge.com/projects/source/archivers/bzip/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Block-sorting file compressor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CSTD=	gnu89

PLIST_FILES=	bin/bzip bin/bunzip \
		share/man/man1/bunzip.1.gz \
		share/man/man1/bzip.1.gz

pre-install:
	@${CAT} ${FILESDIR}/COPYRIGHT

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bzip ${STAGEDIR}${PREFIX}/bin
	${LN} -fs bzip ${STAGEDIR}${PREFIX}/bin/bunzip
	${INSTALL_MAN} ${WRKSRC}/bzip.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/bzip.1
	${INSTALL_MAN} ${WRKSRC}/bzip.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/bunzip.1

.include <bsd.port.mk>
