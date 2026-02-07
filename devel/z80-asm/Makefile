PORTNAME=	z80-asm
PORTVERSION=	2.4.1
CATEGORIES=	devel
MASTER_SITES=	http://wwwhomes.uni-bielefeld.de/achim/z80-asm/
DISTNAME=	z80-asm-current
DIST_SUBDIR=	z80-asm

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	Z80 assembly code assembler and disassembler
WWW=		https://wwwhomes.uni-bielefeld.de/achim/z80-asm.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USES=		gmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS
PORTDOCS=	CHANGELOG README TODO z80-asm.html z80-mon.html
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/z80-asm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/z80-mon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.3 ${STAGEDIR}${PREFIX}/share/man/man3
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.5 ${STAGEDIR}${PREFIX}/share/man/man5

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
