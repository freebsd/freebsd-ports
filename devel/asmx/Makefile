# Created by: elbarto
# $FreeBSD$

PORTNAME=	asmx
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://xi6.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-CPU macro assembler for many major 8-bit and 16-bit CPUs

OPTIONS_DEFINE=	1802 6502 6809 68HC11 68HC16 8051 8085 F8 Z80 DOCS
OPTIONS_DEFAULT=	1802 6502 6809 68HC11 68HC16 8051 8085 F8 Z80

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

NO_WRKSUBDIR=	yes

PORTDOCS=	README.txt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:M1802}
ALL_TARGET+=	asmx-1802
PLIST_FILES+=	bin/asmx-1802
.endif

.if ${PORT_OPTIONS:M6502}
ALL_TARGET+=	asmx-6502
PLIST_FILES+=	bin/asmx-6502
.endif

.if ${PORT_OPTIONS:M6809}
ALL_TARGET+=	asmx-6809
PLIST_FILES+=	bin/asmx-6809
.endif

.if ${PORT_OPTIONS:M68HC11}
ALL_TARGET+=	asmx-68hc11
PLIST_FILES+=	bin/asmx-68hc11
.endif

.if ${PORT_OPTIONS:M68HC16}
ALL_TARGET+=	asmx-68hc16
PLIST_FILES+=	bin/asmx-68hc16
.endif

.if ${PORT_OPTIONS:M68000}
ALL_TARGET+=	asmx-68k
PLIST_FILES+=	bin/asmx-68k
.endif

.if ${PORT_OPTIONS:M8051}
ALL_TARGET+=	asmx-8051
PLIST_FILES+=	bin/asmx-8051
.endif

.if ${PORT_OPTIONS:M8085}
ALL_TARGET+=	asmx-8085
PLIST_FILES+=	bin/asmx-8085
.endif

.if ${PORT_OPTIONS:MF8}
ALL_TARGET+=	asmx-f8
PLIST_FILES+=	bin/asmx-f8
.endif

.if ${PORT_OPTIONS:MZ80}
ALL_TARGET+=	asmx-z80
PLIST_FILES+=	bin/asmx-z80
.endif

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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
