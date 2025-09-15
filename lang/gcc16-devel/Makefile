PORTNAME=	gcc
PORTVERSION=	16.0.0.s20250914
CATEGORIES=	lang
MASTER_SITES=	GCC/snapshots/${DIST_VERSION}
PKGNAMESUFFIX=	${SUFFIX}-devel
DISTNAME=	gcc-${DIST_VERSION}

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	GNU Compiler Collection 16
WWW=		https://gcc.gnu.org

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	runtest:misc/dejagnu
.endif

USES=		compiler:c++11-lang cpe gmake iconv libtool makeinfo perl5 tar:xz
USE_BINUTILS=	yes
USE_PERL5=	build

CPE_VENDOR=	gnu
CPE_VERSION=	${GCC_VERSION}

# DIST_VERSION relates to downloads, GCC_VERSION and SUFFIX to names
# of executables and directories once installed.  A PORTVERSION of
# Y.2.1.s20140817 results in values of Y-20140817, Y.2.1, and Y
# for these three.
DIST_VERSION=	${PORTVERSION:C/([0-9]+).*\.s([0-9]+)/\1-\2/}
GCC_VERSION=	${PORTVERSION:C/(.+)\.s[0-9]{8}/\1/}
SUFFIX=		${PORTVERSION:C/([0-9]+).*/\1/}
CFLAGS:=	${CFLAGS:N-mretpoline} -D__USE_ISOC11
CXXFLAGS:=	${CXXFLAGS:N-mretpoline}

OPTIONS_DEFINE=		GRAPHITE
OPTIONS_DEFAULT_aarch64=STANDARD_BOOTSTRAP
OPTIONS_DEFAULT_armv6=	STANDARD_BOOTSTRAP
OPTIONS_DEFAULT_armv7=	STANDARD_BOOTSTRAP
OPTIONS_DEFAULT_amd64=	STANDARD_BOOTSTRAP
OPTIONS_DEFAULT_i386=	STANDARD_BOOTSTRAP
OPTIONS_DEFAULT_powerpc=LTO_BOOTSTRAP
OPTIONS_DEFAULT_powerpc64=LTO_BOOTSTRAP
OPTIONS_DEFAULT_powerpc64le=LTO_BOOTSTRAP
OPTIONS_RADIO=	BOOTSTRAP
OPTIONS_RADIO_BOOTSTRAP=	LTO_BOOTSTRAP STANDARD_BOOTSTRAP
LTO_BOOTSTRAP_DESC=	Build using a full LTO bootstrap
STANDARD_BOOTSTRAP_DESC=	Build using a full bootstrap without LTO
GRAPHITE_DESC=		Support for Graphite loop optimizations

.if exists(/usr/lib32/libc.so)
OPTIONS_DEFINE_amd64+=		MULTILIB
OPTIONS_DEFAULT_amd64+=	MULTILIB
OPTIONS_DEFINE_powerpc64+=	MULTILIB
#OPTIONS_DEFAULT_powerpc64+=	MULTILIB # https://gcc.gnu.org/bugzilla/show_bug.cgi?id=105010
MULTILIB_DESC=		Build support for 32-bit and 64-bit targets
MULTILIB_CONFIGURE_ENABLE=	multilib
.else
CONFIGURE_ARGS+=	--disable-multilib
.endif

.if defined(CPUTYPE) && ${CPUTYPE:Mg[3-5]}
CFLAGS:=	${CFLAGS:S/mcpu=g/mcpu=G/}
CXXFLAGS:=	${CFLAGS:S/mcpu=g/mcpu=G/}
.endif

GRAPHITE_LIB_DEPENDS=          libisl.so:devel/isl
GRAPHITE_CONFIGURE_WITH+=      isl

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}

.elif ${ARCH} == powerpc64
CONFIGURE_ARGS+=	--with-abi=elfv2
.endif

LANGUAGES=	c,c++,objc,fortran
.if ${ARCH} != i386 && !empty(PORT_OPTIONS:M*BOOTSTRAP)
LANGUAGES:=	${LANGUAGES},jit
.endif

TARGLIB=	${PREFIX}/lib/gcc${SUFFIX}
TARGLIB32=	${PREFIX}/lib32	# The version information is added later
LIBEXEC=	${PREFIX}/libexec/gcc${SUFFIX}
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_OUTSOURCE=	yes
.if empty(PORT_OPTIONS:M*BOOTSTRAP)
CONFIGURE_ARGS+=--disable-bootstrap
.elif ${PORT_OPTIONS:MLTO_BOOTSTRAP}
CONFIGURE_ARGS+=--with-build-config=bootstrap-lto-noplugin
ALL_TARGET=	bootstrap-lean
PIE_UNSAFE=	yes
.else
CONFIGURE_ARGS+=--with-build-config=bootstrap-debug
ALL_TARGET=	bootstrap-lean
PIE_UNSAFE=	yes
.endif
INSTALL_TARGET=	install-strip
.if ${UID} != 0
BINMODE=	755
.endif
CONFIGURE_ARGS+=--disable-nls \
		--disable-libssp \
		--enable-gnu-indirect-function \
		--enable-host-shared \
		--enable-plugin \
		--libdir=${TARGLIB} \
		--libexecdir=${LIBEXEC} \
		--program-suffix=${SUFFIX} \
		--with-as=${LOCALBASE}/bin/as \
		--with-gmp=${LOCALBASE} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/ \
		--with-gxx-libcxx-include-dir=/usr/include/c++/v1 \
		--with-ld=${LOCALBASE}/bin/ld \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection" \
		--with-system-zlib \
		--without-zstd
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
		gcc${SUFFIX}/libgccjit \
		gcc${SUFFIX}/libgomp
.if ${ARCH} == amd64 || ${ARCH} == i386
INFO+=		gcc${SUFFIX}/libquadmath
.endif
.if ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == aarch64 || ${ARCH:Marmv?}
INFO+=		gcc${SUFFIX}/libitm
.endif
SUB_FILES=	pkg-message
SUB_LIST+=	TARGLIB=${TARGLIB}

CONFIGURE_ARGS+=--enable-languages=${LANGUAGES}

.if (${ARCH} == amd64 || ${ARCH} == powerpc64) && ${PORT_OPTIONS:MMULTILIB}
USE_LDCONFIG32=	${TARGLIB32}/gcc${SUFFIX}
.endif

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
	${RM} ${STAGEDIR}${PREFIX}/share/man/man7/*
	${RM} -r ${STAGEDIR}${TARGLIB}/gcc/*/${GCC_VERSION}/include-fixed/
	# Install ISO_Fortran_binding.h in an easily findable directory
	${MKDIR} ${STAGEDIR}${PREFIX}/include/gcc${SUFFIX}
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/lib/gcc${SUFFIX}/gcc/${CONFIGURE_TARGET}/${GCC_VERSION}/include/ISO_Fortran_binding.h	\
		${STAGEDIR}${PREFIX}/include/gcc${SUFFIX}
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
