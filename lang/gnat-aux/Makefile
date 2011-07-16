# New ports collection makefile for:  gnat-aux
# Date created:                       16 December 2010
# Whom:                               John Marino <draco@marino.st>
#
# $FreeBSD$
#

PORTNAME=	gnat-aux
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/

MAINTAINER=	draco@marino.st
COMMENT=	GNAT Ada compiler based on GCC ${GCC_BRANCH}

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp
LIB_DEPENDS+=	mpfr.4:${PORTSDIR}/math/mpfr
LIB_DEPENDS+=	mpc.2:${PORTSDIR}/math/mpc

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BZIP2=		yes
USE_ICONV=		yes
USE_BISON=		build
USE_PERL5_BUILD=	yes
USE_LDCONFIG=		yes
ALL_TARGET=		default

SNAPSHOT=		20110627
GCC_BRANCH=		4.6
GCC_POINT=		1
LANGS=			c

THREAD_MODEL=		posix
INTENDED_COMPILER=	NATIVE
BOOTSTRAP_COMPILER=	NOT_REQUIRED
BOOTSTRAP_TRIPLET=	NOT_SET
FULL_GNATGCC=		NOT_SET

OPTIONS=	ADA    "Build Ada language" on
OPTIONS+=	CXX    "Build C++ language" on
OPTIONS+=	TS_ADA "Enable Ada testsuite" off
OPTIONS+=	TS_CXX "Enable C++ testsuite" off
OPTIONS+=	TS_GCC "Enable GCC testsuite" off

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
BLD_TARGET=		x86_64-aux-freebsd${OSREL}
OS_LABEL4VERS=		[FreeBSD64]
BOOTSTRAP_TRIPLET=	x86_64-bootstrap-freebsd8.1/4.6.0
BOOTSTRAP_COMPILER=	gnat-bootstrap.x86_64.freebsd.tar.bz2
.else
BLD_TARGET=		i386-aux-freebsd${OSREL}
OS_LABEL4VERS=		[FreeBSD]
BOOTSTRAP_TRIPLET=	i386-bootstrap-freebsd8.0/4.6.0
BOOTSTRAP_COMPILER=	gnat-bootstrap.i386.freebsd.tar.bz2
.endif
PLIST_SUB=		GNU_HOST=${BLD_TARGET}
PLIST_SUB+=		GCC_VER=${GCC_BRANCH}.${GCC_POINT}

WRKSRC=			${WRKDIR}/build
GCC_WRKSRC=		${WRKDIR}/gcc-${GCC_BRANCH}-${SNAPSHOT}
BOOTSTRAP_PREFIX=	${WRKDIR}/bootstrap
PKG_PREFIX=		${PREFIX}
CONFIGURE_SCRIPT=	${GCC_WRKSRC}/configure
REVFILE=		${GCC_WRKSRC}/gcc/REVISION
LPATH=			lib/gcc/${BLD_TARGET}/${GCC_BRANCH}.${GCC_POINT}
LEPATH=			libexec/gcc/${BLD_TARGET}/${GCC_BRANCH}.${GCC_POINT}
MAN1=			gnatcpp.1 gnatgcc.1 gnatgcov.1
MAN7=			fsf-funding.7 gfdl.7 gpl.7
MAN1PREFIX=		${PREFIX}/share
MAN7PREFIX=		${PREFIX}/share
NO_MANCOMPRESS=		yes

# If we find gnatgcc and friends in standard location, then we'll use this
# compiler instead of downloading the bootstrap.
.if exists (${PREFIX}/bin/gnatgcc)
.if exists (${PREFIX}/bin/gnatbind)
.if exists (${PREFIX}/bin/gnatlink)
.if exists (${PREFIX}/bin/gnatmake)
FULL_GNATGCC=${PREFIX}/bin/gnatgcc
FULL_PATH=/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/bin
.endif
.endif
.endif
.endif

# If FULL_GNATGCC is not set, we'll request the bootstrap compiler
.if ${FULL_GNATGCC} == "NOT_SET"
INTENDED_COMPILER=BOOTSTRAP
FULL_GNATGCC=${BOOTSTRAP_PREFIX}/bin/gnatgcc
FULL_PATH=${BOOTSTRAP_PREFIX}/bin:/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/bin
DISTFILES=${PORTNAME}-${SNAPSHOT}.tar.bz2 ${BOOTSTRAP_COMPILER}
.endif

