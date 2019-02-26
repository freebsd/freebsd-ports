# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.9.4
PORTREVISION=	10
CATEGORIES=	lang
MASTER_SITES=	GCC
PKGNAMESUFFIX=	${SUFFIX}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	GNU Compiler Collection 4.9

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

DEPRECATED=	Unsupported by upstream. Use GCC 7 or newer instead.
EXPIRATION_DATE=2019-04-26
ONLY_FOR_ARCHS=	amd64 armv6 i386 powerpc powerpc64 sparc64

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	runtest:misc/dejagnu
.endif

USES=		compiler cpe gmake iconv libtool makeinfo perl5 tar:bzip2
USE_BINUTILS=	yes
USE_PERL5=	build

CPE_VENDOR=	gnu

GCC_VERSION=	${PORTVERSION}
SUFFIX=		${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}
SSP_UNSAFE=	yes

OPTIONS_DEFINE=		BOOTSTRAP
OPTIONS_DEFAULT=	BOOTSTRAP
BOOTSTRAP_DESC=		Build using a full bootstrap

.if exists(/usr/lib32/libc.so)
OPTIONS_DEFINE_powerpc64+=	MULTILIB
OPTIONS_DEFAULT_powerpc64+=	MULTILIB
MULTILIB_DESC=		Build support for 32-bit and 64-bit targets
MULTILIB_CONFIGURE_ENABLE=	multilib
.else
CONFIGURE_ARGS+=	--disable-multilib
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.endif

.if ${ARCH} == powerpc64
CONFIGURE_ENV+=	UNAME_m="powerpc64"
.endif

.if ${ARCH} == armv6
# Override sys.mk including -O in CFLAGS which breaks libgomp building.
CFLAGS:=	${CFLAGS:S/-O/-O2/}
. if ${COMPILER_TYPE} == clang
.  if empty(PORT_OPTIONS:MBOOTSTRAP)
MAKE_ARGS+=CXXFLAGS+=-fbracket-depth=512
.  else
MAKE_ARGS+=STAGE1_CXXFLAGS+=-fbracket-depth=512
.  endif
. endif
.endif

LANGUAGES:=	c,c++,objc,fortran
TARGLIB=	${PREFIX}/lib/gcc${SUFFIX}
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
		--with-system-zlib \
		--disable-libgcj \
		--enable-languages=${LANGUAGES}
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
		gcc${SUFFIX}/libgomp \
		gcc${SUFFIX}/libitm \
		gcc${SUFFIX}/libquadmath
SUB_FILES=	pkg-message
SUB_LIST+=	TARGLIB=${TARGLIB}

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for ${CONFIGURE_TARGET} [${LANGUAGES}]"

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.[ch]' | \
	    ${XARGS} ${EGREP} -l '"(HOST_WIDE|PLUGIN_COND)' | \
	    ${XARGS} ${REINPLACE_CMD} -E -e 's/"(HOST_WIDE|PLUGIN_COND)/" \1/g'

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
.for d in ${TARGLIB:S/^${PREFIX}\///} ${LIBEXEC:S/^${PREFIX}\///}
	cd ${STAGEDIR}${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
