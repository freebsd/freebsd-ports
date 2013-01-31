USE_LDCONFIG=	yes
BOOST_SHARED_LIB_VER=	5
PKGMESSAGE=	${WRKDIR}/pkg-message
MAKE_JOBS_SAFE=	yes
BJAM=		bjam

PLIST_SUB+=	BOOST_SHARED_LIB_VER=${BOOST_SHARED_LIB_VER}

PKG_MESSAGE_FILE_THREADS=	${PORTSDIR}/devel/boost-all/pkg-message.threads
PKG_MESSAGE_FILE_PYTHON=	${PORTSDIR}/devel/boost-all/pkg-message.python

BJAM_ARGS=	--layout=system \
		--prefix=${PREFIX}

.if ${ARCH} == amd64
BJAM_ARGS+=	cxxflags=-fPIC
.endif

NO_CCACHE=	yes
.if ${CC:T:Mgcc*}
BOOST_TOOLSET:=	gcc
.elif ${CC:T:Mclang}
BOOST_TOOLSET:=	clang
.else
_COMPILER_VERSION!=	${CC} --version
. if ${_COMPILER_VERSION:Mgcc}
BOOST_TOOLSET:=	gcc
. elif ${_COMPILER_VERSION:M\(GCC\)}
BOOST_TOOLSET:=	gcc
. elif ${_COMPILER_VERSION:Mclang}
BOOST_TOOLSET:=	clang
. else
.error Unable to determine compiler type for ${CC}
. endif
. undef _COMPILER_VERSION
.endif

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

post-patch:
	@${REINPLACE_CMD} -e 's|${PORTVERSION}|${BOOST_SHARED_LIB_VER}|g' \
		${WRKSRC}/Jamroot
