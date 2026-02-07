PORTNAME=	lbrate
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	SUNSITE/utils/compress

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Extract/decompress CP/M LBR archives
WWW=		http://freshmeat.net/projects/lbrate/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_ARGS=	CC="${CC}" CFLAGS="${CPPFLAGS} ${CFLAGS} ${LDFLAGS}"

PORTDOCS=	ChangeLog README TODO
PLIST_FILES=	bin/lbrate \
		share/man/man1/lbrate.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lbrate ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lbrate.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
