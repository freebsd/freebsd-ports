USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
BJAM=		bjam
USES+=		compiler:c++11-lang

PLIST_SUB+=	BOOST_SHARED_LIB_VER=${PORTVERSION} COMPAT_LIB_VER=5

PKG_MESSAGE_FILE_THREADS=	${PORTSDIR}/devel/boost-all/pkg-message.threads
PKG_MESSAGE_FILE_PYTHON=	${PORTSDIR}/devel/boost-all/pkg-message.python

.include <bsd.port.pre.mk>

BJAM_ARGS=	--layout=system \
		--prefix=${PREFIX} \

.if ${ARCH} == amd64
BJAM_ARGS+=	cxxflags=-fPIC
.endif

# Our compiler-flags will be added AFTER those set by bjam. We remove
# the optimization level, because Boost sets it itself (to -O3 in case
# of gcc/g++):
BJAM_ARGS+=    cxxflags="${CXXFLAGS:N-O*}" cflags="${CFLAGS:N-O*}"

BOOST_TOOLSET=	${CHOSEN_COMPILER_TYPE}

BJAM_ARGS+=	--toolset=${BOOST_TOOLSET} \
		${_MAKE_JOBS}

.if ${PORT_OPTIONS:MVERBOSE_BUILD}
BJAM_ARGS+=	-d2
.endif

.if ${PORT_OPTIONS:MDEBUG}
BJAM_ARGS+=	debug
.else
BJAM_ARGS+=	release
.endif

BJAM_ARGS+=	threading=multi \
		link=shared,static

BJAM_ARGS+=	optimization=speed
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
BJAM_ARGS+=	inlining=full
.endif

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
