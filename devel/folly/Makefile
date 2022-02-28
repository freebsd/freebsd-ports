PORTNAME=	folly
DISTVERSIONPREFIX=	v
DISTVERSION=	2022.02.28.00
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library developed and used at Facebook

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	error: use of undeclared identifier 'DCHECK': https://github.com/facebook/folly/issues/1168

BUILD_DEPENDS=	elfutils>0:devel/elfutils # workaround for missing symbols like DW_UT_compile: https://github.com/facebook/folly/issues/1654
LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfmt.so:devel/libfmt \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libicui18n.so:devel/icu \
		liblz4.so:archivers/liblz4 \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium \
		libunwind.so:devel/libunwind \
		libzstd.so:archivers/zstd
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake compiler:c++17-lang cpe ssl
CPE_VENDOR=	facebook
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	FREEBSD_BUILD_EXAMPLES FREEBSD_FOLLY_USE_SYMBOLIZER # enabling symbolizer causes undefined symbol _r_debug, see https://github.com/facebook/folly/issues/1373

CXXFLAGS+=	-fPIC
CXXFLAGS_powerpc64=	-DFOLLY_QUOTIENT_MULTI_SET_SUPPORTED=0

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