###########
##  Ada  ##
###########

.if defined(WITH_ADA)
LANGS+=		ada
.endif

###########
##  C++  ##
###########

.if defined(WITH_CXX)
LANGS+=		c++
MAN1+=		gnatg++.1
LCXXPATH=	include/c++/${GCC_BRANCH}.${GCC_POINT}
LSHRPATH=	share/gcc-${GCC_BRANCH}.${GCC_POINT}
PLIST_SUB+=	CXX=""
.else
PLIST_SUB+=	CXX="@comment "
.endif

##################
##  Testsuites  ##
##################

.if defined(WITH_TS_ADA) \
 || defined(WITH_TS_CXX) \
 || defined(WITH_TS_GCC)
BUILD_DEPENDS=	dejagnu>=1.4:${PORTSDIR}/misc/dejagnu
.endif

# for port maintenance, uncomment to invoke "make makesum"
# DISTFILES=${PORTNAME}-${SNAPSHOT}.tar.bz2 \
#   gnat-aux-460.i386.freebsd.tar.bz2 \
#   gnat-aux-460.x86_64.freebsd.tar.bz2

# Establish Ada-aware compiler for use
ADA_CONFIGURE_ENV=	CC=${FULL_GNATGCC}
ADA_CONFIGURE_ENV+=	PATH=${FULL_PATH}
ADA_CONFIGURE_ENV+=	CONFIG_SHELL=${SH}
ADA_MAKE_ENV=		PATH=${FULL_PATH}
ADA_MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/gcc

# The standard configuration options
CONFIGURE_ARGS=		--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--build=${BLD_TARGET}
CONFIGURE_ARGS+=	--program-prefix=gnat
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-gmp=${PKG_PREFIX}
CONFIGURE_ARGS+=	--with-mpfr=${PKG_PREFIX}
CONFIGURE_ARGS+=	--with-mpc=${PKG_PREFIX}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${PKG_PREFIX}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-threads=${THREAD_MODEL}
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--disable-libquadmath
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-nls

post-extract:
	# Personalize GNAT for each different machine
	@${ECHO} "-=> GNAT AUX ${OS_LABEL4VERS}" > ${REVFILE}

.if ${INTENDED_COMPILER} == "BOOTSTRAP"
	${MKDIR} ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../bin ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../lib ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../libexec ${BOOTSTRAP_PREFIX}

	# Bootstrap compiler has statically linked z, gmp, mpc, mpfr and iconv
	# The only shared lib is libc.so.7, so it should work for a long time.
	# if FBSD 9.0 upgrades libc, a compat8x requirement could be added
	# for FreeBSD 7.x and 8.x
.endif

do-configure:
	#reset timestamps
	cd ${GCC_WRKSRC}; contrib/gcc_update --touch
	${RM} -f ${GCC_WRKSRC}/gcc/*/*.info*
	${TOUCH} ${GCC_WRKSRC}/gcc/cstamp-h.in

	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${SETENV} ${ADA_CONFIGURE_ENV} \
	${SH} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} all

test: build
.if defined(WITH_TS_ADA)
	cd ${WRKSRC} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-ada
.endif
.if defined(WITH_TS_CXX)
	cd ${WRKSRC} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-c++
	cd ${WRKSRC} && ${SETENV} ${ADA_MAKE_ENV} \
	   ${GMAKE} -sk check-target-libstdc++-v3
.endif
.if defined(WITH_TS_GCC)
	cd ${WRKSRC} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} -sk check-c
.endif

do-install:
	cd ${WRKSRC} && ${SETENV} ${ADA_MAKE_ENV} ${GMAKE} install-strip DESTDIR=${DESTDIR}

post-install:
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${LPATH} ${LEPATH} ${LCXXPATH} ${LSHRPATH}
	cd ${PREFIX} ; ${FIND} $d \( -type f -or -type l \) | ${SORT} >> ${WRKDIR}/PLIST.lib
	cd ${PREFIX} ; ${FIND} $d  -type d | ${SORT} -r | \
	   ${SED} -e 's/^/@dirrm /g' >> ${WRKDIR}/PLIST.lib
.endfor
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc/${BLD_TARGET}     2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc                   2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc/${BLD_TARGET} 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc               2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/include/c++               2>/dev/null || true" >> ${WRKDIR}/PLIST.lib

	cd ${WRKDIR}; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
