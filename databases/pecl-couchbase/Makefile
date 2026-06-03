PORTNAME=	couchbase
PORTVERSION=	4.1.6
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/couchbase/couchbase-php-client/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Couchbase Server PHP extension
WWW=		https://pecl.php.net/package/couchbase \
		https://github.com/couchbase/couchbase-php-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:indirect compiler:c++17-lang php:build,pecl

CONFIGURE_ARGS=	COUCHBASE_CMAKE_EXTRA="-DCOUCHBASE_CXX_CLIENT_EMBED_MOZILLA_CA_BUNDLE=OFF"
NO_SHLIB_REQUIRES_GLOB=	libcouchbase_php_wrapper.so

.include <bsd.port.mk>
