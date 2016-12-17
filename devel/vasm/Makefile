# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	vasm
PORTVERSION=	1.7g
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://server.owl.de/%SUBDIR%/
MASTER_SITE_SUBDIR=	~frank/tags/
DISTNAME=	vasm1_7g

MAINTAINER=	cs@innolan.dk
COMMENT=	Portable 6502 6800 arm c16x jagrisc m68k ppc vidcore x86 z80 assembler

LEGAL_TEXT=	This archive may be redistributed without modifications and used for non-commercial purposes.

USES=		gmake pathfix
WRKSRC=		${WRKDIR}/vasm

CPU_LIST=	6502 6800 arm c16x jagrisc m68k ppc test tr3200 vidcore x86 z80
SYNTAX_LIST=	std madmac mot oldstyle test
OUTPUT_LIST=	aout bin elf hunk test tos vobj

do-build:
.for CPU in ${CPU_LIST}
.for SYNTAX in ${SYNTAX_LIST}
	${GMAKE} -C ${WRKSRC} CC=${CC} CPU=${CPU} SYNTAX=${SYNTAX} >/dev/null 2>&1
.endfor
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vobjdump ${STAGEDIR}${PREFIX}/bin
.for CPU in ${CPU_LIST}
.for SYNTAX in ${SYNTAX_LIST}
	${INSTALL_PROGRAM} ${WRKSRC}/vasm${CPU}_${SYNTAX} ${STAGEDIR}${PREFIX}/bin
.endfor
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for CPU in ${CPU_LIST}
.for SYNTAX in ${SYNTAX_LIST}
	-test -f ${WRKSRC}/doc/cpu_${CPU}.texi && ${INSTALL_MAN} ${WRKSRC}/doc/cpu_${CPU}.texi ${STAGEDIR}${DOCSDIR}
	-test -f ${WRKSRC}/doc/syntax_${SYNTAX}.texi && ${INSTALL_MAN} ${WRKSRC}/doc/syntax_${SYNTAX}.texi ${STAGEDIR}${DOCSDIR}
.for OUTPUT in ${OUTPUT_LIST}
	-test -f ${WRKSRC}/doc/output_${OUTPUT}.texi && ${INSTALL_MAN} ${WRKSRC}/doc/output_${OUTPUT}.texi ${STAGEDIR}${DOCSDIR}
.endfor
.endfor
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/vasm.texi ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/vasm_main.texi ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/interface.texi ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
