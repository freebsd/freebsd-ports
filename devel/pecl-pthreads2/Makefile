# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	pthreads
PORTVERSION=	2.0.10
CATEGORIES=	devel
PKGNAMESUFFIX=	2

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Compatible Threading API for PHP5.3+

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

PORTSCOUT=	limit:^2\.

CFLAGS+=	-I${LOCALBASE}/include

USES=		php:pecl
IGNORE_WITH_PHP=71 72 73

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
