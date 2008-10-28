# New ports collection makefile for:   asmx
# Date created:        28 October 2008
# Whom:                elbarto
#
# $FreeBSD$
#

PORTNAME=	asmx
PORTVERSION=	1.8.2
CATEGORIES=	devel
MASTER_SITES=	http://xi6.com/files/ \
		http://distfiles.arcadebsd.org/

MAINTAINER=	elbarto@ArcadeBSD.org
COMMENT=	Multi-CPU macro assembler for many major 8-bit and 16-bit CPUs

WRKSRC=		${WRKDIR}
USE_ZIP=	yes
ALL_TARGET=

PORTDOCS=	README.txt

OPTIONS=	1802 "RCA 1802" On \
		6502 "MOS Technology 6502, 65C02 and 6502" On \
		6809 "Motorola 6809" On \
		68HC11 "Motorola 6800/6801/68HC11 and Hitachi 6303" On \
		68HC16 "Motorola 68HC16" On \
		68000 "Motorola 68000/68010" On \
		8051 "Intel 8051" On \
		8085 "Intel 8080 and 8085" On \
		F8 "Fairchild F8" On \
		Z80 "Zilog Z-80 and Nintendo Gameboy Z-80 variant" On

.include <bsd.port.pre.mk>

.if defined(WITH_1802)
ALL_TARGET+=	asmx-1802
PLIST_FILES+=	bin/asmx-1802
.endif

.if defined(WITH_6502)
ALL_TARGET+=	asmx-6502
PLIST_FILES+=	bin/asmx-6502
.endif

.if defined(WITH_6809)
ALL_TARGET+=	asmx-6809
PLIST_FILES+=	bin/asmx-6809
.endif

.if defined(WITH_68HC11)
ALL_TARGET+=	asmx-68hc11
PLIST_FILES+=	bin/asmx-68hc11
.endif

.if defined(WITH_68HC16)
ALL_TARGET+=	asmx-68hc16
PLIST_FILES+=	bin/asmx-68hc16
.endif

.if defined(WITH_68000)
ALL_TARGET+=	asmx-68k
PLIST_FILES+=	bin/asmx-68k
.endif

.if defined(WITH_8051)
ALL_TARGET+=	asmx-8051
PLIST_FILES+=	bin/asmx-8051
.endif

.if defined(WITH_8085)
ALL_TARGET+=	asmx-8085
PLIST_FILES+=	bin/asmx-8085
.endif

.if defined(WITH_F8)
ALL_TARGET+=	asmx-f8
PLIST_FILES+=	bin/asmx-f8
.endif

.if defined(WITH_Z80)
ALL_TARGET+=	asmx-z80
PLIST_FILES+=	bin/asmx-z80
.endif

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

pre-build:
	${ECHO_CMD} ALL_TARGET=${ALL_TARGET}

do-install:
.for f in ${ALL_TARGET}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
