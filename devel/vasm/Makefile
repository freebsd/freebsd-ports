# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	vasm
PORTVERSION=	1.8a
CATEGORIES=	devel
MASTER_SITES=	http://server.owl.de/~frank/tags/
DISTNAME=	vasm1_8a

MAINTAINER=	cs@innolan.dk
COMMENT=	Portable 6502 6800 arm c16x jagrisc m68k ppc vidcore x86 z80 assembler

LICENSE=	VASMBSD
LICENSE_NAME=	vasm license for FreeBSD
LICENSE_TEXT=	vasm comes with its own license. The source archive may be redistributed \
		without modifications and used for non-commercial purposes. \
		Binary packages are distributed with permission of the author by FreeBSD
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		gmake pathfix
WRKSRC=		${WRKDIR}/vasm

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	DOCS
DOCS_USES=	makeinfo

CPU_LIST=	6502 6800 arm c16x jagrisc m68k ppc qnice tr3200 vidcore x86 z80
SYNTAX_LIST=	std madmac mot oldstyle test
OUTPUT_LIST=	aout bin elf hunk test tos vobj
DOC_LIST=	cpu_6502 cpu_jagrisc cpu_x86 output_bin output_test syntax_mot vasm_main \
		cpu_6800 cpu_m68k cpu_z80 output_elf output_tos syntax_oldstyle cpu_arm \
		cpu_ppc interface output_hunk output_vobj syntax_std cpu_c16x cpu_tr3200 \
		output_aout output_srec syntax_madmac vasm

do-build:
.for CPU in ${CPU_LIST}
.for SYNTAX in ${SYNTAX_LIST}
	${MAKE_CMD} -C ${WRKSRC} CC=${CC} CPU=${CPU} SYNTAX=${SYNTAX}
.endfor
.endfor

do-build-DOCS-on:
.for DOC in ${DOC_LIST}
	makeinfo --plaintext --force --no-validate ${WRKSRC}/doc/${DOC}.texi -o ${WRKSRC}/doc/${DOC}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vobjdump ${STAGEDIR}${PREFIX}/bin
.for CPU in ${CPU_LIST}
.for SYNTAX in ${SYNTAX_LIST}
	${INSTALL_PROGRAM} ${WRKSRC}/vasm${CPU}_${SYNTAX} ${STAGEDIR}${PREFIX}/bin
.endfor
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DOC in ${DOC_LIST}
	${INSTALL_MAN} ${WRKSRC}/doc/${DOC} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
