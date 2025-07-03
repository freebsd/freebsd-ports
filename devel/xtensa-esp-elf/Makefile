PORTNAME=	xtensa-esp-elf
DISTVERSION=	13.2.0_20240530
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	https://github.com/espressif/crosstool-NG/releases/download/esp-${DISTVERSION}/:source1 \
		GNU/gmp:source2 \
		https://libisl.sourceforge.io/:source3 \
		GNU/mpc:source4 \
		GNU/mpfr:source5 \
		https://github.com/madler/zlib/releases/download/v1.2.13/:source6 \
		https://github.com/facebook/zstd/releases/download/v1.5.5/:source7
DISTNAME=	crosstool-NG-esp-${DISTVERSION}-src
EXTRACT_SUFX=	.tar.xz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source1 \
		gmp-6.2.1.tar.bz2:source2 \
		isl-0.26.tar.gz:source3 \
		mpc-1.2.1.tar.gz:source4 \
		mpfr-4.2.1.zip:source5 \
		zlib-1.2.13.tar.xz:source6 \
		zstd-1.5.5.tar.gz:source7
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		espressif-esp-toolchain-bin-wrappers-${TAG_WRAPPERS}_GH0.tar.gz \
		rust/crates/lazy_static-1.4.0.crate \
		rust/crates/libc-0.2.147.crate

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Espressif ESP toolchain
WWW=		https://docs.espressif.com/projects/esp-idf/en/v5.3.1/esp32/get-started/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/libintl.h:devel/gettext-runtime \
		bash:shells/bash \
		gawk:lang/gawk \
		ggrep:textproc/gnugrep \
		gpatch:devel/patch \
		gsed:textproc/gsed \
		help2man:misc/help2man \
		makeinfo:print/texinfo

USES=		autoreconf:build bison cargo gmake libtool python
USE_GCC=	yes:build
USE_GITHUB=	nodefault

BROKEN_armv7=	fails to build: configure: error: C compiler cannot create executables
NO_MTREE=	yes
GH_ACCOUNT=	espressif
GH_PROJECT=	binutils-gdb:github1 \
		gcc:github2 \
		newlib-esp32:github3 \
		esp-toolchain-bin-wrappers:github4
GH_TAGNAME=	esp-2.41.0_${ESPDATE}:github1 \
		esp-${GCCVER}_${ESPDATE}:github2 \
		esp-4.3.0_${ESPDATE}:github3 \
		${TAG_WRAPPERS}:github4
BINARY_ALIAS=	g++=${CXX} gcc=${CC} python=${PYTHON_VERSION}
BUILD_ENV=	${WRK_ENV} \
		CT_ALLOW_BUILD_AS_ROOT_SURE=1 \
		CT_FORBID_DOWNLOAD=y \
		GREP=ggrep \
		LD_RUN_PATH=${PREFIX}/lib/${CC} \
		LDFLAGS=-I${PREFIX}/lib \
		${MAKE_ENV:MPATH=*}

CARGO_BUILD=		no
CARGO_CONFIGURE=	no
CARGO_INSTALL=		no
CARGO_TEST=		no
CARGO_TARGET_DIR=	${WRKSRC2}/target
CARGO_VENDOR_DIR=	${WRKSRC2}/cargo-crates
CARGO_CRATES=	lazy_static-1.4.0 \
		libc-0.2.147
CARGO_CARGOTOML=	${WRKSRC2}/Cargo.toml
CARGO_CARGOLOCK=	${WRKSRC2}/Cargo.lock
WRKSRC2=	${WRKDIR}/esp-toolchain-bin-wrappers-${TAG_WRAPPERS}/gnu-xtensa-toolchian

ESPVER=		esp-${DISTVERSION}
ESPDATE=	20240305
GCCVER=		13.2.0
PLIST_SUB=	PKGBASE=$(PKGBASE) \
		GCCVER=$(GCCVER)
TAG_WRAPPERS=	62776e9
TARBALLS=	${BUILD_WRKSRC}/.build/tarballs
XTENSA_CHIPS=	esp32 esp32s2 esp32s3
XTENSA_WRAPPED= addr2line ar as c++ cc c++filt cpp elfedit g++ gcc \
		gcc-${GCCVER} gcc-ar gcc-nm gcc-ranlib gcov gcov-dump \
		gcov-tool gprof ld ld.bfd lto-dump nm objcopy objdump \
		ranlib readelf size strings strip

post-extract:
	${MKDIR} ${TARBALLS}
