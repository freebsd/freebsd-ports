# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	armv7
PORTVERSION=	${SNAPSHOT}
PORTREVISION?=	${ARMV7_PR}
CATEGORIES=	lang
MASTER_SITES=	GCC/releases/gcc-${GCC_VERSION}
PKGNAMEPREFIX=	gnatdroid-
DISTFILES=	${IDENTIFICATION}.tar.bz2

MAINTAINER?=	marino@FreeBSD.org
COMMENT?=	C/Ada cross-compiler, target: Android ARMv7

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	${SYSROOT}>=19:lang/${SYSROOT} \
		${GDBINUTILS}>=2.21:lang/${GDBINUTILS}
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_LICENSES_INSTALL= yes
AUXPORT=	gcc6-aux

.include "${.CURDIR}/../${AUXPORT}/Makefile.common"

USES+=		ada:6 gmake
LANGS=		c c++ ada
APPLY_DIFFS=	core ada cxx ada-testsuite
NO_MTREE=	YES
DISTINFO_FILE=	${.CURDIR}/../${AUXPORT}/distinfo

OPTIONS_DEFINE=		FORT OBJC
OPTIONS_SUB=		yes
FORT_DESC=		Also build Fortran language
OBJC_DESC=		Also build Objective-C language

DROID_TARGET?=		arm-aux-linux-androideabi
CPUVERSION?=		ARMv7
ARG_ARCH?=		--with-arch=armv7-a
ARG_FPU?=		--with-fpu=neon
ARG_FLOATSOFT?=		--with-float=soft
ALL_TARGET=		all
GARCH=			${ARCH:S/amd64/x86_64/}
BITS=			${GARCH:S/x86_64/64/:S/i386/32/}
OS_LABEL4VERS=		[${OPSYS}${BITS} x Android ${CPUVERSION}]
WRKSRC=			${WRKDIR}/${IDENTIFICATION}
BUILD_WRKSRC=		${WRKDIR}/build
PATCHDIR=		${.CURDIR}/../${AUXPORT}/files
CFG_SCRIPT=		${WRKSRC}/configure
REVFILE=		${WRKSRC}/gcc/REVISION
SRPREFIX?=		${LOCALBASE}/android
PREFIX=			${SRPREFIX}/${CPUVERSION}
SYSROOT?=		gnatdroid-sysroot
GDBINUTILS?=		gnatdroid-binutils
PLIST_SUB+=		TARGET="${DROID_TARGET}"
PLIST_SUB+=		GCCVERS="${GCC_VERSION}"
SUB_FILES=		pkg-message
SUB_LIST=		TARGET="${DROID_TARGET}"
EXTRA_PATCHES=		${FILESDIR}/acats.diff
CROSS=			gnat gnatbind gnatchop gnatclean gnatfind gnatkr \
			gnatlink gnatls gnatmake gnatprep gnatxref

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFORT}
LANGS+=		fortran
APPLY_DIFFS+=	fortran
.endif

.if ${PORT_OPTIONS:MOBJC}
LANGS+=		objc
.endif

INSTALL_ENV=	${MAKE_ENV:C/^PATH=/&${SRPREFIX}\/${CPUVERSION}\/bin:/}

