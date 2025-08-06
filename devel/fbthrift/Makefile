PORTNAME=	fbthrift
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.08.04.00
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Facebook's branch of Apache Thrift, including a new C++ server
WWW=		https://github.com/facebook/fbthrift

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	compilation fails, see https://github.com/facebook/fbthrift/issues/623
BROKEN_armv7=	compilation fails, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=283484

BUILD_DEPENDS=	range-v3>0:devel/range-v3
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libbzip2.so:misc/vxl \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfizz.so:security/fizz \
		libfmt.so:devel/libfmt \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libicui18n.so:devel/icu \
		liblz4.so:archivers/liblz4 \
		libmvfst_state_machine.so:net/mvfst \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium \
		libunwind.so:devel/libunwind \
		libwangle.so:net/wangle \
		libxxhash.so:devel/xxhash \
		libzstd.so:archivers/zstd

USES=		bison cmake:testing compiler:c++17-lang ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	facebook

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	enable_tests

CXXFLAGS+=	-fPIC # https://github.com/facebook/fbthrift/issues/399
CXXFLAGS+=	-DGLOG_USE_GLOG_EXPORT

post-install: # https://github.com/facebook/fbthrift/issues/393
	@${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete

do-test: # no 'test' target, contrary to what the documentation says, see https://github.com/facebook/fbthrift/issues/533
	@cd ${TEST_WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.mk>
