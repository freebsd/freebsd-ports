# $FreeBSD$

PORTNAME=	sdcc
PORTVERSION=	3.6.1.2016.07.08
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	SF/sdcc/snapshot_builds/sdcc-src/ \
		http://tijl.fastmail.com/mirror/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-src-20160708-9632

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Small Device C Compiler

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/adjacency_list.hpp:devel/boost-libs

CONFLICTS_INSTALL=	sdcc-[0-9]*
DESCR=		${PORTSDIR}/lang/sdcc/pkg-descr
GNU_CONFIGURE=	yes
USES=		gmake readline:port tar:bzip2

OPTIONS_DEFINE=		DEVLIB DOCS UCSIM
OPTIONS_MULTI=		TARGETS
OPTIONS_MULTI_TARGETS=	HC08 MCS51 PIC STM8 Z80
OPTIONS_DEFAULT=	DEVLIB UCSIM HC08 MCS51 PIC STM8 Z80
DEVLIB_DESC=	Device libraries
HC08_DESC=	Freescale 68HC08/S08
MCS51_DESC=	Intel MCS51, Maxim DS80C390/DS80C400
PIC_DESC=	Microchip PIC
STM8_DESC=	STMicroelectronics STM8
UCSIM_DESC=	The ucSim simulator
Z80_DESC=	Zilog Z80/Z180/GBZ80, Rabbit 2000/3000, Toshiba TLCS-90

CONFIGURE_ARGS=	--disable-avr --disable-install-libbfd --disable-werror \
		--disable-st7 docdir=${DOCSDIR} sdcc_cv_c_fms_extensions=no
PORTDATA=	*
PORTDOCS=	*
WRKSRC=		${WRKDIR}/sdcc

OPTIONS_SUB=		yes
DEVLIB_CONFIGURE_OFF=	--disable-device-lib
HC08_CONFIGURE_OFF=	--disable-hc08 --disable-hc08-port		\
			--disable-s08-port
MCS51_CONFIGURE_OFF=	--disable-51 --disable-mcs51-port		\
			--disable-ds390-port --disable-ds400-port
PIC_BUILD_DEPENDS=	gputils>=1.2.0:devel/gputils
PIC_RUN_DEPENDS=	gpasm:devel/gputils
PIC_CONFIGURE_OFF=	--disable-pic14-port --disable-pic16-port
STM8_CONFIGURE_OFF=	--disable-stm8 --disable-stm8-port
UCSIM_CONFIGURE_OFF=	--disable-ucsim
Z80_CONFIGURE_OFF=	--disable-z80 --disable-z80-port		\
			--disable-z180-port --disable-gbz80-port	\
			--disable-r2k-port --disable-r3ka-port		\
			--disable-tlcs90-port

BROKEN_aarch64=		Fails to configure: BFD does not support target aarch64-portbld-freebsd11.0

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.endif

post-patch:
	@${REINPLACE_CMD} '/install:/s/:.*/:/' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/support/sdbinutils/libiberty/Makefile.in
	@${REINPLACE_CMD} '/^SUBDIRS =/s/doc//' \
		${WRKSRC}/support/sdbinutils/bfd/Makefile.in
	@${REINPLACE_CMD} 's/[[:<:]]ARCH[[:>:]]/PICARCH/g' \
		${WRKSRC}/device/lib/pic14/Makefile.common \
		${WRKSRC}/device/lib/pic14/Makefile.in \
		${WRKSRC}/device/lib/pic14/configure \
		${WRKSRC}/device/lib/pic14/libm/Makefile.in \
		${WRKSRC}/device/lib/pic14/libsdcc/enhanced/Makefile.in \
		${WRKSRC}/device/lib/pic14/libsdcc/enhanced-no-xinst/Makefile.in \
		${WRKSRC}/device/lib/pic14/libsdcc/regular/Makefile.in \
		${WRKSRC}/device/lib/pic16/Makefile.in \
		${WRKSRC}/device/lib/pic16/configure \
		${WRKSRC}/device/lib/pic16/debug/Makefile.in \
		${WRKSRC}/device/lib/pic16/libc/Makefile.in \
		${WRKSRC}/device/lib/pic16/libio/Makefile.in \
		${WRKSRC}/device/lib/pic16/libm/Makefile.in \
		${WRKSRC}/device/lib/pic16/libsdcc/Makefile.in \
		${WRKSRC}/device/lib/pic16/startup/Makefile.in \
		${WRKSRC}/device/non-free/lib/pic14/Makefile.common.in \
		${WRKSRC}/device/non-free/lib/pic14/Makefile.rules \
		${WRKSRC}/device/non-free/lib/pic16/Makefile.in \
		${WRKSRC}/device/non-free/lib/pic16/configure \
		${WRKSRC}/device/non-free/lib/pic16/libdev/Makefile.in
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} 's, [a-z-]*doc,,' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/sim/ucsim/packages_in.mk
.endif

post-install:
	${FIND} -d ${STAGEDIR}${DATADIR} -type d -empty -delete

.include <bsd.port.mk>
