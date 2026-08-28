PORTNAME=	mongo-cxx-driver
DISTVERSIONPREFIX=	r
DISTVERSION=	4.5.1
CATEGORIES=	devel databases

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	MongoDB C++ driver
WWW=		https://github.com/mongodb/mongo-cxx-driver/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# mongo-c-driver requirement more specific than LIB_DEPENDS can express
BUILD_DEPENDS=	mongo-c-driver>=2.3.3:devel/mongo-c-driver
LIB_DEPENDS=	libmongoc2.so:devel/mongo-c-driver \
		libbson2.so:devel/libbson \
		libutf8proc.so:textproc/utf8proc
RUN_DEPENDS=	mongo-c-driver>=2.3.3:devel/mongo-c-driver

USES=		cmake compiler:c++17-lang pkgconfig ssl
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	mongodb

# USE_CXXSTD=c++17 gets overridden with the default c++11 by cmake
CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=Release \
		-DENABLE_ZLIB=SYSTEM \
		-DCMAKE_CXX_STANDARD=17 \
		-DBUILD_VERSION=${DISTVERSION}
CMAKE_OFF=	BUILD_TESTING \
		ENABLE_TESTS \
		ENABLE_UNINSTALL

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
