# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	pthreads
PORTVERSION=	2.0.10
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Compatible Threading API for PHP5.3+

LICENSE=	PHP301

CFLAGS+=	-I${LOCALBASE}/include

USES=		php:pecl

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
