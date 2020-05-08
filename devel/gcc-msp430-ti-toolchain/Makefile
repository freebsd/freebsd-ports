# $FreeBSD$

PORTNAME=	gcc-msp430-ti-toolchain
PORTVERSION=	${TI_VERSION}.${RELEASE_DATE}
#PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	GCC/releases/gcc-${GCC_REL_VERSION}:gcc \
		SOURCEWARE/binutils/releases:binutils \
		ftp://sources.redhat.com/pub/:newlib \
		GNU/gdb:gdb \
		SOURCEWARE/newlib:newlib \
		http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/${TI_VERSION_PATCH:S/./_/g}/export/:tipatch \
		http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/${TI_VERSION:S/./_/g}/export/:tisupport \
		http://www.ti.com/lit/ug/slau${DOC_VERSION}/:tidocs
DISTFILES=	gcc-${GCC_REL_VERSION}.tar.xz:gcc \
		binutils-${BINUTILS_VERSION}.tar.bz2:binutils \
		gdb-${GDB_VERSION}.tar.xz:gdb \
		newlib-${NEWLIB_VERSION}.tar.gz:newlib \
		msp430-gcc-${PATCHSET_VERSION}-source-patches.tar.bz2:tipatch \
		msp430-gcc-support-files-${SUPPORT_VERSION}.zip:tisupport \
		slau${DOC_VERSION}.pdf:tidocs
EXTRACT_ONLY=	gcc-${GCC_REL_VERSION}.tar.xz \
		binutils-${BINUTILS_VERSION}.tar.bz2 \
		gdb-${GDB_VERSION}.tar.xz \
		newlib-${NEWLIB_VERSION}.tar.gz \
		msp430-gcc-${PATCHSET_VERSION}-source-patches.tar.bz2 \
		msp430-gcc-support-files-${SUPPORT_VERSION}.zip

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Complete gcc-based toolcahin for TI MSP430 uC

LICENSE=	GPLv2 LGPL20 LGPL21 GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	objdump:devel/binutils
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc \
		libisl.so:devel/isl

# Akami tarpitting fetch by user agent
FETCH_BEFORE_ARGS=	--user-agent=Wget/1.20.3

USES=		bison compiler cpe gmake iconv libtool makeinfo ncurses \
		tar:bzip2
USE_CSTD=	gnu89

GNU_CONFIGURE=		yes

TI_VERSION=		8.3.2.2
TI_VERSION_PATCH=	8.3.1.0
GCC_REL_VERSION=	8.3.0
GCC_VERSION=		8.3.1
SUPPORT_VERSION=	1.209
BINUTILS_VERSION=	2.26
GDB_VERSION=		8.1
NEWLIB_VERSION=		2.4.0
PATCHSET_VERSION=	8.3.1.25
DOC_VERSION=		646e
RELEASE_DATE=		20200313
TARGET=			msp430-elf

CPE_PRODUCT=	gcc
CPE_VENDOR=	gnu
CPE_VERSION=	${GCC_REL_VERSION}

PATCH_WRKSRC=	${WRKDIR}
MANPREFIX=	${PREFIX}/${PORTNAME}-${TI_VERSION}
DOCSDIR=	${PREFIX}/${PORTNAME}-${TI_VERSION}/docs
PLIST_SUB+=	TARGET=${TARGET} GCC_VERSION=${GCC_VERSION} \
		TI_VERSION=${TI_VERSION} DOC_VERSION=${DOC_VERSION}

DIST_PATCH_ARGS=--forward --force --quiet --remove-empty-files --strip=0

UNNEEDED_HOST_FILES=	lib/lib${TARGET}-sim.a
UNNEEDED_HOST_DIRS=	lib/gcc/${TARGET}/${GCC_VERSION}/plugin/include/ada \
			lib/gcc/${TARGET}/${GCC_VERSION}/plugin/include/java \
			lib/gcc/${TARGET}/${GCC_VERSION}/plugin/include/objc \
			include info man share

BUILD_DIR=	${WRKDIR}/build
INTERIM_WORLD=	${WRKDIR}/install
INTERIM_PREFIX=	${INTERIM_WORLD}/${PORTNAME}-${TI_VERSION}

MAKE_ENV=	PATH="${PATH}:${INTERIM_PREFIX}/bin"
CONFIGURE_ENV=	PATH="${PATH}:${INTERIM_PREFIX}/bin"

GCC_DIRS_FROM_NEWLIB=	libgloss newlib

CONFIGURE_ARGS_COMMON=	--prefix=${INTERIM_PREFIX} \
			--target=msp430-elf \
			--enable-languages=c,c++ \
			--disable-nls \
			--enable-initfini-array

