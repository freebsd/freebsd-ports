# New ports collection makefile for:	gxemul
# Date created:		15 May 2005
# Whom:			Janni
#
# $FreeBSD$
#

PORTNAME=	gxemul
PORTVERSION=	0.3.8
CATEGORIES=	emulators
MASTER_SITES=	http://gavare.se/gxemul/src/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	Instruction-level machine emulator

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
		MIPS16   "MIPS16 instruction support (experimental)" off \
		NEWMIPS  "new MIPS CPU emulation code (experimental)" off \
		X        "X11 support" on

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
.if defined(WITH_X)
USE_XLIB=	yes
.else
CONFIGURE_ARGS+=--disable-x
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
