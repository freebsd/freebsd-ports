# $FreeBSD$

PORTNAME=	gcc-msp430-ti-toolchain
PORTVERSION=	${GCC_VERSION}.${TI_VERSION}.${RELEASE_DATE}
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	GCC/releases/gcc-${GCC_VERSION}:gcc \
		SOURCEWARE/binutils/releases:binutils \
		ftp://sources.redhat.com/pub/:newlib \
		GNU/gdb:gdb \
		SOURCEWARE/newlib:newlib \
		http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/${TI_VERSION:S/./_/g}/exports/:ti \
		http://www.ti.com/lit/ml/slau591${DOC_VERSION}/:docs
DISTFILES=	gcc-${GCC_VERSION}.tar.bz2:gcc \
		binutils-${BINUTILS_VERSION}.tar.bz2:binutils \
		gdb-${GDB_VERSION}.tar.bz2:gdb \
		newlib-${NEWLIB_VERSION}.tar.gz:newlib \
		msp430-gcc-${PATCHSET_VERSION}_source-patches.tar.bz2:ti \
		msp430-gcc-support-files-${SUPPORT_VERSION}.zip:ti \
		slau591${DOC_VERSION}.pdf:docs
EXTRACT_ONLY=	gcc-${GCC_VERSION}.tar.bz2 \
		binutils-${BINUTILS_VERSION}.tar.bz2 \
		gdb-${GDB_VERSION}.tar.bz2 \
		newlib-${NEWLIB_VERSION}.tar.gz \
		msp430-gcc-${PATCHSET_VERSION}_source-patches.tar.bz2 \
		msp430-gcc-support-files-${SUPPORT_VERSION}.zip
MAINTAINER=	lev@FreeBSD.org
COMMENT=	Complete gcc-based toolcahin for TI MSP430 uC

LICENSE=	GPLv2 LGPL20 LGPL21 GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc \
		libisl.so:devel/isl

USES=		bison compiler cpe gmake iconv libtool makeinfo ncurses \
		tar:bzip2
USE_CSTD=	gnu89

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/${SUBPREFIX}

TI_VERSION=		4.02.00.00
GCC_VERSION=		5.3.0
SUPPORT_VERSION=	1.194
BINUTILS_VERSION=	2.25.1
GDB_VERSION=		7.7
NEWLIB_VERSION=		2.2.0
PATCHSET_VERSION=	5.3.0.224
DOC_VERSION=		c
RELEASE_DATE=		20161108
TARGET=			msp430-elf

CPE_PRODUCT=	gcc
CPE_VENDOR=	gnu
CPE_VERSION=	${GCC_VERSION}

SUBPREFIX=	${PORTNAME}-${TI_VERSION}

MANPREFIX=	${GNU_CONFIGURE_PREFIX}
DOCSDIR=	${GNU_CONFIGURE_PREFIX}/docs
PLIST_SUB+=	TARGET=${TARGET} GCC_VERSION=${GCC_VERSION} \
		TI_VERSION=${TI_VERSION} DOC_VERSION=${DOC_VERSION}

DIST_PATCH_ARGS=--forward --force --quiet --remove-empty-files --strip 1

UNNEEDED_HOST_FILES=	lib/lib${TARGET}-sim.a
UNNEEDED_HOST_DIRS=	lib/gcc/${TARGET}/${GCC_VERSION}/plugin/include/ada \
			lib/gcc/${TARGET}/${GCC_VERSION}/plugin/include/java \
			lib/gcc/${TARGET}/${GCC_VERSION}/plugin/include/objc \
			include info man share

GCC_DIRS_FROM_BINUTILS=	bfd binutils gas gprof ld opcodes
GCC_DIRS_FROM_NEWLIB=	libgloss newlib

