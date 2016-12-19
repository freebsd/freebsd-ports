# Created by: Samy Al Bahra <samy@kerneled.org>
# $FreeBSD$

PORTNAME=	z80-asm
PORTVERSION=	2.4.p3
CATEGORIES=	devel
MASTER_SITES=	http://wwwhomes.uni-bielefeld.de/achim/z80-asm/
DISTNAME=	${PORTNAME}-2.3
DIST_SUBDIR=	z80-asm

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	diff_2.3_2.4-pre3.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Z80 assembly code assembler and disassembler

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USES=		gmake

PORTDOCS=	CHANGELOG README TODO z80-asm.html z80-mon.html

OPTIONS_DEFINE=	DOCS

post-extract:
	@${TOUCH} ${WRKSRC}/hardware/bus_masters

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}|g ; \
		 s|^CC=|CC?=|g ; \
		 s|=-O2|+=|g ; \
		 s|make |$$(MAKE) |g ; \
		 s|gcc |$$(CC) |g'  ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		'/LCD=/s|^|#|g ; \
		 s|^CC=|CC?=|g ; \
		 s|=-O2|+=|g ; \
		 s|gcc |$$(CC) |g ; \
		 s|-lc ||g' ${WRKSRC}/hardware/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/z80-asm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/z80-mon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.3 ${STAGEDIR}${MAN3PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
