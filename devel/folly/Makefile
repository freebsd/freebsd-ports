# $FreeBSD$

PORTNAME=	folly
DISTVERSIONPREFIX=	v
DISTVERSION=	2021.03.01.00
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library developed and used at Facebook

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_11=	bug in folly, confusion with Jemalloc: https://github.com/facebook/folly/issues/1458
BROKEN_i386=	error: use of undeclared identifier 'DCHECK': https://github.com/facebook/folly/issues/1168

LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfmt.so:devel/libfmt \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		liblz4.so:archivers/liblz4 \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium \
		libunwind.so:devel/libunwind \
		libzstd.so:archivers/zstd
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake compiler:c++17-lang ssl
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	FREEBSD_BUILD_EXAMPLES FREEBSD_FOLLY_USE_SYMBOLIZER # enabling symbolizer causes undefined symbol _r_debug, see https://github.com/facebook/folly/issues/1373

CXXFLAGS+=	-fPIC

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
