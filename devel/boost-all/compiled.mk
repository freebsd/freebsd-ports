USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
MAKE_CMD=	bjam
MAKEFILE=	#
MAKE_FLAGS=	#
ALL_TARGET=	stage
USES+=		compiler:c++11-lang

PLIST_SUB+=	BOOST_SHARED_LIB_VER=${PORTVERSION}

PKG_MESSAGE_FILE_THREADS=	${PORTSDIR}/devel/boost-all/pkg-message.threads
PKG_MESSAGE_FILE_PYTHON=	${PORTSDIR}/devel/boost-all/pkg-message.python

MAKE_ARGS=	--layout=system \
		--prefix=${PREFIX} \
		-d2

# Our compiler-flags will be added AFTER those set by bjam. We remove
# the optimization level, because Boost sets it itself (to -O3 in case
# of gcc/g++):
MAKE_ARGS+=    cxxflags="${CXXFLAGS:N-O*}" cflags="${CFLAGS:N-O*}"

MAKE_ARGS+=	--toolset=${CHOSEN_COMPILER_TYPE} \
		${_MAKE_JOBS}

DEBUG_MAKE_ARGS=	debug
DEBUG_MAKE_ARGS_OFF=	release

MAKE_ARGS+=	threading=multi \
		link=shared,static

MAKE_ARGS+=	optimization=speed
OPTIMIZED_CFLAGS_MAKE_ARGS=	inlining=full

# ccache build fails when using precompiled headers, on a cached build.
.if defined(WITH_CCACHE_BUILD)
BJAM_ARGS+=	pch=off
.endif

post-patch:
.if defined(USE_BINUTILS)
	@${ECHO} "using ${CHOSEN_COMPILER_TYPE} : : ${CXX} : <linkflags>-B${LOCALBASE}/bin ;" >> ${WRKSRC}/tools/build/v2/user-config.jam
.else
	@${ECHO} "using ${CHOSEN_COMPILER_TYPE} : : ${CXX} ;" >> ${WRKSRC}/tools/build/v2/user-config.jam
.endif
