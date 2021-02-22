# $FreeBSD$

PORTNAME=	fbthrift
DISTVERSIONPREFIX=	v
DISTVERSION=	2021.02.22.00
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Facebook's branch of Apache Thrift, including a new C++ server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libfizz.so:security/fizz \
		libfmt.so:devel/libfmt \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libsodium.so:security/libsodium \
		libwangle.so:net/wangle \
		libzstd.so:archivers/zstd

USES=		bison cmake compiler:c++17-lang ssl
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

CXXFLAGS+=	-fPIC # https://github.com/facebook/fbthrift/issues/399

post-install: # https://github.com/facebook/fbthrift/issues/393
	${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete

.include <bsd.port.mk>
