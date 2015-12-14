# Created by: elbarto
# $FreeBSD$

PORTNAME=	asmx
PORTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://xi6.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-CPU macro assembler for many major 8-bit and 16-bit CPUs

USES=		zip
NO_WRKSUBDIR=	yes

PORTDOCS=	README.txt

OPTIONS_DEFINE=	1802 6502 6809 68HC11 68HC16 68000 8051 8085 F8 Z80 DOCS
OPTIONS_DEFAULT=1802 6502 6809 68HC11 68HC16 68000 8051 8085 F8 Z80

1802_DESC=	RCA 1802
6502_DESC=	MOS Technology 6502, 65C02 and 6502
6809_DESC=	Motorola 6809
68HC11_DESC=	Motorola 6800/6801/68HC11 and Hitachi 6303
68HC16_DESC=	Motorola 68HC16
68000_DESC=	Motorola 68000/68010
8051_DESC=	Intel 8051
8085_DESC=	Intel 8080 and 8085
F8_DESC=	Fairchild F8
Z80_DESC=	Zilog Z-80 and Nintendo Gameboy Z-80 variant

1802_ALL_TARGET=	asmx-1802
1802_PLIST_FILES=	bin/asmx-1802
6502_ALL_TARGET=	asmx-6502
6502_PLIST_FILES=	bin/asmx-6502
6809_ALL_TARGET=	asmx-6809
6809_PLIST_FILES=	bin/asmx-6809
68HC11_ALL_TARGET=	asmx-68hc11
68HC11_PLIST_FILES=	bin/asmx-68hc11
68HC16_ALL_TARGET=	asmx-68hc16
68HC16_PLIST_FILES=	bin/asmx-68hc16
68000_ALL_TARGET=	asmx-68k
68000_PLIST_FILES=	bin/asmx-68k
8051_ALL_TARGET=	asmx-8051
8051_PLIST_FILES=	bin/asmx-8051
8085_ALL_TARGET=	asmx-8085
8085_PLIST_FILES=	bin/asmx-8085
F8_ALL_TARGET=		asmx-f8
F8_PLIST_FILES=		bin/asmx-f8
Z80_ALL_TARGET=		asmx-z80
Z80_PLIST_FILES=	bin/asmx-z80

.include <bsd.port.options.mk>

post-patch:
	@${ECHO_CMD} >> ${WRKSRC}/asmguts.h

do-build:
.for f in ${ALL_TARGET}
	(cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} ${f:S/asmx-/asm/}.c -o ${f})
.endfor

do-install:
.for f in ${ALL_TARGET}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
