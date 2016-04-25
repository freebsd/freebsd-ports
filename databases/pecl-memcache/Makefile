# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	memcache
PORTVERSION=	3.0.8
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Memcached extension

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	does not build

OPTIONS_DEFINE=	EXAMPLES

CONFIGURE_ARGS=	--with-zlib-dir=/usr
IGNORE_WITH_PHP=70
USE_CSTD=	gnu89
USE_PHP=	zlib session
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USES=		dos2unix tar:tgz

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/example.php ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
