PORTNAME=	xtensa-esp-elf
DISTVERSION=	13.2.0_20240530
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
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Espressif ESP toolchain
WWW=		https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	bash:shells/bash \
		gawk:lang/gawk \
		gpatch:devel/patch \
		${LOCALBASE}/bin/grep:textproc/gnugrep \
		${LOCALBASE}/include/libintl.h:devel/gettext-runtime \
		gsed:textproc/gsed \
		help2man:misc/help2man \
		makeinfo:print/texinfo

USES=		autoreconf:build bison gmake libtool python
USE_GCC=	yes
USE_GITHUB=	nodefault

NO_MTREE=	yes
GH_ACCOUNT=	espressif
GH_PROJECT=	binutils-gdb:github1 \
		gcc:github2 \
		newlib-esp32:github3
GH_TAGNAME=	esp-2.41.0_${ESPDATE}:github1 \
		esp-${GCCVER}_${ESPDATE}:github2 \
		esp-4.3.0_${ESPDATE}:github3
BINARY_ALIAS=	g++=${CXX} gcc=${CC} python=${PYTHON_VERSION}
BUILD_ENV=	CT_ALLOW_BUILD_AS_ROOT_SURE=1 \
		CT_FORBID_DOWNLOAD=y \
		GREP=${LOCALBASE}/bin/grep \
		LD_RUN_PATH=${PREFIX}/lib/${CC} \
		LDFLAGS=-I${PREFIX}/lib \
		${MAKE_ENV:MPATH=*}

ESPVER=		${DISTNAME:tl:S/-src$//:S/-esp-/-/}
ESPDATE=	20240305
GCCVER=		13.2.0
PLIST_SUB=	PKGBASE=$(PKGBASE) GCCVER=$(GCCVER)
TARBALLS=	${BUILD_WRKSRC}/.build/tarballs

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

	# Use a new crosstool.config that lets us download a
	# branch/tag tarball instead of doing "git clone"
	${MV} ${WRKSRC}/samples/xtensa-esp-elf/crosstool.config \
	    ${WRKSRC}/samples/xtensa-esp-elf/crosstool.config-
	${CP} ${FILESDIR}/crosstool.config ${WRKSRC}/samples/xtensa-esp-elf

do-configure:
	cd ${BUILD_WRKSRC} && ./bootstrap
	${PRINTF} "#!/bin/sh\necho '${ESPVER}'\n" > \
	    ${BUILD_WRKSRC}/version.sh
	${CHMOD} -w+x ${BUILD_WRKSRC}/version.sh
	cd ${BUILD_WRKSRC} && \
	    ${SETENV} ${BUILD_ENV} LIBS=-lintl \
	    ./configure --prefix=${WRKDIR}/ct-ng --exec-prefix=${WRKDIR}/ct-ng
	cd ${BUILD_WRKSRC} && \
	    ${SETENV} -uMAKELEVEL -uMAKEFLAGS -u.MAKE.LEVEL.ENV ${BUILD_ENV} \
	    ${MAKE_CMD} install && ${SETENV} ${BUILD_ENV} ./ct-ng xtensa-esp-elf

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${BUILD_ENV} ./ct-ng build
	cd ${BUILD_WRKSRC}/builds/${PORTNAME} && \
	    ${CHMOD} +w . lib && \
	    ${RM} build.log.bz2 lib/charset.alias && \
	    ${CHMOD} -w . lib

do-install:
	cd ${BUILD_WRKSRC}/builds/${PORTNAME} && \
	    ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/${PKGBASE}
	${FIND} ${STAGEDIR}${PREFIX}/${PKGBASE} -type f | \
	    ${XARGS} ${CHMOD} -wx
	${FIND} ${STAGEDIR}${PREFIX}/${PKGBASE}/bin \
	    ${STAGEDIR}${PREFIX}/${PKGBASE}/libexec/gcc/${PORTNAME}/${GCCVER} \
	    ${STAGEDIR}${PREFIX}/${PKGBASE}/${PORTNAME}/bin -type f | \
	    ${XARGS} ${CHMOD} +x

.include <bsd.port.mk>
