PORTNAME=	couchbase
DISTVERSION=	3.2.2
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Couchbase Server PHP extension
WWW=		https://pecl.php.net/package/couchbase

LICENSE=	APACHE20

BUILD_DEPENDS=	libcouchbase>=3.3.2:databases/libcouchbase
LIB_DEPENDS=	libcouchbase.so:databases/libcouchbase

USES=		php:build,pecl
USE_PHP=	json:build

IGNORE_WITH_PHP=81 82

.include <bsd.port.mk>