pre-patch:
	@${ECHO_MSG} "===> Apply distribution patches..."
	@${ECHO_MSG} "====> Patch gcc"
	@cd ${WRKDIR}/gcc-${GCC_VERSION} && \
	 ${PATCH} ${DIST_PATCH_ARGS} < ${WRKDIR}/msp430-gcc-${PATCHSET_VERSION}_source-patches/gcc_${GCC_VERSION:S/./_/g}_release.diff
	# binutils patch contains chunks for files not included into distirbution
	@${ECHO_MSG} "====> Patch binutils (ignore error message, please)"
	-@cd ${WRKDIR}/binutils-${BINUTILS_VERSION} && \
	 ${MKDIR} sim/testsuite/sim/msp430 && \
	 ${PATCH} ${DIST_PATCH_ARGS} < ${WRKDIR}/msp430-gcc-${PATCHSET_VERSION}_source-patches/binutils-${BINUTILS_VERSION:S/./_/g}.diff > /dev/null 2>&1
 	# gdb patch contains chunks for files not included into distirbution
	@${ECHO_MSG} "====> Patch gdb (ignore error message, please)"
	-@cd ${WRKDIR}/gdb-${GDB_VERSION} && \
	 ${MKDIR} gas/config ld/emultempl && \
	 ${PATCH} ${DIST_PATCH_ARGS} < ${WRKDIR}/msp430-gcc-${PATCHSET_VERSION}_source-patches/gdb-${GDB_VERSION}-release.diff > /dev/null 2>&1
	@${ECHO_MSG} "====> Patch newlib"
	@cd ${WRKDIR}/newlib-${NEWLIB_VERSION} && \
	 ${PATCH} ${DIST_PATCH_ARGS} < ${WRKDIR}/msp430-gcc-${PATCHSET_VERSION}_source-patches/newlib-${NEWLIB_VERSION:S/./_/g}.diff

pre-configure:
.for _DIR in ${GCC_DIRS_FROM_BINUTILS}
	@${LN} -fns ${WRKDIR}/binutils-${BINUTILS_VERSION}/${_DIR} ${WRKDIR}/gcc-${GCC_VERSION}/${_DIR}
.endfor
.for _DIR in ${GCC_DIRS_FROM_NEWLIB}
	@${LN} -fns ${WRKDIR}/newlib-${NEWLIB_VERSION}/${_DIR} ${WRKDIR}/gcc-${GCC_VERSION}/${_DIR}
.endfor
	@${MKDIR} ${WRKDIR}/build/gcc ${WRKDIR}/build/gdb

do-configure:
	@cd ${WRKDIR}/build/gcc && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${WRKDIR}/gcc-${GCC_VERSION}/configure \
	  --prefix=${PREFIX}/${SUBPREFIX} \
	  --target=msp430-elf \
	  --enable-languages=c,c++ \
	  --disable-nls \
	  --enable-target-optspace \
	  --enable-newlib-nano-formatted-io \
	  --with-gmp=${PREFIX} \
	  --with-mprf=${PREFIX} \
	  --with-mpc=${PREFIX} \
	  --with-isl=${PREFIX} \
	  --with-pkgversion="FreeBSD Ports Collection" \
	  --with-system-zlib
	@cd ${WRKDIR}/build/gdb && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${WRKDIR}/gdb-${GDB_VERSION}/configure \
	  --prefix=${PREFIX}/${SUBPREFIX} \
	  --target=msp430-elf \
	  --enable-languages=c,c++ \
	  ${ICONV_CONFIGURE_ARG} \
	  --disable-nls \
	  --disable-binutils \
	  --disable-gas \
	  --disable-ld \
	  --disable-gprof \
	  --disable-etc \
	  --with-pkgversion="FreeBSD Ports Collection"

do-build:
	@cd ${WRKDIR}/build/gcc && \
	 ${DO_MAKE_BUILD}
	@cd ${WRKDIR}/build/gdb && \
	 ${DO_MAKE_BUILD}

do-install:
	@cd ${WRKDIR}/build/gcc && \
	 ${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install
	@cd ${WRKDIR}/build/gdb && \
	 ${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install

post-stage:
	@${ECHO_MSG} "Remove unneeded host files..."
	@for f in ${UNNEEDED_HOST_FILES} ; do \
		${RM} "${STAGEDIR}${GNU_CONFIGURE_PREFIX}/$$f" ; \
	done
	@for f in ${UNNEEDED_HOST_DIRS} ; do \
		${RM} -r "${STAGEDIR}${GNU_CONFIGURE_PREFIX}/$$f" ; \
	done
	@${ECHO_MSG} "Install devices' headers and linker scripts..."
	@${MKDIR} ${STAGEDIR}${GNU_CONFIGURE_PREFIX}/include
	cd ${WRKDIR}/msp430-gcc-support-files && \
		${TAR} cf - . | \
		${TAR} xf - -C ${STAGEDIR}${GNU_CONFIGURE_PREFIX}
	@${ECHO_MSG} "Install minimal documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/slau591${DOC_VERSION}.pdf \
		${STAGEDIR}${DOCSDIR}/slau591c.pdf
	${INSTALL_MAN} ${FILESDIR}/watchdog.txt \
		${STAGEDIR}${DOCSDIR}/watchdog.txt

.include <bsd.port.mk>
