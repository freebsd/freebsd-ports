PORTNAME=	couchbase
PORTVERSION=	4.1.4
CATEGORIES=	databases
MASTER_SITES=	https://github.com/couchbase/couchbase-php-client/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Couchbase Server PHP extension
WWW=		https://pecl.php.net/package/couchbase \
		https://github.com/couchbase/couchbase-php-client

LICENSE=	APACHE20

BUILD_DEPENDS=	cmake:devel/cmake-core

USES=		compiler:c++17-lang php:build,pecl

CONFIGURE_ARGS=	COUCHBASE_CMAKE_EXTRA="-DCOUCHBASE_CXX_CLIENT_EMBED_MOZILLA_CA_BUNDLE=OFF"

.include <bsd.port.mk>
