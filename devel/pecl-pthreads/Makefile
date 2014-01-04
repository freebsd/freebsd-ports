# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	pthreads
PORTVERSION=	0.0.45
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Compatible Threading API for PHP5.3+

LICENSE=	PHP301

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	pthreads
IGNORE_WITH_PHP=	52

.include <bsd.port.options.mk>

.if !defined(PHP_ZTS) && exists(${LOCALBASE}/bin/php)
PHP_ZTS!=	${LOCALBASE}/bin/php -r 'phpinfo();' | ${GREP} 'Thread Safety' | ${AWK} -F '=> ' '{print $$2}'
.else
PHP_ZTS=	disabled
.endif

.if ${PHP_ZTS} == "disabled"
IGNORE=		pthreads requires ZTS, please re-compile PHP with ZTS enabled
.endif

.include <bsd.port.mk>
