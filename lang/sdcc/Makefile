# $FreeBSD$

PORTNAME=	sdcc
PORTVERSION=	3.9.0
DISTVERSIONPREFIX=src-
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small Device C Compiler

LICENSE=	GPLv3

BROKEN_aarch64=		Fails to configure: BFD does not support target aarch64-portbld-freebsd11.0

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/adjacency_list.hpp:devel/boost-libs

CONFLICTS_INSTALL=	sdcc-[0-9]* sdcc-devel-[0-9]*
GNU_CONFIGURE=	yes
USES=		bison compiler:c++11-lang gmake readline:port python:2.7,run shebangfix tar:bzip2
SHEBANG_FILES=	support/scripts/as2gbmap.py

OPTIONS_DEFINE=		SDCCLIB DEVLIB DOCS UCSIM
OPTIONS_MULTI=		TARGETS
OPTIONS_MULTI_TARGETS=	HC08 MCS51 PADAUK PIC STM8 Z80
OPTIONS_DEFAULT=	SDCCLIB DEVLIB SDCCLIB UCSIM HC08 MCS51 PADAUK PIC STM8 Z80

# XXX libsdcc does not build correctly without this.
SDCCLIB_IMPLIES=MCS51

SDCCLIB_DESC=	Standard C library (libsdcc)
DEVLIB_DESC=	Device libraries
HC08_DESC=	Freescale 68HC08/S08
MCS51_DESC=	Intel MCS51, Maxim DS80C390/DS80C400
PADAUK_DESC=	Padauk PDK14/PDK15
PIC_DESC=	Microchip PIC
STM8_DESC=	STMicroelectronics STM8
UCSIM_DESC=	The ucSim simulator
Z80_DESC=	Zilog Z80/Z180/GBZ80, Rabbit 2000/3000, Toshiba TLCS-90

CONFIGURE_ARGS=	--disable-non-free \
		docdir=${DOCSDIR}
PORTDOCS=	*
WRKSRC=		${WRKDIR}/sdcc-${PORTVERSION}

OPTIONS_SUB=		yes
DEVLIB_CONFIGURE_OFF=	--disable-device-lib
HC08_CONFIGURE_OFF=	--disable-hc08-port --disable-s08-port
MCS51_CONFIGURE_OFF=	--disable-ds390-port --disable-ds400-port	\
			--disable-mcs51-port
PADAUK_CONFIGURE_OFF=	--disable-pdk14-port --disable-pdk15-port
PIC_BUILD_DEPENDS=	gputils>=1.2.0:devel/gputils
PIC_RUN_DEPENDS=	gpasm:devel/gputils
PIC_CONFIGURE_OFF=	--disable-pic14-port --disable-pic16-port
STM8_CONFIGURE_OFF=	--disable-stm8-port
UCSIM_CONFIGURE_OFF=	--disable-ucsim
Z80_CONFIGURE_OFF=	--disable-gbz80-port --disable-r2k-port		\
			--disable-r3ka-port --disable-tlcs90-port	\
			--disable-z180-port --disable-z80-port

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.endif

post-patch:
	@${REINPLACE_CMD} '/install:/s/:.*/:/' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/sdas/linksrc/Makefile.in \
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
# Upstream forgot to run some autotools in this release so make tries to run
# them.  Change a timestamp so aclocal.m4 and Makefile.in no longer appear
# out-of-date.
	@${TOUCH} -r ${WRKSRC}/device/non-free/lib/pic16/configure.ac \
		${WRKSRC}/device/non-free/lib/pic16/supported-devices.ac

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's, [a-z-]*doc,,' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/sim/ucsim/packages_in.mk

post-install:
	${FIND} -d ${STAGEDIR}${DATADIR} -type d -empty -delete

.include <bsd.port.mk>