pre-patch:
	@${ECHO_MSG} "===> Apply distribution patches..."
	@${ECHO_MSG} "====> Patch gcc"
	@cd ${WRKDIR}/gcc-${GCC_REL_VERSION} && \
	 ${PATCH} ${DIST_PATCH_ARGS} < ${WRKDIR}/msp430-gcc-${PATCHSET_VERSION}-source-patches/gcc-${GCC_REL_VERSION:S/./_/g}-release.patch
	@${ECHO_MSG} "====> Patch binutils"
	@cd ${WRKDIR}/binutils-${BINUTILS_VERSION} && \
	 ${MKDIR} sim/testsuite/sim/msp430 && \
	 ${PATCH} ${DIST_PATCH_ARGS} < ${WRKDIR}/msp430-gcc-${PATCHSET_VERSION}-source-patches/binutils-${BINUTILS_VERSION:S/./_/g}.patch
	@${ECHO_MSG} "====> Patch gdb"
	@cd ${WRKDIR}/gdb-${GDB_VERSION} && \
	 ${MKDIR} gas/config ld/emultempl && \
	 ${PATCH} ${DIST_PATCH_ARGS} < ${WRKDIR}/msp430-gcc-${PATCHSET_VERSION}-source-patches/gdb-${GDB_VERSION}-release.patch
	@${ECHO_MSG} "====> Patch newlib"
	@cd ${WRKDIR}/newlib-${NEWLIB_VERSION} && \
	 ${PATCH} ${DIST_PATCH_ARGS} < ${WRKDIR}/msp430-gcc-${PATCHSET_VERSION}-source-patches/newlib-${NEWLIB_VERSION:S/./_/g}.patch

do-configure:
.for _DIR in ${GCC_DIRS_FROM_NEWLIB}
	@${LN} -fns ${WRKDIR}/newlib-${NEWLIB_VERSION}/${_DIR} ${WRKDIR}/gcc-${GCC_REL_VERSION}/${_DIR}
.endfor
	@${RM} -r ${BUILD_DIR}
	@${MKDIR} ${BUILD_DIR}
	@${RM} -r ${INTERIM_PREFIX}
	@${MKDIR} ${INTERIM_PREFIX}

do-build:
# Build & install binutils
	${MKDIR} ${BUILD_DIR}/binutils
	@cd ${BUILD_DIR}/binutils && \
		${MAKE_ENV} ${CONFIGURE_ENV} ${WRKDIR}/binutils-${BINUTILS_VERSION}/configure \
		 ${CONFIGURE_ARGS_COMMON} \
		 --disable-sim \
		 --disable-gdb \
		 --disable-werror \
		 --with-pkgversion="FreeBSD Ports Collection" \
	         --with-system-zlib
	@cd ${BUILD_DIR}/binutils && \
		${DO_MAKE_BUILD}
	@cd ${BUILD_DIR}/binutils && \
		${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install DESTDIR=''
# Build & install gcc & newlib
	@${MKDIR} ${BUILD_DIR}/gcc
	@cd ${BUILD_DIR}/gcc && \
		${MAKE_ENV} ${CONFIGURE_ENV} ${WRKDIR}/gcc-${GCC_REL_VERSION}/configure \
		 ${CONFIGURE_ARGS_COMMON} \
		 --enable-target-optspace \
		 --enable-newlib-nano-formatted-io \
		 --with-gmp=${PREFIX} \
		 --with-mprf=${PREFIX} \
		 --with-mpc=${PREFIX} \
		 --with-isl=${PREFIX} \
		 --with-pkgversion="FreeBSD Ports Collection" \
		 --with-system-zlib
	@cd ${BUILD_DIR}/gcc && \
		${DO_MAKE_BUILD}
	@cd ${BUILD_DIR}/gcc && \
		${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install DESTDIR=''
# Build & install gdb
	@${MKDIR} ${BUILD_DIR}/gdb
	@cd ${BUILD_DIR}/gdb && \
		${MAKE_ENV} ${CONFIGURE_ENV} ${WRKDIR}/gdb-${GDB_VERSION}/configure \
		 ${CONFIGURE_ARGS_COMMON} \
		 --disable-binutils \
		 --disable-gas \
		 --disable-ld \
		 --disable-gprof \
		 --disable-etc \
		 --without-mpfr \
		 --without-lzma \
		 --with-python=no \
		 --with-pkgversion="FreeBSD Ports Collection" \
		 --with-system-zlib
	@cd ${BUILD_DIR}/gdb && \
		${DO_MAKE_BUILD}
	@cd ${BUILD_DIR}/gdb && \
		${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install DESTDIR=''

do-install:
	@${TAR} -cf - -C ${INTERIM_WORLD} ${PORTNAME}-${TI_VERSION} | ${TAR} -xf - -C ${STAGEDIR}${PREFIX}
	@${ECHO_MSG} "Remove unneeded host files..."
	@for f in ${UNNEEDED_HOST_FILES} ; do \
		${RM} "${STAGEDIR}${PREFIX}/$$f" ; \
	done
	@for f in ${UNNEEDED_HOST_DIRS} ; do \
		${RM} -r "${STAGEDIR}${PREFIX}/$$f" ; \
	done
	@${ECHO_MSG} "Install devices' headers and linker scripts..."
	@${MKDIR} ${STAGEDIR}${PREFIX}/include
	cd ${WRKDIR}/msp430-gcc-support-files && \
		${TAR} cf - . | \
		${TAR} xf - -C ${STAGEDIR}${PREFIX}/${PORTNAME}-${TI_VERSION}
	@${ECHO_MSG} "Install minimal documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/slau${DOC_VERSION}.pdf \
		${STAGEDIR}${DOCSDIR}/slau${DOC_VERSION}.pdf
	${INSTALL_DATA} ${FILESDIR}/watchdog.txt ${STAGEDIR}${DOCSDIR}/watchdog.txt

.include <bsd.port.mk>
