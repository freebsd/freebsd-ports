PORTNAME=	sdcc
PORTVERSION=	4.0.0
DISTVERSIONPREFIX=src-
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	darius@dons.net.au
COMMENT=	Small Device C Compiler
WWW=		https://sdcc.sourceforge.net/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv3=	${WRKSRC}/sdas/COPYING3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/adjacency_list.hpp:devel/boost-libs

CONFLICTS_INSTALL=	sdcc sdcc-devel
GNU_CONFIGURE=	yes
USES=		autoreconf:build bison compiler:c++11-lang gmake \
		readline python shebangfix tar:bzip2
SHEBANG_FILES=	support/scripts/as2gbmap.py
TEST_WRKSRC=	${WRKSRC}/support/regression
TEST_ARGS=	--no-print-directory # tons of them, way too annoying
TEST_TARGET=	all

OPTIONS_DEFINE=		SDCCLIB DEVLIB DOCS UCSIM
OPTIONS_MULTI=		TARGETS
OPTIONS_MULTI_TARGETS=	HC08 MCS51 PADAUK PIC STM8 Z80
OPTIONS_DEFAULT=	SDCCLIB DEVLIB UCSIM HC08 MCS51 PADAUK PIC STM8 Z80

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

CONFIGURE_ARGS=	--enable-non-free \
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

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's, [a-z-]*doc,,' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/sim/ucsim/packages_in.mk

pre-configure:
	cd ${WRKSRC}/device/lib/pic14 && ${AUTORECONF} -f -i

post-install:
	${FIND} -d ${STAGEDIR}${DATADIR} -type d -empty -delete

.include <bsd.port.mk>
