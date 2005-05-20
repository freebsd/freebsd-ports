# New ports collection makefile for:	gxemul
# Date created:		15 May 2005
# Whom:			Janni
#
# $FreeBSD$
#

PORTNAME=	gxemul
PORTVERSION=	0.3.2
CATEGORIES=	emulators
MASTER_SITES=	http://gavare.se/gxemul/src/

MAINTAINER=	jannisan@t-online.de
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
		X        "X11 support" on \
		ALPHA    "Alpha CPU emulation" off \
		HPPA     "HPPA CPU emulation" off \
		MIPS     "MIPS CPU emulation" on \
		PPC      "PPC CPU emulation" on \
		SPARC    "SPARC CPU emulation" off \
		URISC    "URISC CPU emulation" on \
		X86      "x86 CPU emulation" off \
		MIPS16   "MIPS16 instruction support (experimental)" off

.include <bsd.port.pre.mk>

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
.if defined(WITH_X)
USE_XLIB=	yes
.else
CONFIGURE_ARGS+=--disable-x
.endif
.if defined(WITH_ALPHA)
CONFIGURE_ARGS+=--enable-alpha
.endif
.if defined(WITH_HPPA)
CONFIGURE_ARGS+=--enable-hppa
.endif
.if !defined(WITH_MIPS)
CONFIGURE_ARGS+=--disable-mips
.endif
.if !defined(WITH_PPC)
CONFIGURE_ARGS+=--disable-ppc
.endif
.if defined(WITH_SPARC)
CONFIGURE_ARGS+=--enable-sparc
.endif
.if !defined(WITH_URISC)
CONFIGURE_ARGS+=--disable-urisc
.endif
.if defined(WITH_X86)
CONFIGURE_ARGS+=--enable-x86
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
