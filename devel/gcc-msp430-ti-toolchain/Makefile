# $FreeBSD$

PORTNAME=	gcc-msp430-ti-toolchain
PORTVERSION=	${GCC_VERSION}.${TI_VERSION}.${RELEASE_DATE}
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/${TI_VERSION:S/./_/g}/exports/ \
		http://www.ti.com/lit/ml/slau591b/:docs
DISTFILES=	msp430-gcc-source.tar.bz2 \
		msp430-gcc-support-files.zip \
		slau591b.pdf:docs
DIST_SUBDIR=	mspgcc${TI_VERSION}
EXTRACT_ONLY=	msp430-gcc-source.tar.bz2 \
		msp430-gcc-support-files.zip

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Complete gcc-based toolcahin for TI MSP430 uC

LICENSE=	GPLv2 LGPL20 LGPL21 GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	expect:lang/expect \
		flex:textproc/flex

#OPTIONS_DEFINE=	INSIGHT PURE
OPTIONS_DEFINE=	PURE
OPTIONS_DEFAULT=
#INSIGHT_DESC=	Build graphical version of gdb (Insight), needs X11 and TK
PURE_DESC=	Use all libraries from bundle, do not depend on anything
OPTIONS_SUB=	yes

#INSIGHT_CONFIGURE_WITH=	x
#INSIGHT_CONFIGURE_ENABLE=	gdbtk
#INSIGHT_USE=			XORG=x11

PURE_CONFIGURE_OFF=	--with-gmp=${PREFIX} \
			--with-mprf=${PREFIX} \
			--with-mpc=${PREFIX}
PURE_LIB_DEPENDS_OFF=	libgmp.so:math/gmp \
			libmpfr.so:math/mpfr \
			libmpc.so:math/mpc
PURE_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-libgui_configure \
			${PATCHDIR}/extra-patch-gdb_configure

NOT_FOR_ARCHS=		aarch64 arm armeb armv6 armv6hf \
			mips mips64 mips64el mipsel mipsn32
NOT_FOR_ARCHS_REASON=	Very slow to build on emulator

USES=		bison compiler cpe gmake libtool makeinfo ncurses tar:bzip2
USE_CSTD=	gnu89

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/${SUBPREFIX}
CONFIGURE_ARGS=	--target=${TARGET} \
		--enable-languages=c,c++ \
		--disable-nls

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

#.if !${PORT_OPTIONS:MPURE} && ${PORT_OPTIONS:MINSIGHT}
#RUN_DEPENDS+=		iwidgets>0:x11-toolkits/iwidgets
#USES+=			tk:84+
#CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} \
#			--with-tk=${TK_LIBDIR}
#.endif

.include "bsd.port.pre.mk"

GCC_VERSION=	5.3.0
TI_VERSION=	4.00.01.00
RELEASE_DATE=	20160401
TARGET=		msp430-elf

CPE_PRODUCT=	gcc
CPE_VENDOR=	gnu
CPE_VERSION=	${GCC_VERSION}

WRKSRC=		${WRKDIR}/sources/tools
CONFIGURE_WRKSRC=${WRKDIR}/build
CONFIGURE_SCRIPT=../sources/tools/configure
BUILD_WRKSRC=	${WRKDIR}/build
INSTALL_WRKSRC=	${WRKDIR}/build

SUBPREFIX=	${PORTNAME}-${TI_VERSION}

MANPREFIX=	${GNU_CONFIGURE_PREFIX}
DOCSDIR=	${GNU_CONFIGURE_PREFIX}/docs
PLIST_SUB+=	TARGET=${TARGET} GCC_VERSION=${GCC_VERSION} \
		TI_VERSION=${TI_VERSION}
PLIST_SUB+=	INSIGHT="@comment "

UNNEEDED_HOST_FILES=	lib/lib${TARGET}-sim.a

#.if ${PORT_OPTIONS:MPURE} && ${PORT_OPTIONS:MINSIGHT}
#UNNEEDED_HOST_FILES+=	lib/libtcl8.4.a lib/libtclstub8.4.a \
#			lib/tclConfig.sh
#.if ${PORT_OPTIONS:MINSIGHT}
#UNNEEDED_HOST_FILES+=	lib/libtk8.4.a lib/libtkstub8.4.a \
#			lib/tkConfig.sh \
#			lib/itclConfig.sh lib/itcl3.3/libitclstub3.3.a
#.endif
#.endif

UNNEEDED_HOST_DIRS=	include info man share

pre-extract:
	@${MKDIR} ${BUILD_WRKSRC}

# Till we don't have Insight, we don't need to build tcl anyway
post-patch:
	@${RM} -rf ${WRKSRC}/tcl ${WRKSRC}/tk ${WRKSRC}/itcl \
		${WRKSRC}/libgui

post-patch-PURE-off:
	@${RM} -rf ${WRKSRC}/gmp ${WRKSRC}/mpfr ${WRKSRC}/mpc

post-stage:
	@${ECHO_MSG} "Remove unneeded host files..."
	@for f in ${UNNEEDED_HOST_FILES} ; do \
		${RM} "${STAGEDIR}${GNU_CONFIGURE_PREFIX}/$$f" ; \
	done
	@for f in ${UNNEEDED_HOST_DIRS} ; do \
		${RM} -rf "${STAGEDIR}${GNU_CONFIGURE_PREFIX}/$$f" ; \
	done
	@${ECHO_MSG} "Install devices' headers and linker scripts..."
	@${MKDIR} ${STAGEDIR}${GNU_CONFIGURE_PREFIX}/include
	cd ${WRKDIR}/GCC_RH && \
		${TAR} cf - . | \
		${TAR} xf - -C ${STAGEDIR}${GNU_CONFIGURE_PREFIX}
	@${ECHO_MSG} "Install minimal documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/slau591b.pdf \
		${STAGEDIR}${DOCSDIR}/slau591b.pdf
	${INSTALL_MAN} ${FILESDIR}/watchdog.txt \
		${STAGEDIR}${DOCSDIR}/watchdog.txt

.include <bsd.port.post.mk>