.for F in $(DISTFILES:N$(EXTRACT_ONLY)\:source[0-9]*)
	${LN} -s ${DISTDIR}/${F:C/:source[0-9]+$//} ${TARBALLS}
.endfor
	${ECHO} CT_LOG_PROGRESS_BAR=n >> \
	    ${BUILD_WRKSRC}/samples/${PORTNAME}/crosstool.config
	# Make tar names match extract directories
	${LN} -s \
	    ${DISTDIR}/espressif-binutils-gdb-esp-2.41.0_${ESPDATE}_GH0.tar.gz \
	    ${TARBALLS}/binutils-gdb-esp-2.41.0_${ESPDATE}.tar.gz
	${LN} -s ${DISTDIR}/espressif-gcc-esp-${GCCVER}_${ESPDATE}_GH0.tar.gz \
	    ${TARBALLS}/gcc-esp-${GCCVER}_${ESPDATE}.tar.gz
	${LN} -s \
	    ${DISTDIR}/espressif-newlib-esp32-esp-4.3.0_${ESPDATE}_GH0.tar.gz \
	    ${TARBALLS}/newlib-esp32-esp-4.3.0_${ESPDATE}.tar.gz
	${CP} -p ${BUILD_WRKSRC}/maintainer/git-version-gen \
	    ${BUILD_WRKSRC}/maintainer/git-version-gen-
	${PRINTF} "#!/bin/sh\necho -n '${ESPVER}'\n" > \
	    ${BUILD_WRKSRC}/maintainer/git-version-gen

	# Use a new crosstool.config that lets us download a
	# branch/tag tarball instead of doing "git clone"
	${MV} ${WRKSRC}/samples/xtensa-esp-elf/crosstool.config \
	    ${WRKSRC}/samples/xtensa-esp-elf/crosstool.config-
	${CP} ${FILESDIR}/crosstool.config ${WRKSRC}/samples/xtensa-esp-elf

do-configure:
	cd ${BUILD_WRKSRC} && ./bootstrap
	cd ${BUILD_WRKSRC} && \
	    ${SETENVI} ${BUILD_ENV} LIBS=-lintl \
	    ./configure --prefix=${WRKDIR}/ct-ng --exec-prefix=${WRKDIR}/ct-ng
	cd ${BUILD_WRKSRC} && \
	    ${SETENVI} -uMAKELEVEL -uMAKEFLAGS -u.MAKE.LEVEL.ENV ${BUILD_ENV} \
	    ${MAKE_CMD} install && \
	    ${SETENVI} ${BUILD_ENV} ./ct-ng xtensa-esp-elf

	# xtensa-toolchian-wrapper
	${MKDIR} ${WRKDIR}/.cargo
	: > ${WRKDIR}/.cargo/config.toml
	${ECHO_CMD} "[source.cargo]" >> ${WRKDIR}/.cargo/config.toml
	${ECHO_CMD} "directory = '${CARGO_VENDOR_DIR}'" >> \
	    ${WRKDIR}/.cargo/config.toml
	${ECHO_CMD} "[source.crates-io]" >> ${WRKDIR}/.cargo/config.toml
	${ECHO_CMD} "replace-with = 'cargo'" >> ${WRKDIR}/.cargo/config.toml
	@cd ${WRKSRC2} && ${CARGO_CARGO_RUN} update \
	    --manifest-path ${CARGO_CARGOTOML} \
	    --verbose \
	    --verbose \
	    ${CARGO_UPDATE_ARGS}

do-build:
	cd ${BUILD_WRKSRC} && ${SETENVI} ${BUILD_ENV} ./ct-ng build
	cd ${BUILD_WRKSRC}/builds/${PORTNAME} && \
	    ${CHMOD} +w . lib && \
	    ${RM} build.log.bz2 lib/charset.alias && \
	    ${CHMOD} -w . lib

	# xtensa-toolchian-wrapper
	cd ${WRKSRC2} && ${CARGO_CARGO_RUN} build \
	    --manifest-path ${CARGO_CARGOTOML} \
	    --verbose \
	    --verbose \
	    ${CARGO_BUILD_ARGS}

do-install:
	cd ${BUILD_WRKSRC}/builds/${PORTNAME} && \
	    ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/${PKGBASE}
	${FIND} ${STAGEDIR}${PREFIX}/${PKGBASE} -type f | \
	    ${XARGS} ${CHMOD} -wx
	${FIND} ${STAGEDIR}${PREFIX}/${PKGBASE}/bin \
	    ${STAGEDIR}${PREFIX}/${PKGBASE}/libexec/gcc/${PORTNAME}/${GCCVER} \
	    ${STAGEDIR}${PREFIX}/${PKGBASE}/${PORTNAME}/bin -type f | \
	    ${XARGS} ${CHMOD} +x

	# xtensa-toolchian-wrapper
	${INSTALL_PROGRAM} ${WRKSRC2}/target/release/xtensa-toolchian-wrapper \
	    ${STAGEDIR}${PREFIX}/${PKGBASE}/bin
.for chip in ${XTENSA_CHIPS}
.for wrap in ${XTENSA_WRAPPED}
	${LN} -f \
	    ${STAGEDIR}${PREFIX}/${PKGBASE}/bin/xtensa-toolchian-wrapper \
	    ${STAGEDIR}${PREFIX}/${PKGBASE}/bin/xtensa-${chip}-elf-${wrap}
.endfor
.endfor
	${RM} ${STAGEDIR}${PREFIX}/${PKGBASE}/bin/xtensa-toolchian-wrapper

.include <bsd.port.mk>
