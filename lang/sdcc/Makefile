# New ports collection makefile for:	sdcc
# Date created:		3 May 2004
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	sdcc
PORTVERSION=	3.2.0
DISTVERSIONPREFIX=	src-
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	tijl@coosemans.org
COMMENT=	Small Device C Compiler

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/adjacency_list.hpp:${PORTSDIR}/devel/boost-libs

CONFLICTS_INSTALL=	sdcc-[0-9]*
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GCC=	4.6+

OPTIONS_DEFINE= DEVLIB DOCS HC08 MCS51 PIC UCSIM Z80
OPTIONS_DEFAULT=${OPTIONS_DEFINE:NDOCS}
DEVLIB_DESC=	Device libraries
HC08_DESC=	Freescale 68HC08/S08
MCS51_DESC=	Intel MCS51, Maxim DS80C390/DS80C400
PIC_DESC=	Microchip PIC
UCSIM_DESC=	The ucSim simulator
Z80_DESC=	Zilog Z80/Z180/GBZ80, Rabbit 2000/3000/3000A

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS= --disable-avr --disable-install-libbfd --disable-werror
CONFIGURE_ENV=	ARCH=""
WRKSRC= 	${WRKDIR}/sdcc

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

.if ${PORT_OPTIONS:MDEVLIB}
PLIST_SUB+=	DEVLIB=""
.else
CONFIGURE_ARGS+=--disable-device-lib
PLIST_SUB+=	DEVLIB="@comment "
.endif

.if ${PORT_OPTIONS:MHC08}
PLIST_SUB+=	HC08=""
.else
CONFIGURE_ARGS+=--disable-hc08 --disable-hc08-port --disable-s08-port
PLIST_SUB+=	HC08="@comment "
.endif

.if ${PORT_OPTIONS:MMCS51}
PLIST_SUB+=	MCS51=""
.else
CONFIGURE_ARGS+=--disable-51 --disable-mcs51-port \
		--disable-ds390-port --disable-ds400-port
PLIST_SUB+=	MCS51="@comment "
.endif

.if ${PORT_OPTIONS:MPIC}
BUILD_DEPENDS+= gputils>=0.14.2:${PORTSDIR}/devel/gputils
RUN_DEPENDS+=	gputils>=0.14.2:${PORTSDIR}/devel/gputils
PLIST_SUB+=	PIC=""
.else
CONFIGURE_ARGS+=--disable-pic14-port --disable-pic16-port
PLIST_SUB+=	PIC="@comment "
.endif

.if ${PORT_OPTIONS:MUCSIM}
PLIST_SUB+=	UCSIM=""
.else
CONFIGURE_ARGS+=--disable-ucsim
PLIST_SUB+=	UCSIM="@comment "
.endif

.if ${PORT_OPTIONS:MZ80}
PLIST_SUB+=	Z80=""
.else
CONFIGURE_ARGS+=--disable-z80 --disable-z80-port --disable-z180-port \
		--disable-gbz80-port --disable-r2k-port --disable-r3ka-port
PLIST_SUB+=	Z80="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} '/install:/s/:.*/:/' \
		${WRKSRC}/support/sdbinutils/libiberty/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} 's, [a-z-]*doc,,' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/sim/ucsim/packages_in.mk
.endif

.include <bsd.port.post.mk>
