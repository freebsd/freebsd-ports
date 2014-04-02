# $FreeBSD$

PORTNAME=	gcc-arm-embedded
PORTVERSION=	4.8.20140314
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/gcc-arm-embedded/4.8/4.8-2014-q1-update/+download/
DISTNAME=	${ORIGINAL_PACKAGE_NAME}-src

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Complete gcc-based toolcahin for embedded ARM development

LICENSE=	GPLv2 LGPL20 LGPL21 GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libmpc.so:${PORTSDIR}/math/mpc \
		libcloog-isl.so:${PORTSDIR}/math/cloog \
		libelf.so:${PORTSDIR}/devel/libelf

OPTIONS_DEFINE=	EXAMPLES HTML PDF
OPTIONS_DEFAULT=EXAMPLES
HTML_DESC=	Install HTML documentation
PDF_DESC=	Install PDF documentation (requires TeX, it is huge)

PDF_USE=		TEX=base:build,tex:build
PDF_BUILD_DEPENDS=	texi2dvi:${PORTSDIR}/print/texinfo
OPTIONS_SUB=		yes

USE_BZIP2=	yes
USES=		gmake bison iconv compiler
GNU_CONFIGURE=	yes

BUILD_WRKSRC=	${WRKDIR}

FULL_VERSION=		4_8-2014q1-20140314
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
INTERIM_PREFIX=	${WRKDIR}/install/${PORTNAME}-${FULL_VERSION}

VAR_TO_SUBMAKE=	BUILD_DIR CC CFLAGS CHOSEN_COMPILER_TYPE CONFIG_SITE \
		CONFIGURE_MAX_CMD_LEN CP CPP CPPFLAGS CXX CXXFLAGS \
		DOCS_SUFFIX ECHO_MSG EXAMPLESDIR FILE FIND GMAKE GREP \
		INSTALL_MACROS INTERIM_PREFIX LD LDFLAGS LIBDIR LN LOCALBASE \
		MAKE_JOBS_NUMBER MKDIR ORIGINAL_PACKAGE_NAME PORT_OPTIONS \
		PREFIX RM SED SH SRC_DIR STRIP_CMD TAR TARGET WRKDIR

VAR_TO_SUBMAKE_NOEXPAND=	CONFIGURE_ENV MAKE_ENV

.include <bsd.port.pre.mk>

post-extract:
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
.for VAR in ${VAR_TO_SUBMAKE_NOEXPAND}
	@${ECHO} -n '${VAR}='                          >> ${WRKDIR}/Makefile.inc
	@${MAKE} .MAKE.EXPAND_VARIABLES=0 -X -V ${VAR} >> ${WRKDIR}/Makefile.inc
.endfor

do-build:
	@${MAKE} -C ${WRKDIR}

do-install:
	@${TAR} -cf - -C ${WRKDIR}/install ${PORTNAME}-${FULL_VERSION} | ${TAR} -xf - -C ${STAGEDIR}${PREFIX}

.include <bsd.port.post.mk>
