PORTNAME=	mongo-cxx-driver
DISTVERSIONPREFIX=	r
# Note: mongo-cxx-driver > 4.0.0 requires mongo-c-driver 2.x
DISTVERSION=	4.4.1
CATEGORIES=	devel databases

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	MongoDB C++ driver
WWW=		https://github.com/mongodb/mongo-cxx-driver/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mongo-c-driver>=2.3.3:devel/mongo-c-driver
LIB_DEPENDS=	libmongoc2.so:devel/mongo-c-driver \
		libbson2.so:devel/libbson \
		libutf8proc.so:textproc/utf8proc

USES=		cmake compiler:c++17-lang pkgconfig ssl
USE_CXXSTD=	c++17
USE_GITHUB=	yes
GH_ACCOUNT=	mongodb

CMAKE_ARGS=	-DENABLE_ZLIB=SYSTEM \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_CXX_STANDARD=17 \
		-DBUILD_VERSION=${DISTVERSION}
CMAKE_OFF=	BUILD_TESTING \
		ENABLE_TESTS \
		ENABLE_UNINSTALL

.include <bsd.port.mk>
