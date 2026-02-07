PORTNAME=	ttcp
DISTVERSIONPREFIX=	${PORTNAME}-
PORTVERSION=	1.13
CATEGORIES=	benchmarks net
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Benchmarking tool for analysing TCP and UDP performance
WWW=		https://codeberg.org/BSDforge/ttcp/

LICENSE=	BSD0CLAUSE

CFLAGS+=	-Wno-strict-prototypes

PLIST_FILES=			bin/ttcp share/man/man1/ttcp.1.gz
PORTDOCS=		README CHANGES LICENSE
OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/ttcp ${WRKSRC}/ttcp.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttcp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttcp.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
