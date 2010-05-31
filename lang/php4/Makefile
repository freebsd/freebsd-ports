# New ports collection makefile for:	php4
# Date created:				Tue Feb 18 11:17:13 CET 2003
# Whom:					Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	php4
PORTVERSION=	4.4.9
PORTREVISION?=	3
CATEGORIES?=	lang devel www
MASTER_SITES=	${MASTER_SITE_PHP:S,$,:release,} \
		http://downloads.php.net/ilia/:rc \
		http://downloads.php.net/jani/:rc
MASTER_SITE_SUBDIR=	distributions/:release
DISTNAME=	php-${PORTVERSION:S/.r/RC/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:release

MAINTAINER?=	ale@FreeBSD.org
COMMENT?=	PHP Scripting Language

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

USE_BZIP2=	yes
.if !defined(PKGNAMESUFFIX)
USE_AUTOTOOLS=	autoconf:262

CONFIGURE_ARGS=	--enable-versioning \
		--enable-memory-limit \
		--with-layout=GNU \
		--with-config-file-scan-dir=${PREFIX}/etc/php \
		--disable-all \
		--program-prefix=""

OPTIONS=	CLI "Build CLI version" on \
		CGI "Build CGI version" on \
		APACHE "Build Apache module" off \
		DEBUG "Enable debug" off \
		SUHOSIN "Enable Suhosin protection system (not for jails)" on \
		MULTIBYTE "Enable zend multibyte support" off \
		IPV6 "Enable ipv6 support" on \
		MAILHEAD "Enable mail header patch" off \
		REDIRECT "Enable force-cgi-redirect support (CGI only)" off \
		DISCARD "Enable discard-path support (CGI only)" off \
		FASTCGI "Enable fastcgi support (CGI only)" on \
		PATHINFO "Enable path-info-check support (CGI only)" on \
		OPENSSL "Build static OpenSSL extension" off \
		ZLIB "Build static zlib extension" off

CONFLICTS=	php5-5*

MAN1=		php-config.1 phpize.1

.include <bsd.port.pre.mk>

PATCH_DIST_STRIP=	-p1

.if !defined(WITHOUT_SUHOSIN)
PATCHFILES+=	suhosin-patch-${PORTVERSION}-0.9.6.patch.gz:suhosin
PATCH_SITES+=	http://download.suhosin.org/:suhosin
PLIST_SUB+=	SUHOSIN=""
.else
PLIST_SUB+=	SUHOSIN="@comment "
.endif

.if defined(WITH_MAILHEAD)
PATCHFILES+=	php-${PORTVERSION}-mail-header.patch:mail
PATCH_SITES+=	http://choon.net/opensource/php/:mail
.endif

.if !defined(WITHOUT_CLI)
PHP_SAPI+=	cli
PLIST_SUB+=	CLI=""
MAN1+=		php.1
.else
PLIST_SUB+=	CLI="@comment "
CONFIGURE_ARGS+=--disable-cli
.endif

.if !defined(WITHOUT_CGI)
PHP_SAPI+=	cgi
PLIST_SUB+=	CGI=""
.if defined(WITH_REDIRECT)
CONFIGURE_ARGS+=--enable-force-cgi-redirect
.endif
.if defined(WITH_DISCARD)
CONFIGURE_ARGS+=--enable-discard-path
.endif
.if !defined(WITHOUT_FASTCGI)
CONFIGURE_ARGS+=--enable-fastcgi
.endif
.if defined(WITHOUT_PATHINFO)
CONFIGURE_ARGS+=--disable-path-info-check
.endif
.else
PLIST_SUB+=	CGI="@comment "
CONFIGURE_ARGS+=--disable-cgi
.endif

.if defined(WITH_APACHE)
PHP_SAPI+=	mod
USE_APACHE=	1.3+
.include "${PORTSDIR}/Mk/bsd.apache.mk"
.if ${APACHE_VERSION} > 13
CONFIGURE_ARGS+=--with-apxs2=${APXS}
.else
CONFIGURE_ARGS+=--with-apxs=${APXS}
.endif
PKGMESSAGE=	${PKGDIR}/pkg-message.mod
MODULENAME=	lib${PORTNAME}
SHORTMODNAME=	${PORTNAME}
PLIST_SUB+=	APACHE=""
.else
PLIST_SUB+=	APACHE="@comment "
.endif

.if !defined(WITH_REGEX_TYPE) || ${WITH_REGEX_TYPE} == "php"
CONFIGURE_ARGS+=--with-regex=php
.elif defined(WITH_REGEX_TYPE) && ${WITH_REGEX_TYPE} == "system"
CONFIGURE_ARGS+=--with-regex=system
.elif defined(WITH_REGEX_TYPE) && ${WITH_REGEX_TYPE} == "apache"
CONFIGURE_ARGS+=--with-regex=apache
.endif

CONFIGURE_ENV+=	ac_cv_pthreads_lib=${PTHREAD_LIBS} \
		ac_cv_pthreads_cflags=${PTHREAD_CFLAGS} \
		pthreads_working="yes"

 MAKE_ENV+=      LDFLAGS="${LDFLAGS}"

.if defined(WITH_OPENSSL)
WITH_OPENSSL_BASE=	yes
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE} \
		--with-openssl-dir=${OPENSSLBASE}
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto -lssl
PHP_EXT_INC+=	openssl
.endif

.if defined(WITH_ZLIB)
CONFIGURE_ARGS+=--with-zlib=/usr
PHP_EXT_INC+=	zlib
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.if defined(WITH_MULTIBYTE)
CONFIGURE_ARGS+=--enable-zend-multibyte
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/ext/php_config.h
	@${REINPLACE_CMD} "s|^\(extension_dir\)|; \1|" ${WRKSRC}/php.ini-*

pre-configure:
	@${CAT} ${WRKSRC}/acinclude.m4 ${WRKSRC}/build/libtool.m4 > ${WRKSRC}/aclocal.m4

post-build:
	@${ECHO_CMD} "PHP_VER=4" > ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_VERSION=${PORTVERSION}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_SAPI=${PHP_SAPI}" >> ${WRKDIR}/php.conf
.if defined(PHP_EXT_INC)
	@${ECHO_CMD} "PHP_EXT_INC=${PHP_EXT_INC}" >> ${WRKDIR}/php.conf
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKSRC}/php.ini-recommended ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKDIR}/php.conf ${PREFIX}/etc
	@${TOUCH} ${PREFIX}/include/php/ext/php_config.h
.if defined(WITH_APACHE)
	@${CAT} ${PKGMESSAGE}
.endif

.else
.include "${MASTERDIR}/Makefile.ext"
.endif
.include <bsd.port.post.mk>
