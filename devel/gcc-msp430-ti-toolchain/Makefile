# $FreeBSD$

PORTNAME=	gcc-msp430-ti-toolchain
PORTVERSION=	${GCC_VERSION}.${TI_VERSION}.${RELEASE_DATE}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/${TI_VERSION:S/./_/g}/exports/ \
		http://www.ti.com/lit/ml/slau591a/:docs
DISTFILES=	msp430-gcc-source.tar.bz2 \
		msp430-gcc-support-files.zip \
		slau591a.pdf:docs
DIST_SUBDIR=	mspgcc${TI_VERSION}
EXTRACT_ONLY=	msp430-gcc-source.tar.bz2 \
		msp430-gcc-support-files.zip

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Complete gcc-based toolcahin for TI MSP430 uC

LICENSE=	GPLv2 LGPL20 LGPL21 GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	expect:${PORTSDIR}/lang/expect

OPTIONS_DEFINE=	INSIGHT PURE
OPTIONS_DEFAULT=
INSIGHT_DESC=	Build graphical version of gdb (Insight), needs X11 and TK
PURE_DESC=	Use all libraries from bundle, do not depend on anything
OPTIONS_SUB=	yes

INSIGHT_CONFIGURE_WITH=		x
INSIGHT_CONFIGURE_ENABLE=	gdbtk
INSIGHT_USE=			XORG=x11

PURE_CONFIGURE_OFF=	--with-gmp=${PREFIX} \
			--with-mprf=${PREFIX} \
			--with-mpc=${PREFIX}
PURE_LIB_DEPENDS_OFF=	libgmp.so:${PORTSDIR}/math/gmp \
			libmpfr.so:${PORTSDIR}/math/mpfr \
			libmpc.so:${PORTSDIR}/math/mpc
PURE_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-libgui_configure \
			${PATCHDIR}/extra-patch-gdb_configure

USES=		bison compiler cpe flex gmake libtool makeinfo tar:bzip2
USE_CSTD=	gnu89

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/${SUBPREFIX}
CONFIGURE_ARGS=	--target=${TARGET} \
		--enable-languages=c,c++ \
		--disable-nls

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MPURE} && ${PORT_OPTIONS:MINSIGHT}
RUN_DEPENDS+=		iwidgets>0:${PORTSDIR}/x11-toolkits/iwidgets
USES+=			tk:84+
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} \
			--with-tk=${TK_LIBDIR}
.endif

.include "bsd.port.pre.mk"

GCC_VERSION=	4.9.1
TI_VERSION=	3.05.00.00
RELEASE_DATE=	20150915
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

UNNEEDED_HOST_FILES=	lib/lib${TARGET}-sim.a

.if ${PORT_OPTIONS:MPURE} && ${PORT_OPTIONS:MINSIGHT}
UNNEEDED_HOST_FILES+=	lib/libtcl8.4.a lib/libtclstub8.4.a \
			lib/libtk8.4.a lib/libtkstub8.4.a \
			lib/tclConfig.sh lib/tkConfig.sh \
			lib/itclConfig.sh lib/itcl3.3/libitclstub3.3.a
.endif

UNNEEDED_HOST_DIRS=	include info man share

pre-extract:
	@${MKDIR} ${BUILD_WRKSRC}

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
	cd ${WRKDIR}/msp430-gcc-support-files && \
		${TAR} cf - . | \
		${TAR} xf - -C ${STAGEDIR}${GNU_CONFIGURE_PREFIX}/include
	@${ECHO_MSG} "Install minimal documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/slau591a.pdf \
		${STAGEDIR}${DOCSDIR}/slau591a.pdf
	${INSTALL_MAN} ${FILESDIR}/watchdog.txt \
		${STAGEDIR}${DOCSDIR}/watchdog.txt

post-patch-PURE-off:
	@${RM} -rf ${WRKSRC}/gmp ${WRKSRC}/mpfr ${WRKSRC}/mpc \
		${WRKSRC}/tcl ${WRKSRC}/tk ${WRKSRC}/itcl

.include <bsd.port.post.mk>
