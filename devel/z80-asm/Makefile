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
COMMENT=	A Z80 assembly code assembler and disassembler

USE_GMAKE=	yes

MAN1=		z80-asm.1 z80-mon.1
MAN3=		z80-cpu.3 z80-memory.3
MAN5=		z80-asm.5 z80-banks.5 z80-file.5 z80-keyboard.5 \
		z80-memory.5 z80-ports.5
PORTDOCS=	CHANGELOG README TODO z80-asm.html z80-mon.html
PLIST_FILES=	${BINS:S,^,bin/,}

BINS=		z80-asm z80-mon

NO_STAGE=	yes
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
.for file in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/man/${file} ${MAN1PREFIX}/man/man1
.endfor
.for file in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/doc/man/${file} ${MAN3PREFIX}/man/man3
.endfor
.for file in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/doc/man/${file} ${MAN5PREFIX}/man/man5
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
