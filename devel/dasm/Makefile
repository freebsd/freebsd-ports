PORTNAME=	dasm
DISTVERSION=	2.20.14.1
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Macro assembler with support for several 8-bit microprocessors
WWW=		https://dasm-assembler.github.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	dasm-assembler
TEST_TARGET=	test

PLIST_FILES=	bin/dasm \
		bin/ftohex \
		share/man/man1/dasm.1.gz
PORTDOCS=	dasm.txt \
		dasm.pdf \
		ftohex.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dasm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ftohex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/dasm.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/docs/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
