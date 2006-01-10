# New ports collection makefile for:	gxemul
# Date created:		15 May 2005
# Whom:			Janni
#
# $FreeBSD$
#

PORTNAME=	gxemul
PORTVERSION=	0.3.7
CATEGORIES=	emulators
MASTER_SITES=	http://gavare.se/gxemul/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Instruction-level machine emulator

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	build

PLIST_FILES=	bin/gxemul
MAN1=		gxemul.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

OPTIONS=	ALWAYS32 "ALWAYS_SIGNEXTEND_32" off \
		BINTRANS "bintrans" on \
		CACHES   "cache emulation (experimental)" off \
		DELAYS   "instruction latency/delay emulation" off \
		TRACENULL "tracenull support" off \
		X        "X11 support" on \
		ALPHA    "Alpha CPU emulation" off \
		ARM      "ARM CPU emulation" on \
		AVR      "AVR CPU emulation" off \
		HPPA     "HPPA CPU emulation" off \
		I960     "i960 CPU emulation" off \
		IA64     "ia64 CPU emulation" off \
		M86K     "m68k CPU emulation" off \
		MIPS     "MIPS CPU emulation" on \
		PPC      "PPC CPU emulation" on \
		SH       "SH CPU emulation" off \
		SPARC    "SPARC CPU emulation" off \
		X86      "x86 CPU emulation" off \
		NEWMIPS  "NEWMIPS CPU emulation (experimental)" off \
		MIPS16   "MIPS16 instruction support (experimental)" off

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 500000 )
USE_GCC=	3.2+
.endif

.if defined(WITH_ALWAYS32)
CONFIGURE_ARGS+=--always32
.endif
.if !defined(WITH_BINTRANS)
CONFIGURE_ARGS+=--disable-bintrans
.endif
.if defined(WITH_CACHES)
CONFIGURE_ARGS+=--enable-caches
.endif
.if defined(WITH_DELAYS)
CONFIGURE_ARGS+=--enable-delays
.endif
.if defined(WITH_TRACENULL)
CONFIGURE_ARGS+=--tracenull
.endif
.if defined(WITH_X)
USE_XLIB=	yes
.else
CONFIGURE_ARGS+=--disable-x
.endif
.if defined(WITH_ALPHA)
CONFIGURE_ARGS+=--enable-alpha
.else
CONFIGURE_ARGS+=--disable-alpha
.endif
.if defined(WITH_ARM)
CONFIGURE_ARGS+=--enable-arm
.else
CONFIGURE_ARGS+=--disable-arm
.endif
.if defined(WITH_AVR)
CONFIGURE_ARGS+=--enable-avr
.else
CONFIGURE_ARGS+=--disable-avr
.endif
.if defined(WITH_HPPA)
CONFIGURE_ARGS+=--enable-hppa
.else
CONFIGURE_ARGS+=--disable-hppa
.endif
.if defined(WITH_I960)
CONFIGURE_ARGS+=--enable-i960
.else
CONFIGURE_ARGS+=--disable-i960
.endif
.if defined(WITH_IA64)
CONFIGURE_ARGS+=--enable-ia64
.else
CONFIGURE_ARGS+=--disable-ia64
.endif
.if defined(WITH_M68K)
CONFIGURE_ARGS+=--enable-m68k
.else
CONFIGURE_ARGS+=--disable-m68k
.endif
.if defined(WITH_MIPS)
CONFIGURE_ARGS+=--enable-mips
.else
CONFIGURE_ARGS+=--disable-mips
.endif
.if defined(WITH_PPC)
CONFIGURE_ARGS+=--enable-ppc
.else
CONFIGURE_ARGS+=--disable-ppc
.endif
.if defined(WITH_SH)
CONFIGURE_ARGS+=--enable-sh
.else
CONFIGURE_ARGS+=--disable-sh
.endif
.if defined(WITH_SPARC)
CONFIGURE_ARGS+=--enable-sparc
.else
CONFIGURE_ARGS+=--disable-sparc
.endif
.if defined(WITH_X86)
CONFIGURE_ARGS+=--enable-x86
.else
CONFIGURE_ARGS+=--disable-x86
.endif

.if defined(WITH_NEWMIPS)
CONFIGURE_ARGS+=--enable-newmips
.endif
.if defined(WITH_MIPS16)
CONFIGURE_ARGS+=--enable-mips16
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|/usr/X11R6|${X11BASE}|g; s|-O[0-9]?||g; s|-f[a-zA-Z-]+||g' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxemul ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/gxemul.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
