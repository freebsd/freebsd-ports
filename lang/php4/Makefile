# New ports collection makefile for:	php4
# Date created:				Tue Feb 18 11:17:13 CET 2003
# Whom:					Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	php4
PORTVERSION=	4.3.8
PORTREVISION?=	2
CATEGORIES?=	lang devel www
MASTER_SITES=	${MASTER_SITE_PHP:S,$,:release,} \
		http://downloads.php.net/ilia/:rc \
		http://downloads.php.net/jani/:rc
MASTER_SITE_SUBDIR=	distributions/:release
DISTNAME=	php-${PORTVERSION:S/.r/RC/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:release

MAINTAINER?=	ale@FreeBSD.org
COMMENT?=	PHP Scripting Language (Apache Module and CLI)

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

USE_BZIP2=	yes
.if !defined(PKGNAMESUFFIX) || ${PKGNAMESUFFIX} == "-cgi" || ${PKGNAMESUFFIX} == "-cli"
GNU_CONFIGURE=	yes
USE_BISON=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--enable-versioning \
		--enable-memory-limit \
		--with-layout=GNU \
		--with-config-file-scan-dir=${PREFIX}/etc/php \
		--disable-all

.if !defined(WITH_REGEX_TYPE) || ${WITH_REGEX_TYPE} == "php"
CONFIGURE_ARGS+=--with-regex=php
.else
.if ${WITH_REGEX_TYPE} == "system"
CONFIGURE_ARGS+=--with-regex=system
.else
.if ${WITH_REGEX_TYPE} == "apache"
CONFIGURE_ARGS+=--with-regex=apache
.endif
.endif
.endif

.if !defined(PKGNAMEPREFIX) && !defined(PKGNAMESUFFIX)
PHP_SAPI=	full
WITH_APACHE=	yes
.else
.if !defined(PKGNAMEPREFIX)
PHP_SAPI=	${PKGNAMESUFFIX:S/-//}
.else
PHP_SAPI=	${PKGNAMEPREFIX:S/_//}
WITH_APACHE=	yes
.endif
.endif

.if defined(WITH_APACHE)
PKGMESSAGE=	${PKGDIR}/pkg-message.mod
.endif

.if ${PHP_SAPI} == "cgi"
OPTIONS=	REDIRECT "Enable force-cgi-redirect support" off \
		DISCARD "Enable discard-path support" off \
		FASTCGI "Enable fastcgi support" off \
		PATHINFO "Enable path-info-check support" on
.endif
.if defined(WITH_APACHE)
OPTIONS=	APACHE2 "Use apache 2.x instead of apache 1.3.x" off
.endif
OPTIONS+=	DEBUG "Enable debug" off \
		IPV6 "Enable ipv6 support" on

EXT_DIR=	20020429

CONFLICTS?=	php4-cli-4* mod_php4-4* php4-cgi-4*
CONFLICTS+=	php5-5* php5-cli-5* mod_php5-5* php5-cgi-5*

.if ${PHP_SAPI} == "cgi" || ${PHP_SAPI} == "mod"
CONFIGURE_ARGS+=--disable-cli
.endif

.if ${PHP_SAPI} == "full" || ${PHP_SAPI} == "cli"
PLIST_SUB+=	CLI=""
MAN1=		php.1
.else
PLIST_SUB+=	CLI="@comment "
.endif

.if defined(WITH_APACHE)
PLIST_SUB+=	APACHE=""
.else
PLIST_SUB+=	APACHE="@comment "
.endif

.if ${PHP_SAPI} == "cli"
CONFIGURE_ARGS+=--disable-cgi
SAPI_FILE=	"@comment "
.endif

.if ${PHP_SAPI} == "cgi"
SAPI_FILE=	bin/php
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500016
WITH_PTHREAD_LIBS?=	${PTHREAD_LIBS:S/-l//}
WITH_PTHREAD_CFLAGS?=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	ac_cv_pthreads_lib=${WITH_PTHREAD_LIBS} \
		ac_cv_pthreads_cflags=${WITH_PTHREAD_CFLAGS}
.endif

.if defined(WITH_APACHE)
.if exists(${LOCALBASE}/include/apache2/httpd.h)
WITH_APACHE2=	yes
APACHE_MPM!=	${APXS} -q MPM_NAME
.endif
.if defined(WITH_APACHE2)
APACHE_MPM?=	${WITH_MPM}
APACHE_PORT=	www/apache2
CONFIGURE_ARGS+=--with-apxs2=${APXS}
SAPI_FILE=	libexec/apache2/libphp4.so
.if ${APACHE_MPM} == "worker"
EXT_DIR:=	${EXT_DIR}-zts
.endif
.else
APACHE_PORT?=	www/apache13
CONFIGURE_ARGS+=--with-apxs=${APXS}
SAPI_FILE=	libexec/apache/libphp4.so
.endif
BUILD_DEPENDS+=	${APXS}:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS+=	${APXS}:${PORTSDIR}/${APACHE_PORT}
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
EXT_DIR:=	${EXT_DIR}-debug
.endif

PLIST_SUB+=	SAPI_FILE=${SAPI_FILE}

.if ${OSVERSION} < 400014 || defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PHP_SAPI} == "cgi"
.if defined(WITH_REDIRECT)
CONFIGURE_ARGS+=--enable-force-cgi-redirect
.endif
.if defined(WITH_DISCARD)
CONFIGURE_ARGS+=--enable-discard-path
.endif
.if defined(WITH_FASTCGI)
CONFIGURE_ARGS+=--enable-fastcgi
.endif
.if defined(WITHOUT_PATHINFO)
CONFIGURE_ARGS+=--disable-path-info-check
.endif
.endif

_PORTSDIR!=	${REALPATH} ${PORTSDIR}
PHP_PORT=	${.CURDIR:S|^${_PORTSDIR}||:S|^/||}

post-patch:
	@${TOUCH} ${WRKSRC}/ext/php_config.h
	@${REINPLACE_CMD} "s|^\(extension_dir\)|; \1|" ${WRKSRC}/php.ini-*

.if ${PHP_SAPI} == "full"
pre-configure:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You are building the Apache Module and the Command Line Interpreter of PHP."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Use port:"
	@${ECHO_CMD} "	lang/php4-cli		for Command Line Interpreter only"
	@${ECHO_CMD} "	www/php4-cgi		for Common Gateway Interface only"
	@${ECHO_CMD} "	www/mod_php4		for Apache Module only"
	@${ECHO_CMD} ""
.endif

post-build:
	@${ECHO_CMD} "PHP_VER=4" > ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_VERSION=${PORTVERSION}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_EXT_DIR=${EXT_DIR}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_PORT=\$${PORTSDIR}/${PHP_PORT}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_SAPI=${PHP_SAPI}" >> ${WRKDIR}/php.conf

post-install:
	@${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKSRC}/php.ini-recommended ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKDIR}/php.conf ${PREFIX}/etc
	@${TOUCH} ${PREFIX}/include/php/ext/php_config.h
.if defined(WITH_APACHE)
	@${CAT} ${PKGMESSAGE}
.endif

.else
.if ${PKGNAMESUFFIX} == "-pear"
.include "${MASTERDIR}/Makefile.pear"
.else
.include "${MASTERDIR}/Makefile.ext"
.endif
.endif
.include <bsd.port.post.mk>
