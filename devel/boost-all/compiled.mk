USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
BJAM=		bjam
USES+=		compiler:c++11-lang

PLIST_SUB+=	BOOST_SHARED_LIB_VER=${PORTVERSION} COMPAT_LIB_VER=5

PKG_MESSAGE_FILE_THREADS=	${PORTSDIR}/devel/boost-all/pkg-message.threads
PKG_MESSAGE_FILE_PYTHON=	${PORTSDIR}/devel/boost-all/pkg-message.python

BJAM_ARGS=	--layout=system \
		--prefix=${PREFIX} \

# Our compiler-flags will be added AFTER those set by bjam. We remove
# the optimization level, because Boost sets it itself (to -O3 in case
# of gcc/g++):
BJAM_ARGS+=    cxxflags="${CXXFLAGS:N-O*}" cflags="${CFLAGS:N-O*}"

BOOST_TOOLSET=	${CHOSEN_COMPILER_TYPE}

BJAM_ARGS+=	--toolset=${BOOST_TOOLSET} \
		${_MAKE_JOBS}

VERBOSE_BUILD_VARS=	BJAM_ARGS+=-d2

DEBUG_VARS=	BJAM_ARGS+=debug
DEBUG_VARS_OFF=	BJAM_ARGS+=release

BJAM_ARGS+=	threading=multi \
		link=shared,static

BJAM_ARGS+=	optimization=speed
OPTIMIZED_CFLAGS_VARS=	BJAM_ARGS+=inlining=full

# ccache build fails when using precompiled headers, on a cached build.
.if defined(WITH_CCACHE_BUILD)
BJAM_ARGS+=	pch=off
.endif

post-patch:
.if defined(USE_BINUTILS)
	@${ECHO} "using ${BOOST_TOOLSET} : : ${CXX} : <linkflags>-B${LOCALBASE}/bin ;" >> ${WRKSRC}/tools/build/v2/user-config.jam
.else
	@${ECHO} "using ${BOOST_TOOLSET} : : ${CXX} ;" >> ${WRKSRC}/tools/build/v2/user-config.jam
.endif
