# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	9.3.1.s20200501
CATEGORIES=	lang
MASTER_SITES=	GCC/snapshots/${DIST_VERSION}
PKGNAMESUFFIX=	${SUFFIX}-devel
DISTNAME=	gcc-${DIST_VERSION}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	GNU Compiler Collection 9

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	aarch64 amd64 arm armv6 armv7 i386 powerpc powerpc64 sparc64

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	runtest:misc/dejagnu
.endif

USES=		compiler cpe gmake iconv libtool makeinfo perl5 tar:xz
USE_BINUTILS=	yes
USE_PERL5=	build

CONFLICTS=	gcc9-9.*

CPE_VENDOR=	gnu
CPE_VERSION=	${GCC_VERSION}

# DIST_VERSION relates to downloads, GCC_VERSION and SUFFIX to names
# of executables and directories once installed.  A PORTVERSION of
# Y.2.1.s20140817 results in values of Y-20140817, Y.2.1, and Y
# for these three.
DIST_VERSION=	${PORTVERSION:C/([0-9]+).*\.s([0-9]+)/\1-\2/}
GCC_VERSION=	${PORTVERSION:C/(.+)\.s[0-9]{8}/\1/}
SUFFIX=		${PORTVERSION:C/([0-9]+).*/\1/}
SSP_UNSAFE=	yes
CFLAGS:=	${CFLAGS:N-mretpoline}
CXXFLAGS:=	${CXXFLAGS:N-mretpoline}

OPTIONS_DEFINE=		BOOTSTRAP GRAPHITE PLUGINS
OPTIONS_DEFAULT=	BOOTSTRAP PLUGINS
BOOTSTRAP_DESC=		Build using a full bootstrap
GRAPHITE_DESC=		Support for Graphite loop optimizations

.if exists(/usr/lib32/libc.so)
OPTIONS_DEFINE_amd64+=		MULTILIB
OPTIONS_DEFAULT_amd64+=	MULTILIB
OPTIONS_DEFINE_powerpc64+=	MULTILIB
OPTIONS_DEFAULT_powerpc64+=	MULTILIB
MULTILIB_DESC=		Build support for 32-bit and 64-bit targets
MULTILIB_CONFIGURE_ENABLE=	multilib
.else
CONFIGURE_ARGS+=	--disable-multilib
.endif

PLUGINS_CONFIGURE_ENABLE=	plugin

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}

.elif ${ARCH} == powerpc64
CONFIGURE_ENV+=	UNAME_m="powerpc64"
. if defined(PPC_ABI) && ${PPC_ABI} == ELFv2
CONFIGURE_ARGS+=	--with-abi=elfv2
. else
MAKE_ARGS+=	CFLAGS_FOR_TARGET="-O0" CXXFLAGS_FOR_TARGET="-O0" BOOT_CFLAGS="-O0"
. endif
.endif

LANGUAGES:=	c,c++,objc,fortran
TARGLIB=	${PREFIX}/lib/gcc${SUFFIX}
TARGLIB32=	${PREFIX}/lib32	# The version information is added later
LIBEXEC=	${PREFIX}/libexec/gcc${SUFFIX}
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
.if empty(PORT_OPTIONS:MBOOTSTRAP)
CONFIGURE_ARGS+=--disable-bootstrap
.else
CONFIGURE_ARGS+=--with-build-config=bootstrap-debug
ALL_TARGET=	bootstrap-lean
.endif
INSTALL_TARGET=	install-strip
.if ${UID} != 0
BINMODE=	755
.endif
CONFIGURE_ARGS+=--disable-nls \
		--enable-gnu-indirect-function \
		--libdir=${TARGLIB} \
		--libexecdir=${LIBEXEC} \
		--program-suffix=${SUFFIX} \
		--with-as=${LOCALBASE}/bin/as \
		--with-gmp=${LOCALBASE} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/ \
		--with-ld=${LOCALBASE}/bin/ld \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection" \
		--with-system-zlib
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=	${TARGLIB}
PLIST_SUB+=	GCC_VERSION=${GCC_VERSION} \
		GNU_HOST=${CONFIGURE_TARGET} \
		SUFFIX=${SUFFIX}
INFO=		gcc${SUFFIX}/cpp \
		gcc${SUFFIX}/cppinternals \
		gcc${SUFFIX}/gcc \
		gcc${SUFFIX}/gccinstall \
		gcc${SUFFIX}/gccint \
		gcc${SUFFIX}/gfortran \
		gcc${SUFFIX}/libgomp
.if ${ARCH} == amd64 || ${ARCH} == i386
INFO+=		gcc${SUFFIX}/libquadmath \
		gcc${SUFFIX}/libitm
.endif
SUB_FILES=	pkg-message
SUB_LIST+=	TARGLIB=${TARGLIB}

.if ${PORT_OPTIONS:MGRAPHITE}
LIB_DEPENDS+=	libisl.so:devel/isl
CONFIGURE_ARGS+=--with-isl=${LOCALBASE}
.endif

CONFIGURE_ARGS+=--enable-languages=${LANGUAGES}

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for ${CONFIGURE_TARGET} [${LANGUAGES}]"

pre-configure:
	cd ${WRKSRC} ; contrib/gcc_update --touch
	@${RM} ${WRKSRC}/gcc/*/*.info*

.if defined(MAINTAINER_MODE)
full-regression-test: build
	cd ${TEST_WRKSRC}; ${MAKE_CMD} -sk check \
	; ${WRKSRC}/contrib/test_summary
.endif

post-stage:
	${RM} ${STAGEDIR}${PREFIX}/man/man7/*
	${RM} -r ${STAGEDIR}${TARGLIB}/gcc/*/${GCC_VERSION}/include-fixed/
	# Add target libraries and include files to packaging list.
	${RM} ${WRKDIR}/PLIST.lib

.if (${ARCH} == amd64 || ${ARCH} == powerpc64) && ${PORT_OPTIONS:MMULTILIB}
	${MKDIR} ${STAGEDIR}${TARGLIB32}
	${MV} ${STAGEDIR}${PREFIX}/lib/lib32 ${STAGEDIR}${TARGLIB32}/gcc${SUFFIX}
.endif

.for d in ${TARGLIB:S/^${PREFIX}\///} ${TARGLIB32:S/^${PREFIX}\///} ${LIBEXEC:S/^${PREFIX}\///}
	cd ${STAGEDIR}${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
