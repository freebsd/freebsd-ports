PORTNAME=	couchbase
PORTVERSION=	4.1.2
CATEGORIES=	databases
MASTER_SITES=	https://github.com/couchbase/couchbase-php-client/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Couchbase Server PHP extension
WWW=		https://pecl.php.net/package/couchbase \
		https://github.com/couchbase/couchbase-php-client

LICENSE=	APACHE20

BUILD_DEPENDS=	cmake:devel/cmake-core

USES=		compiler:c++17-lang php:build,pecl

.include <bsd.port.mk>
