PORTNAME=	php80
DISTVERSION=	8.0.30
PORTREVISION=	1
CATEGORIES=	lang devel www
MASTER_SITES=	PHP
DISTNAME=	php-${DISTVERSION}
DIST_SUBDIR=	php

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PHP Scripting Language
WWW=		https://www.php.net/

LICENSE=	PHP301

.if !defined(WITH_CLUSTER_ALLOW_TECHNICAL_DEBTS)
IGNORE=		PHP 8.0 is EOL; set WITH_CLUSTER_ALLOW_TECHNICAL_DEBTS=yes in make.conf to build it
.endif

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only built and tested on amd64 for a single deployment

BUILD_DEPENDS=	re2c>0:devel/re2c
LIB_DEPENDS=	\
		libargon2.so:security/libargon2 \
		libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libgd.so:graphics/gd \
		libonig.so:devel/oniguruma \
		libpcre2-8.so:devel/pcre2 \
		libpng.so:graphics/png \
		libzip.so:archivers/libzip

USES=		autoreconf:build compiler:c11 cpe gettext gnome jpeg localbase \
		pkgconfig ssl tar:xz
CPE_PRODUCT=	php
USE_GNOME=	libxml2
USE_RC_SUBR=	php-fpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=\
		--disable-all \
		--disable-cgi \
		--enable-ctype \
		--enable-dom \
		--enable-fileinfo \
		--enable-filter \
		--enable-fpm \
		--enable-gd \
		--enable-mbstring \
		--enable-mysqlnd \
		--enable-opcache \
		--enable-pcntl \
		--enable-posix \
		--enable-simplexml \
		--program-prefix="" \
		--with-config-file-scan-dir=${PREFIX}/etc/php \
		--with-curl=${LOCALBASE} \
		--with-external-gd \
		--with-external-pcre=${LOCALBASE} \
		--with-fpm-user=${WWWOWN} \
		--with-fpm-group=${WWWGRP} \
		--with-gettext=${LOCALBASE} \
		--with-layout=GNU \
		--with-libxml \
		--with-mysqli=mysqlnd \
		--with-openssl \
		--with-password-argon2=${LOCALBASE} \
		--with-zip \
		--with-zlib=/usr
CONFIGURE_ENV+=	ac_cv_decimal_fp_supported="no" \
		lt_cv_path_SED="sed" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto" \
		PHP_OPENSSL=yes

DESTDIRNAME=	INSTALL_ROOT

LDFLAGS=	-L${OPENSSLLIB} -lcrypto -lssl
LIBS+=		-lpthread

CONFLICTS_INSTALL=	php[0-9][0-9]${PKGNAMESUFFIX}

PHP_SAPI=cli fpm

OPTIONS_DEFINE=PHPDBG DEBUG DTRACE
OPTIONS_SUB=	yes

PHPDBG_DESC=	Interactive PHP debugger

DEBUG_CONFIGURE_ENABLE=debug
DTRACE_CONFIGURE_ENABLE=dtrace
PHPDBG_CONFIGURE_ENABLE=phpdbg
PHPDBG_VARS=	PHP_SAPI+=phpdbg

.include <bsd.port.options.mk>

.if ( ${OPSYS} == FreeBSD && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl3*}
CXXFLAGS+=	-DOPENSSL_API_COMPAT=0x30000000L
.endif

.if ${PORT_OPTIONS:MPHPDBG} && ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-phpdbg-debug
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/ext/php_config.h
	@${REINPLACE_CMD} -e "s|^;\(pid\)|\1|;s|^;\(pm\.[a-z_]*_servers\)|\1|" \
		${WRKSRC}/sapi/fpm/php-fpm.conf.in

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} MAKE=${MAKE_CMD} ./buildconf --force)

test: build
	@(cd ${WRKSRC} && ${MAKE} test)

post-install:
	${INSTALL_DATA} ${WRKSRC}/php.ini-development ${WRKSRC}/php.ini-production \
		${STAGEDIR}/${PREFIX}/etc
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/php
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/sbin/php-fpm

post-install-PHPDBG-on:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/phpdbg

.include <bsd.port.mk>
