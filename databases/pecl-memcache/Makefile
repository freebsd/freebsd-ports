# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	memcache
PORTVERSION=	3.0.8
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Memcached extension

OPTIONS_DEFINE=	EXAMPLES

CONFIGURE_ARGS=	--with-zlib-dir=/usr
USE_DOS2UNIX=	yes
USE_PHP=	zlib session
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_CSTD=	gnu89

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/example.php ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
