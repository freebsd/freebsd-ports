# New ports collection makefile for:	sdcc
# Date created:		3 May 2004
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	sdcc
PORTVERSION=	3.1.2.2012.01.22
CATEGORIES=	lang
MASTER_SITES=	SF/sdcc/snapshot_builds/sdcc-src/ \
		http://tijl.fastmail.fm/mirror/
DISTNAME=	${PORTNAME}-src-20120122-7247

MAINTAINER=	tijl@coosemans.org
COMMENT=	Small Device C Compiler

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/adjacency_list.hpp:${PORTSDIR}/devel/boost-libs

WRKSRC=		${WRKDIR}/sdcc

GNU_CONFIGURE=	yes
NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

OPTIONS=	MCS51   "Intel 8051 port" on \
		Z80	"Zilog Z80/Z180, Rabbit 2000 port" on \
		DS390   "Maxim 80DS390/DS400 port" on \
		PIC14	"Microchip PIC16 series port" on \
		PIC16   "Microchip PIC18 series port" on \
		HC08    "Motorola 68HC08 port" on \
		DEVLIB  "Device libraries" on \
		UCSIM	"The ucSim simulator" on

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-avr --docdir=${DOCSDIR} --enable-new-pics
CONFIGURE_ENV=	ARCH=""

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MCS51) && defined(WITHOUT_DS390)
CONFIGURE_ARGS+=	--disable-51
PLIST_SUB+=		MCS51DS390="@comment "
.else
USE_AUTOTOOLS+=		autoconf
PLIST_SUB+=		MCS51DS390=""
.endif

.if defined(WITHOUT_MCS51)
CONFIGURE_ARGS+=	--disable-mcs51-port
PLIST_SUB+=		MCS51="@comment "
.else
PLIST_SUB+=		MCS51=""
.endif

.if defined(WITHOUT_Z80)
CONFIGURE_ARGS+=	--disable-gbz80-port --disable-r2k-port \
			--disable-z180-port --disable-z80-port --disable-z80
PLIST_SUB+=		Z80="@comment "
.else
PLIST_SUB+=		Z80=""
.endif

.if defined(WITHOUT_DS390)
CONFIGURE_ARGS+=	--disable-ds390-port --disable-ds400-port
PLIST_SUB+=		DS390="@comment "
.else
PLIST_SUB+=		DS390=""
.endif

.if defined(WITHOUT_PIC14)
CONFIGURE_ARGS+=	--disable-pic14-port
PLIST_SUB+=		PIC14="@comment "
.else
BUILD_DEPENDS+=		gputils>=0.14.1:${PORTSDIR}/devel/gputils
RUN_DEPENDS+=		gputils>=0.14.1:${PORTSDIR}/devel/gputils
PLIST_SUB+=		PIC14=""
.endif

.if defined(WITHOUT_PIC16)
CONFIGURE_ARGS+=	--disable-pic16-port
PLIST_SUB+=		PIC16="@comment "
.else
BUILD_DEPENDS+=		gputils>=0.14.1:${PORTSDIR}/devel/gputils
RUN_DEPENDS+=		gputils>=0.14.1:${PORTSDIR}/devel/gputils
PLIST_SUB+=		PIC16=""
.endif

.if defined(WITHOUT_HC08)
CONFIGURE_ARGS+=	--disable-hc08-port --disable-hc08
PLIST_SUB+=		HC08="@comment "
.else
PLIST_SUB+=		HC08=""
.endif

.if defined(WITHOUT_DEVLIB)
CONFIGURE_ARGS+=	--disable-device-lib
PLIST_SUB+=		DEVLIB="@comment "
.else
PLIST_SUB+=		DEVLIB=""
.endif

.if defined(WITHOUT_UCSIM)
CONFIGURE_ARGS+=	--disable-ucsim
PLIST_SUB+=		UCSIM="@comment "
.else
USE_AUTOTOOLS+=		libtool
LIBTOOLFILES=		sim/ucsim/configure
PLIST_SUB+=		UCSIM=""
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} 's, [a-z-]*doc,,' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/sim/ucsim/packages_in.mk
.endif

.include <bsd.port.post.mk>
