
USE_GCC=	4.2+
USE_LDCONFIG=	yes
BOOST_SHARED_LIB_VER=	4
PKGMESSAGE=	${WRKDIR}/pkg-message
BJAM=		bjam

PLIST_SUB+=	BOOST_SHARED_LIB_VER=${BOOST_SHARED_LIB_VER}

PKG_MESSAGE_FILE_THREADS=	${PORTSDIR}/devel/boost-all/pkg-message.threads
PKG_MESSAGE_FILE_PYTHON=	${PORTSDIR}/devel/boost-all/pkg-message.python

BOOST_TOOLS=	gcc

BJAM_OPTIONS=	--layout=system --disable-long-double
.if defined (WITH_VERBOSE_BUILD)
BJAM_OPTIONS+=	-d2
.endif

.if defined (WITHOUT_DEBUG)
BJAM_OPTIONS+=	variant=release
.else
BJAM_OPTIONS+=	variant=debug
.endif

BJAM_OPTIONS+=	threading=multi

# Unless WITH_OPTIMIZED_CFLAGS is defined, the port uses
# CXXFLAGS as defined by the user (overridng Boost's 'speed'
# configuration scheme
BJAM_OPTIONS+=	optimization=speed
.if defined (WITH_OPTIMIZED_CFLAGS)
BJAM_OPTIONS+=	inlining=full
CXXFLAGS=	-O3
.endif

customize-boost-build:
# Do the right thing(tm) for pthread support and respect CXX
	@${REINPLACE_CMD}\
		-e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|'\
		-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|'\
		-e 's|%%CXX%%|${CXX}|'\
		-e 's|%%CXXFLAGS%%|${CXXFLAGS}|'\
	${WRKSRC}/tools/build/v2/tools/gcc.jam

	@${REINPLACE_CMD}\
		-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:S/-//}|'\
	${WRKSRC}/tools/build/v2/tools/python.jam
