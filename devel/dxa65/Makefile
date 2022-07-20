PORTNAME=	dxa
PORTVERSION=	0.1.4
CATEGORIES=	devel
MASTER_SITES=	http://www.floodgap.com/retrotech/xa/dists/
PKGNAMESUFFIX=	65

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Disassembler for MOS 6502 and compatible CPUs

LICENSE=	GPLv2+

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PORTDOCS=	INSTALL
PLIST_FILES=	bin/dxa65 man/man1/dxa.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dxa ${STAGEDIR}${PREFIX}/bin/dxa65
	${INSTALL_MAN} ${WRKSRC}/dxa.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
