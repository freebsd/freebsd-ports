PORTNAME=	libmemcached
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C/C++ client library and tools for the memcached server
WWW=		https://awesomized.github.io/libmemcached/ \
		https://github.com/awesomized/libmemcached

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent
TEST_DEPENDS=	memcached:databases/memcached \
		onetbb>=0:devel/onetbb

USES=		bison compiler:c++11-lang pkgconfig ssl

CMAKE_OFF=	BUILD_DOCSONLY \
		BUILD_DOCS_MANGZ \
		BUILD_DOCS_HTML \
		BUILD_TESTING \
		ENABLE_DTRACE
CMAKE_ON=	BUILD_SHARED_LIBS \
		ENABLE_MEMASLAP \
		ENABLE_OPENSSL_CRYPTO
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	awesomized

OPTIONS_DEFINE=	DOCS MANPAGES SASL
OPTIONS_GROUP=	HASH
OPTIONS_GROUP_HASH=	FNV64 HSIEH MURMUR
OPTIONS_DEFAULT=FNV64 HSIEH MURMUR SASL
OPTIONS_SUB=	yes
FNV64_DESC=	Enable fnv64 hashing
HSIEH_DESC=	Enable hsieh hashing
MEMASLAP_DESC=	Load generation and benchmark tool
MURMUR_DESC=	Enable murmur hashing

FNV64_CMAKE_BOOL=	ENABLE_HASH_FNV64
HSIEH_CMAKE_BOOL=	ENABLE_HASH_HSIEH
MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_CMAKE_BOOL=	BUILD_DOCS BUILD_DOCS_MAN
MANPAGES_USES=		cmake:noninja,testing python:env
MANPAGES_USES_OFF=	cmake:testing
MURMUR_CMAKE_BOOL=	ENABLE_HASH_MURMUR
SASL_CMAKE_BOOL=	ENABLE_SASL
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

.include <bsd.port.mk>
