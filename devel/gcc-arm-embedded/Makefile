# $FreeBSD$

PORTNAME=	gcc-arm-embedded
PORTVERSION=	6.3.20170628
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://developer.arm.com/-/media/Files/downloads/gnu-rm/6-2017q2/
DISTNAME=	${ORIGINAL_PACKAGE_NAME}-src

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Complete gcc-based toolcahin for embedded ARM development

LICENSE=	GPLv2 LGPL20 LGPL21 GPLv3 LGPL3
LICENSE_COMB=	multi

BROKEN_powerpc64=	does not build: __adjust.c: internal compiler error: Segmentation fault

OPTIONS_DEFINE=	PYGDB EXAMPLES HTML PDF DOCS
OPTIONS_DEFAULT=PYGDB
HTML_DESC=	Install HTML documentation
PDF_DESC=	Install PDF documentation (requires TeX, it is huge)
PYGDB_DESC=	Build and install python-enabled gdb in addition to standard one

PDF_USE=		TEX=base:build,tex:build,dvipsk:build
PDF_BUILD_DEPENDS=	texi2dvi:print/texinfo
PYGDB_USES=		python:2

OPTIONS_SUB=		yes

NOT_FOR_ARCHS=		aarch64 arm armeb armv6 \
			mips mips64 mips64el mipsel mipsn32
NOT_FOR_ARCHS_REASON=	Very slow to build on emulator

LIB_DEPENDS=		libexpat.so:textproc/expat2 \
			libgmp.so:math/gmp \
			libmpfr.so:math/mpfr \
			libmpc.so:math/mpc \
			libisl.so:devel/isl

USES=			bison compiler cpe gmake gettext-runtime iconv makeinfo tar:bzip2

GNU_CONFIGURE=	yes

PATCH_WRKSRC=	${WRKDIR}/${ORIGINAL_PACKAGE_NAME}
BUILD_WRKSRC=	${WRKDIR}

GCC_VERSION=		6.3.1
FULL_VERSION=		6-2017-q2-update
TARGET=			arm-none-eabi
ORIGINAL_PACKAGE_NAME=	gcc-${TARGET}-${FULL_VERSION}

CPE_PRODUCT=	gcc
CPE_VENDOR=	gnu
CPE_VERSION=	${GCC_VERSION}

INFO_PATH=	${PORTNAME}-${FULL_VERSION}/share/doc/gcc-${TARGET}/info
INFO=		annotate as bfd binutils cpp cppinternals gcc \
		gccinstall gccint gdb gprof ld stabs

MANPREFIX=	${PREFIX}/${PORTNAME}-${FULL_VERSION}/${DOCS_SUFFIX}
DOCSDIR=	${PREFIX}/${PORTNAME}-${FULL_VERSION}/${DOCS_SUFFIX}
EXAMPLESDIR=	${PREFIX}/${PORTNAME}-${FULL_VERSION}/share/gcc-${TARGET}/samples

PLIST_SUB+=	TARGET=${TARGET} FULL_VERSION=${FULL_VERSION} \
		GCC_VERSION=${GCC_VERSION}

DOCS_SUFFIX=	share/doc/gcc-${TARGET}
SRC_DIR=	${WRKDIR}/${ORIGINAL_PACKAGE_NAME}/src
BUILD_DIR=	${WRKDIR}/build
INTERIM_WORLD=	${WRKDIR}/install
INTERIM_PREFIX=	${INTERIM_WORLD}/${PORTNAME}-${FULL_VERSION}

VAR_TO_SUBMAKE=	BUILD_DIR CC CFLAGS CHOSEN_COMPILER_TYPE CONFIG_SITE \
		CONFIGURE_MAX_CMD_LEN CONFIGURE_SHELL CP CPP CPPFLAGS CXX \
		CXXFLAGS DOCS_SUFFIX ECHO_MSG EXAMPLESDIR FILE FIND GMAKE \
		GCC_VERSION GREP MAKE_CMD MAKE_SHELL PATCH \
		INSTALL_MACROS INTERIM_PREFIX INTERIM_WORLD LD LDFLAGS LIBDIR \
		LN LOCALBASE MAKE_JOBS_NUMBER MKDIR ORIGINAL_PACKAGE_NAME \
		PORT_OPTIONS PREFIX PYTHON_CMD RM SED SH SRC_DIR STRIP_CMD TAR \
		TARGET WRKDIR

VAR_TO_SUBMAKE_NOEXPAND=	CONFIGURE_ENV MAKE_ENV

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPURE}
IGNORE=	PURE option is not valid anymore, no libraries are bundled
.endif

post-extract:
	@${ECHO_MSG} "====>  Extracting bundled binutils"
	@${TAR} -xf ${SRC_DIR}/binutils.tar.bz2 -C ${SRC_DIR}
	@${ECHO_MSG} "====>  Extracting bundled gcc"
	@${TAR} -xf ${SRC_DIR}/gcc.tar.bz2 -C ${SRC_DIR}
	@${ECHO_MSG} "====>  Extracting bundled gdb"
	@${TAR} -xf ${SRC_DIR}/gdb.tar.bz2 -C ${SRC_DIR}
	@${ECHO_MSG} "====>  Extracting bundled newlib"
	@${TAR} -xf ${SRC_DIR}/newlib.tar.bz2 -C ${SRC_DIR}

do-configure:
	@${RM} -r ${BUILD_DIR}
	@${MKDIR} ${BUILD_DIR}
	@${RM} -r ${INTERIM_PREFIX}
	@${MKDIR} ${INTERIM_PREFIX}
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}
	@${RM} ${WRKDIR}/Makefile.inc
.for VAR in ${VAR_TO_SUBMAKE}
	@${ECHO} '${VAR}=${${VAR}}' >> ${WRKDIR}/Makefile.inc
.endfor
.for L in ${BUNDLED_LIBS}
	@${ECHO} -n 'BUNDLED_VERSION_${L:C/[:].+//}='   >> ${WRKDIR}/Makefile.inc
	@${ECHO}    '${BUNDLED_VERSION_${L:C/[:].+//}}' >> ${WRKDIR}/Makefile.inc
.endfor
.for VAR in ${VAR_TO_SUBMAKE_NOEXPAND}
	@${ECHO} -n '${VAR}='                          >> ${WRKDIR}/Makefile.inc
	@${MAKE} .MAKE.EXPAND_VARIABLES=0 -X -V ${VAR} >> ${WRKDIR}/Makefile.inc
.endfor

do-build:
	@${MAKE} -C ${WRKDIR}

do-install:
	@${TAR} -cf - -C ${WRKDIR}/install ${PORTNAME}-${FULL_VERSION} | ${TAR} -xf - -C ${STAGEDIR}${PREFIX}

.include <bsd.port.post.mk>
