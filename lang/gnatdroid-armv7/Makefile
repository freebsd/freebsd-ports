# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	armv7
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VERSION}
PKGNAMEPREFIX=	gnatdroid-
DISTFILES=	${IDENTIFICATION}.tar.bz2

MAINTAINER=	marino@FreeBSD.org
COMMENT=	C/Ada cross-compiler, target: Android ARMv7

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	gnatdroid-sysroot>=19:${PORTSDIR}/lang/gnatdroid-sysroot \
		gnatdroid-binutils>=2.21:${PORTSDIR}/lang/gnatdroid-binutils
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_LICENSES_INSTALL= yes

.include "${.CURDIR}/../gcc-aux/Makefile.common"

USES+=		ada gmake
LANGS=		c c++ ada
APPLY_DIFFS=	core ada cxx ada-testsuite
NO_MTREE=	YES
DISTINFO_FILE=	${.CURDIR}/../gcc-aux/distinfo

OPTIONS_DEFINE=		FORT OBJC
OPTIONS_SUB=		yes
FORT_DESC=		Also build Fortran language
OBJC_DESC=		Also build Objective-C language

DROID_TARGET=		arm-aux-linux-androideabi
DROID_ARCH=		armv7-a
ARMVERSION=		ARMv7
FPU=			neon
WRKSRC=			${WRKDIR}/${IDENTIFICATION}
BUILD_WRKSRC=		${WRKDIR}/build
PATCHDIR=		${.CURDIR}/../gcc-aux/files
CFG_SCRIPT=		${WRKSRC}/configure
REVFILE=		${WRKSRC}/gcc/REVISION
SRPREFIX=		${LOCALBASE}/android
PREFIX=			${SRPREFIX}/${ARMVERSION}
PLIST_SUB+=		TARGET="${DROID_TARGET}"
PLIST_SUB+=		GCCVERS="${GCC_VERSION}"
SUB_FILES=		pkg-message
SUB_LIST=		TARGET="${DROID_TARGET}"
EXTRA_PATCHES=		${FILESDIR}/acats.diff
CROSS=			gnat gnatbind gnatchop gnatclean gnatfind gnatkr \
			gnatlink gnatls gnatmake gnatprep gnatxref

ALL_TARGET=		all

.include <bsd.port.options.mk>

.if ${ARCH:S/amd64/x86_64/} == x86_64
OS_LABEL4VERS=	"[${OPSYS}64 x Android ${ARMVERSION}]"
.else
OS_LABEL4VERS=	"[${OPSYS}32 x Android ${ARMVERSION}]"
.endif

.if ${PORT_OPTIONS:MFORT}
LANGS+=		fortran
APPLY_DIFFS+=	fortran
.endif

.if ${PORT_OPTIONS:MOBJC}
LANGS+=		objc
.endif

INSTALL_ENV=	${MAKE_ENV:C/^PATH=/&${SRPREFIX}\/${ARMVERSION}\/bin:/}

CONFIGURE_ARGS=		--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--target=${DROID_TARGET}
CONFIGURE_ARGS+=	--program-prefix=${DROID_TARGET}-
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-arch=${DROID_ARCH}
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-gmp=${LOCALBASE}
CONFIGURE_ARGS+=	--with-mpfr=${LOCALBASE}
CONFIGURE_ARGS+=	--with-mpc=${LOCALBASE}
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_ARG}
CONFIGURE_ARGS+=	--with-sysroot=${SRPREFIX}
CONFIGURE_ARGS+=	--with-float=soft
CONFIGURE_ARGS+=	--with-fpu=${FPU}
CONFIGURE_ARGS+=	--enable-target-optspace
CONFIGURE_ARGS+=	--enable-threads=posix
CONFIGURE_ARGS+=	--enable-cxx-flags=-frtti
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-libquadmath
CONFIGURE_ARGS+=	--disable-libsanitizer
CONFIGURE_ARGS+=	--disable-libitm
CONFIGURE_ARGS+=	--disable-sjlj-exceptions
CONFIGURE_ARGS+=	--disable-tls
CONFIGURE_ARGS+=	--disable-nls

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

do-configure:
	${MKDIR} ${BUILD_WRKSRC}
	cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${CFG_SCRIPT} ${CONFIGURE_ARGS}

do-install:
#	Buggy makefile; seems to have forgotten this is a cross compiler
#	Manually rename products so it doesn't rebuild them with new name
.for X in ${CROSS}
.  if !exists(${BUILD_WRKSRC}/gcc/${X})
	${CP} -a ${BUILD_WRKSRC}/gcc/${X}-cross ${BUILD_WRKSRC}/gcc/${X}
.  endif
.endfor
	cd ${BUILD_WRKSRC} && ${SETENV} ${INSTALL_ENV} \
		${MAKE_CMD} install-strip DESTDIR=${STAGEDIR}
	${MV} ${STAGEDIR}${PREFIX}/bin/ada \
		${STAGEDIR}${PREFIX}/bin/${DROID_TARGET}-ada

post-install:
.for loop in A B
	cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d -empty | \
		${SORT} -dr | ${XARGS} ${RMDIR}
.endfor
	cd ${STAGEDIR}${PREFIX}; \
	   ${FIND} * \( -type f -or -type l \) | ${SORT} | \
	   ${SED} -e '/^bin\//d' -e '/^${DROID_TARGET}\/bin\//d' \
	   >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${SORT} -dr | \
	   ${SED} -e 's/^/@dirrmtry /g' >> ${TMPPLIST}

acats: build
	cd ${BUILD_WRKSRC}/gcc && ${SETENV} \
	   PATH=${LOCALBASE}/gcc-aux/bin:${PATH}:${PREFIX}/bin \
	   gmake -sk check-acats

.include <bsd.port.mk>
