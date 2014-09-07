# $FreeBSD$

PORTNAME=	gcc-arm-embedded
PORTVERSION=	4.8.20140609
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/gcc-arm-embedded/4.8/4.8-2014-q2-update/+download/
DISTNAME=	${ORIGINAL_PACKAGE_NAME}-src

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Complete gcc-based toolcahin for embedded ARM development

LICENSE=	GPLv2 LGPL20 LGPL21 GPLv3 LGPL3
LICENSE_COMB=	multi

OPTIONS_DEFINE=	PURE EXAMPLES HTML PDF DOCS
OPTIONS_DEFAULT=EXAMPLES
PURE_DESC=	Use all libraries from bundle, do not depend on anything
HTML_DESC=	Install HTML documentation
PDF_DESC=	Install PDF documentation (requires TeX, it is huge)

PURE_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-gcc-isl-0.13-compatibility
PURE_LIB_DEPENDS_OFF=	\
			libexpat.so:${PORTSDIR}/textproc/expat2 \
			libgmp.so:${PORTSDIR}/math/gmp \
			libmpfr.so:${PORTSDIR}/math/mpfr \
			libmpc.so:${PORTSDIR}/math/mpc \
			libisl.so:${PORTSDIR}/devel/isl \
			libcloog-isl.so:${PORTSDIR}/math/cloog \
			libelf.so:${PORTSDIR}/devel/libelf

PDF_USE=		TEX=base:build,tex:build
PDF_BUILD_DEPENDS=	texi2dvi:${PORTSDIR}/print/texinfo
OPTIONS_SUB=		yes

USES=		bison compiler gmake iconv makeinfo tar:bzip2
GNU_CONFIGURE=	yes

PATCH_WRKSRC=		${WRKDIR}/${ORIGINAL_PACKAGE_NAME}

BUILD_WRKSRC=	${WRKDIR}

FULL_VERSION=		4_8-2014q2-20140609
TARGET=			arm-none-eabi
ORIGINAL_PACKAGE_NAME=	gcc-${TARGET}-${FULL_VERSION}

INFO_PATH=	${PORTNAME}-${FULL_VERSION}/share/doc/gcc-${TARGET}/info
INFO=		annotate as bfd binutils configure cpp cppinternals gcc \
		gccinstall gccint gdb gdbint gprof ld stabs standards

MANPREFIX=	${PREFIX}/${PORTNAME}-${FULL_VERSION}/${DOCS_SUFFIX}
DOCSDIR=	${PREFIX}/${PORTNAME}-${FULL_VERSION}/${DOCS_SUFFIX}
EXAMPLESDIR=	${PREFIX}/${PORTNAME}-${FULL_VERSION}/share/gcc-${TARGET}/samples

PLIST_SUB+=	TARGET=${TARGET} FULL_VERSION=${FULL_VERSION}

DOCS_SUFFIX=	share/doc/gcc-${TARGET}
SRC_DIR=	${WRKDIR}/${ORIGINAL_PACKAGE_NAME}/src
BUILD_DIR=	${WRKDIR}/build
INTERIM_WORLD=	${WRKDIR}/install
INTERIM_PREFIX=	${INTERIM_WORLD}/${PORTNAME}-${FULL_VERSION}

BUNDLED_LIBS=			EXPAT:gz ZLIB:bz2 LIBELF:gz \
				GMP:bz2 MPFR:bz2 MPC:gz ISL:bz2 CLOOG:gz
BUNDLED_VERSION_EXPAT=		2.0.1
BUNDLED_VERSION_ZLIB=		1.2.5
BUNDLED_VERSION_LIBELF=		0.8.13
BUNDLED_VERSION_GMP=		4.3.2
BUNDLED_VERSION_MPFR=		2.4.2
BUNDLED_VERSION_MPC=		0.8.1
BUNDLED_VERSION_ISL=		0.11.1
BUNDLED_VERSION_CLOOG=		0.18.0


VAR_TO_SUBMAKE=	BUILD_DIR CC CFLAGS CHOSEN_COMPILER_TYPE CONFIG_SITE \
		CONFIGURE_MAX_CMD_LEN CONFIGURE_SHELL CP CPP CPPFLAGS CXX \
		CXXFLAGS DOCS_SUFFIX ECHO_MSG EXAMPLESDIR FILE FIND GMAKE \
		GREP MAKE_CMD MAKE_SHELL PATCH \
		INSTALL_MACROS INTERIM_PREFIX INTERIM_WORLD LD LDFLAGS LIBDIR \
		LN LOCALBASE MAKE_JOBS_NUMBER MKDIR ORIGINAL_PACKAGE_NAME \
		PORT_OPTIONS PREFIX RM SED SH SRC_DIR STRIP_CMD TAR TARGET \
		WRKDIR

VAR_TO_SUBMAKE_NOEXPAND=	CONFIGURE_ENV MAKE_ENV

.include <bsd.port.pre.mk>

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
	@${ECHO_MSG} "====>  Extracting bundled gcc plugins"
	@${TAR} -xf ${SRC_DIR}/gcc-plugins.tar.bz2 -C ${SRC_DIR}
	@${ECHO_MSG} "====>  Extracting bundled gdb"
	@${TAR} -xf ${SRC_DIR}/gdb.tar.bz2 -C ${SRC_DIR}
	@${ECHO_MSG} "====>  Extracting bundled newlib"
	@${TAR} -xf ${SRC_DIR}/newlib.tar.bz2 -C ${SRC_DIR}
	@${ECHO_MSG} "====>  Extracting bundled newlib-nano"
	@${TAR} -xf ${SRC_DIR}/newlib-nano-2.1.tar.bz2 -C ${SRC_DIR}

do-configure:
	@${RM} -rf ${BUILD_DIR}
	@${MKDIR} ${BUILD_DIR}
	@${RM} -rf ${INTERIM_PREFIX}
	@${MKDIR} ${INTERIM_PREFIX}
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}
	@${RM} -f ${WRKDIR}/Makefile.inc
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
