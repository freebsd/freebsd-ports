PORTNAME=	libmongocrypt
DISTVERSION=	1.20.0
CATEGORIES=	databases

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	MongoDB companion C library for client side encryption in drivers
WWW=		https://github.com/mongodb/libmongocrypt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbson2.so:devel/libbson \
		libmongoc2.so:devel/mongo-c-driver

USES=		cmake cpe python:build ssl

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb

USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_VERSION=${DISTVERSION} \
		-DMONGOCRYPT_MONGOC_DIR="USE-SYSTEM" \
		-DMONGOCRYPT_CRYPTO=OpenSSL
CMAKE_ON=	USE_SHARED_LIBBSON
CMAKE_OFF=	BUILD_TESTING ENABLE_ONLINE_TESTS \
		MONGOCRYPT_ENABLE_DECIMAL128

CPE_VENDOR=	${GH_ACCOUNT}

.include <bsd.port.mk>
