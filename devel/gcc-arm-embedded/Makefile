# $FreeBSD$

PORTNAME=	gcc-arm-embedded
# This is typo (2030 instead of 2020), buit I don't want to bump EPOCH
PORTVERSION=	9.3.20300529
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2020q2/
DISTNAME=	${ORIGINAL_PACKAGE_NAME}-src

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Complete gcc-based toolcahin for embedded ARM development

LICENSE=	GPLv2 LGPL20 LGPL21 GPLv3 LGPL3
LICENSE_COMB=	multi

BROKEN_aarch64=		fails to build
NOT_FOR_ARCHS=		arm armeb armv6 armv7 \
			mips mips64 mips64el mipsel mipsn32
NOT_FOR_ARCHS_REASON=	Very slow to build on emulator

BUILD_DEPENDS=		objdump:devel/binutils

OPTIONS_DEFINE=	APROFILE PURE PYGDB EXAMPLES HTML PDF DOCS SYMLINK
OPTIONS_DEFAULT=PURE PYGDB SYMLINK
APROFILE_DESC=	Add support for Cortex-A profiles
PURE_DESC=	Use all libraries from bundle, do not depend on anything
HTML_DESC=	Install HTML documentation
PDF_DESC=	Install PDF documentation (requires TeX, it is huge)
PYGDB_DESC=	Build and install python-enabled gdb in addition to standard one
SYMLINK_DESC=	Make version-independent symlink ${LOCALBASE}/${PORTNAME}

PURE_LIB_DEPENDS_OFF=	libexpat.so:textproc/expat2 \
			libgmp.so:math/gmp \
			libmpfr.so:math/mpfr \
			libmpc.so:math/mpc \
			libisl.so:devel/isl

PDF_USE=		TEX=base:build,tex:build,dvipsk:build
PDF_BUILD_DEPENDS=	texi2dvi:print/texinfo
PYGDB_USES=		python

OPTIONS_SUB=		yes

USES=			bison compiler:c++11-lang cpe gmake gettext-runtime \
			makeinfo tar:bzip2 iconv

GNU_CONFIGURE=	yes

PATCH_WRKSRC=	${WRKDIR}/${ORIGINAL_PACKAGE_NAME}
BUILD_WRKSRC=	${WRKDIR}

GCC_VERSION=		9.3.1
FULL_VERSION=		9-2020-q2-update
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

BUNDLED_LIBS=			EXPAT:bz2 ZLIB:gz LIBELF:gz \
				GMP:bz2 MPFR:bz2 MPC:gz ISL:xz
BUNDLED_VERSION_EXPAT=		2.1.1
BUNDLED_VERSION_ZLIB=		1.2.8
BUNDLED_VERSION_LIBELF=		0.8.13
BUNDLED_VERSION_GMP=		6.1.0
BUNDLED_VERSION_MPFR=		3.1.4
BUNDLED_VERSION_MPC=		1.0.3
BUNDLED_VERSION_ISL=		0.18

VAR_TO_SUBMAKE=	BUILD_DIR CC CFLAGS CHOSEN_COMPILER_TYPE CONFIG_SITE \
		CONFIGURE_MAX_CMD_LEN CONFIGURE_SHELL CP CPP CPPFLAGS CXX \
		CXXFLAGS DOCS_SUFFIX ECHO_MSG EXAMPLESDIR FILE FIND GMAKE \
		GCC_VERSION GREP MAKE_CMD MAKE_SHELL PATCH \
		INSTALL_MACROS INTERIM_PREFIX INTERIM_WORLD LD LDFLAGS LIBDIR \
		LN LOCALBASE MAKE_JOBS_NUMBER MKDIR ORIGINAL_PACKAGE_NAME \
		PORT_OPTIONS PREFIX PYTHON_CMD RM SED SH SRC_DIR STRIP_CMD TAR \
		TARGET WRKDIR CONFIGURE_TARGET

VAR_TO_SUBMAKE_NOEXPAND=	CONFIGURE_ENV MAKE_ENV

.include <bsd.port.pre.mk>

#.if ${PORT_OPTIONS:MPURE}
#IGNORE=	PURE option is not valid anymore, no libraries are bundled
#.endif

post-extract:
.if ${PORT_OPTIONS:MPURE}
.for L in ${BUNDLED_LIBS}
	@${ECHO_MSG} "====>  Extracting bundled ${L:C/[:].+//:tl}"
	@${TAR} -xf ${SRC_DIR}/${L:C/[:].+//:tl}-${BUNDLED_VERSION_${L:C/[:].+//}}.tar.${L:C/.+[:]//} -C ${SRC_DIR}
.endfor
.endif
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
.if ${PORT_OPTIONS:MSYMLINK}
	@${LN} -s ${PORTNAME}-${FULL_VERSION} ${STAGEDIR}${PREFIX}/${PORTNAME}
.endif

.include <bsd.port.post.mk>
