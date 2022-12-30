PORTNAME=	couchbase
PORTVERSION=	3.2.2
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Couchbase Server PHP extension
WWW=		https://pecl.php.net/package/couchbase

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libcouchbase>=3.2.4:databases/libcouchbase
LIB_DEPENDS=	libcouchbase.so:databases/libcouchbase

USES=		php:build,pecl
USE_PHP=	json:build

.include <bsd.port.mk>