ADA_CONFIG_ARGS=	--enable-languages=${LANGS:Q}
ADA_CONFIG_ARGS+=	--target=${DROID_TARGET}
ADA_CONFIG_ARGS+=	--program-prefix=${DROID_TARGET}-
ADA_CONFIG_ARGS+=	--prefix=${PREFIX}
ADA_CONFIG_ARGS+=	${ARG_ARCH}
ADA_CONFIG_ARGS+=	--with-system-zlib
ADA_CONFIG_ARGS+=	--with-gmp=${LOCALBASE}
ADA_CONFIG_ARGS+=	--with-mpfr=${LOCALBASE}
ADA_CONFIG_ARGS+=	--with-mpc=${LOCALBASE}
ADA_CONFIG_ARGS+=	${ICONV_CONFIGURE_ARG}
ADA_CONFIG_ARGS+=	--with-sysroot=${SRPREFIX}
ADA_CONFIG_ARGS+=	${ARG_FLOATSOFT}
ADA_CONFIG_ARGS+=	${ARG_FPU}
ADA_CONFIG_ARGS+=	--enable-target-optspace
ADA_CONFIG_ARGS+=	--enable-threads=posix
ADA_CONFIG_ARGS+=	--enable-cxx-flags=-frtti
ADA_CONFIG_ARGS+=	--enable-checking=release
ADA_CONFIG_ARGS+=	--disable-bootstrap
ADA_CONFIG_ARGS+=	--disable-shared
ADA_CONFIG_ARGS+=	--disable-libssp
ADA_CONFIG_ARGS+=	--disable-libgomp
ADA_CONFIG_ARGS+=	--disable-libmudflap
ADA_CONFIG_ARGS+=	--disable-libquadmath
ADA_CONFIG_ARGS+=	--disable-libsanitizer
ADA_CONFIG_ARGS+=	--disable-libitm
ADA_CONFIG_ARGS+=	--disable-sjlj-exceptions
ADA_CONFIG_ARGS+=	--disable-tls
ADA_CONFIG_ARGS+=	--disable-nls

post-extract:
	# Personalize GNAT for each different machine
	@${ECHO} "-=> GNAT AUX ${OS_LABEL4VERS}" > ${REVFILE}
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/locale/dragonfly
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/os/bsd/dragonfly
	# Apply required composite diff files
.for suffix in ${APPLY_DIFFS}
	@${ECHO} "Applying composite patch diff-${suffix}"
	@${PATCH} -d ${WRKSRC} -s -E < ${PATCHDIR}/diff-${suffix}
.endfor
	@(cd ${WRKSRC}/gcc/testsuite/ada/acats && \
		${CP} run_remote.sh run_all.sh)
	${REINPLACE_CMD} -e 's|@REMOTE_TARGET@|${DROID_TARGET}|' \
		${WRKSRC}/gcc/testsuite/ada/acats/run_all.sh
	${REINPLACE_CMD} -e 's|<syscall.h>|<sys/syscall.h>|' \
		${WRKSRC}/libstdc++-v3/libsupc++/guard.cc

do-configure:
	${MKDIR} ${BUILD_WRKSRC}
	(cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${CFG_SCRIPT} ${ADA_CONFIG_ARGS})

do-install:
#	Buggy makefile; seems to have forgotten this is a cross compiler
#	Manually rename products so it doesn't rebuild them with new name
.for X in ${CROSS}
.  if !exists(${BUILD_WRKSRC}/gcc/${X})
	${CP} -a ${BUILD_WRKSRC}/gcc/${X}-cross ${BUILD_WRKSRC}/gcc/${X}
.  endif
.endfor
	(cd ${BUILD_WRKSRC} && ${SETENV} ${INSTALL_ENV} \
		${MAKE_CMD} install-strip DESTDIR=${STAGEDIR})
	${MV} ${STAGEDIR}${PREFIX}/bin/ada \
		${STAGEDIR}${PREFIX}/bin/${DROID_TARGET}-ada

post-stage:
.for loop in A B
	(cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d -empty | \
		${SORT} -dr | ${XARGS} ${RMDIR})
.endfor
	(cd ${STAGEDIR}${PREFIX}; \
		${FIND} * \( -type f -or -type l \) | ${SORT} | \
		${SED} -e '/^bin\//d' -e '/^${DROID_TARGET}\/bin\//d' \
		>> ${TMPPLIST})

acats: build
	(cd ${BUILD_WRKSRC}/gcc && ${SETENV} \
		PATH=${LOCALBASE}/${AUXPORT}/bin:${PATH}:${PREFIX}/bin \
		${GMAKE} -sk check-acats)

gnatdg: build
	(cd ${BUILD_WRKSRC}/gcc && ${SETENV} \
		PATH=${LOCALBASE}/${AUXPORT}/bin:${PATH}:${PREFIX}/bin \
		${GMAKE} -sk check-gnat RUNTESTFLAGS=--target_board=gnatdroid6)

.include <bsd.port.mk>
