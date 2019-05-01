# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	pthreads
PORTVERSION=	3.1.6
CATEGORIES=	devel

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Compatible Threading API for PHP7.0+

LICENSE=	PHP301

DEPRECATED=	Does not work with recent versions of php
EXPIRATION_DATE=	2019-06-02

CFLAGS+=	-I${LOCALBASE}/include

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

# We cannot use IGNORE here, the package gets ignored anyway because the
# ignore'd status is checked without any dependency installed.
pre-configure:
	@if ! ${LOCALBASE}/bin/php -r 'phpinfo();' | ${GREP} -q 'Thread Safety => enabled'; then \
		${ECHO_MSG} "===>  ${PKGNAME} pthreads requires ZTS, please re-compile PHP with ZTS enabled." | ${FMT_80} ; \
		false ; \
	fi

.include <bsd.port.mk>
