# New ports collection makefile for:	sdcc
# Date created:		3 May 2004
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	sdcc
PORTVERSION=	2.4.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sdcc

MAINTAINER=	tijl@ulyssis.org
COMMENT=	Small Device C Compiler

WRKSRC=		${WRKDIR}/sdcc

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15

OPTIONS=	MCS51   "Intel mcs51 port" on \
		GBZ80   "Gameboy gbz80 port" on \
		Z80     "Z80 port" on \
		AVR     "AVR port" on \
		DS390   "DS390 port" on \
		DS400   "DS400 port" on \
		PIC     "PIC port" on \
		PIC16   "PIC16 port" on \
		XA51    "XA51 port" on \
		HC08    "HC08 port" on \
		UCSIM   "The ucSim simulator" on \
		PACKIHX "A tool to pack (compress) Intel hex files" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MCS51)
CONFIGURE_ARGS+=	--disable-mcs51-port
PLIST_SUB+=		MCS51="@comment "
.else
PLIST_SUB+=		MCS51=""
.endif

.if defined(WITHOUT_GBZ80)
CONFIGURE_ARGS+=	--disable-gbz80-port
PLIST_SUB+=		GBZ80="@comment "
.else
PLIST_SUB+=		GBZ80=""
.endif

.if defined(WITHOUT_Z80)
CONFIGURE_ARGS+=	--disable-z80-port
PLIST_SUB+=		Z80="@comment "
.else
PLIST_SUB+=		Z80=""
.endif

.if defined(WITHOUT_AVR)
CONFIGURE_ARGS+=	--disable-avr-port
.endif

.if defined(WITHOUT_DS390)
CONFIGURE_ARGS+=	--disable-ds390-port
PLIST_SUB+=		DS390="@comment "
.else
PLIST_SUB+=		DS390=""
.endif

.if defined(WITHOUT_DS400)
CONFIGURE_ARGS+=	--disable-ds400-port
PLIST_SUB+=		DS400="@comment "
.else
PLIST_SUB+=		DS400=""
.endif

.if defined(WITHOUT_PIC)
CONFIGURE_ARGS+=	--disable-pic-port
.endif

.if defined(WITHOUT_PIC16)
CONFIGURE_ARGS+=	--disable-pic16-port
PLIST_SUB+=		PIC16="@comment "
.else
PLIST_SUB+=		PIC16=""
.endif

.if defined(WITHOUT_XA51)
CONFIGURE_ARGS+=	--disable-xa51-port
.endif

.if defined(WITHOUT_HC08)
CONFIGURE_ARGS+=	--disable-hc08-port
PLIST_SUB+=		HC08="@comment "
.else
PLIST_SUB+=		HC08=""
.endif

.if defined(WITHOUT_UCSIM)
CONFIGURE_ARGS+=	--disable-ucsim
PLIST_SUB+=		UCSIM="@comment "
.else
PLIST_SUB+=		UCSIM=""
.endif

.if defined(WITHOUT_PACKIHX)
CONFIGURE_ARGS+=	--disable-packihx
PLIST_SUB+=		PACKIHX="@comment "
.else
PLIST_SUB+=		PACKIHX=""
.endif

.include <bsd.port.post.mk>
