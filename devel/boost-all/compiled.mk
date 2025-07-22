USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
MAKE_CMD?=	bjam
MAKEFILE=	#
MAKE_FLAGS=	#
ALL_TARGET=	stage
USES+=		compiler:c++17-lang
USE_CXXSTD=	gnu++17

LDFLAGS+=	-Wl,--as-needed

PLIST_SUB+=	BOOST_MAJOR_VER=${BOOST_MAJOR_VER} \
		BOOST_MINOR_VER=${BOOST_MINOR_VER} \
		BOOST_SHARED_LIB_VER=${BOOST_SHARED_LIB_VER}

PKG_MESSAGE_FILE_THREADS=	${PORTSDIR}/devel/boost-all/pkg-message.threads
PKG_MESSAGE_FILE_PYTHON=	${PORTSDIR}/devel/boost-all/pkg-message.python

MAKE_ARGS=	--layout=system \
		--prefix=${PREFIX} \
		-d2

# Our compiler-flags will be added AFTER those set by bjam. We remove
# the optimization level, because Boost sets it itself (to -O3 in case
# of gcc/g++):
MAKE_ARGS+=	cxxflags="${CXXFLAGS:N-O*}" cflags="${CFLAGS:N-O*}" linkflags="${LDFLAGS}"

MAKE_ARGS+=	--toolset=${CHOSEN_COMPILER_TYPE} \
		${_MAKE_JOBS}

DEBUG_MAKE_ARGS=	debug
DEBUG_MAKE_ARGS_OFF=	release

MAKE_ARGS+=	threading=multi \
		link=shared,static

MAKE_ARGS+=	optimization=speed
OPTIMIZED_CFLAGS_MAKE_ARGS=	inlining=full

# ccache build fails when using precompiled headers, on a cached build.
#
# base gcc 4.2.1 fails when using precompiled headers on 11.0+ kernel.
# https://lists.freebsd.org/pipermail/svn-src-all/2015-March/101722.html
MAKE_ARGS+=	pch=off

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && \
	((${OSVERSION} >= 1500000 && ${OSVERSION} < 1500017) || \
	${PORT_OPTIONS:MLLVM_FROM_PORTS})
USES+=	llvm:build
USES:=	${USES:Ncompiler\:*} # XXX avoid warnings
CHOSEN_COMPILER_TYPE=	clang
.endif

post-patch:
.if defined(USE_BINUTILS)
	@${ECHO} "using ${CHOSEN_COMPILER_TYPE} : : ${CXX} : <linkflags>-B${LOCALBASE}/bin ;" >> ${WRKSRC}/tools/build/src/user-config.jam
.else
	@${ECHO} "using ${CHOSEN_COMPILER_TYPE} : : ${CXX} ;" >> ${WRKSRC}/tools/build/src/user-config.jam
.endif
