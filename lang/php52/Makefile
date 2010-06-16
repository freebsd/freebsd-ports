# New ports collection makefile for:	php52
# Date created:				17 Apr 2010
# Whom:					Alex Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	php52
PORTVERSION=	5.2.13
PORTREVISION=	3
CATEGORIES?=	lang devel www
MASTER_SITES=	${MASTER_SITE_PHP}
MASTER_SITE_SUBDIR=	distributions
DISTNAME=	php-${PORTVERSION}

MAINTAINER=	admin@lissyara.su
COMMENT=	PHP Scripting Language

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes
.if !defined(PKGNAMESUFFIX)
USE_AUTOTOOLS=	autoconf:262

CONFIGURE_ARGS=	\
		--with-layout=GNU \
		--with-config-file-scan-dir=${PREFIX}/etc/php \
		--disable-all \
		--enable-libxml \
		--with-libxml-dir=${LOCALBASE} \
		--enable-reflection \
		--program-prefix=""

USE_GNOME=	libxml2

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
		FPM "Enable fastcgi process manager (CGI only)" off \
		PATHINFO "Enable path-info-check support (CGI only)" on

CONFLICTS=	php4-4* php5-5.3*

MAN1=		php-config.1 phpize.1

.include <bsd.port.pre.mk>

PATCH_DIST_STRIP=	-p1

.if defined(WITH_FPM) && defined(WITH_CGI)
. if defined(WITHOUT_FASTCGI)
IGNORE=		FPM requires FastCGI support
. endif
PATCHFILES+=	php-5.2.13-fpm-0.5.14-freebsd.patch.gz
PATCH_SITES+=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR+=	mm
LIB_DEPENDS+=	event-1.4:${PORTSDIR}/devel/libevent
PHP_FPM_UID?=	www
PHP_FPM_GID?=	www
PHP_FPM_PID?=	/var/run/php-fpm/php-fpm.pid
PHP_FPM_LOG?=	/var/log/php-fpm/php-fpm.log
SUB_FILES+=	php-fpm.conf.sample
SUB_LIST+=	PHP_FPM_UID=${PHP_FPM_UID} \
		PHP_FPM_GID=${PHP_FPM_GID} \
		PHP_FPM_PID=${PHP_FPM_PID} \
		PHP_FPM_LOG=${PHP_FPM_LOG}
USE_RC_SUBR+=	php-fpm
PLIST_SUB+=	FPM="" \
		PHP_FPM_PID=${PHP_FPM_PID} \
		PHP_FPM_LOG=${PHP_FPM_LOG}

CONFIGURE_ARGS+=	--enable-fpm \
			--with-fpm-conf=${PREFIX}/etc/php-fpm.conf \
			--with-fpm-pid=${PHP_FPM_PID} \
			--with-fpm-log=${PHP_FPM_LOG} \
			--with-libevent=${LOCALBASE}
.else
PLIST_SUB+=	FPM="@comment "
.endif

.if !defined(WITHOUT_SUHOSIN)
PATCHFILES+=	suhosin-patch-${PORTVERSION}-0.9.7.patch.gz:suhosin
PATCH_SITES+=	http://download.suhosin.org/:suhosin
PLIST_SUB+=	SUHOSIN=""
.else
PLIST_SUB+=	SUHOSIN="@comment "
.endif

.if defined(WITH_MAILHEAD)
#PATCHFILES+=	php-${PORTVERSION}-mail-header.patch:mail
PATCHFILES+=	php-5.2.10-mail-header.patch:mail
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
MODULENAME=	libphp5
SHORTMODNAME=	php5
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

.if !defined(WITH_ZEND_VM) || ${WITH_ZEND_VM} == "CALL"
CONFIGURE_ARGS+=--with-zend-vm=CALL
.elif defined(WITH_ZEND_VM) && ${WITH_ZEND_VM} == "SWITCH"
CONFIGURE_ARGS+=--with-zend-vm=SWITCH
.elif defined(WITH_ZEND_VM) && ${WITH_ZEND_VM} == "GOTO"
CONFIGURE_ARGS+=--with-zend-vm=GOTO
.endif

CONFIGURE_ENV+=	ac_cv_pthreads_lib="" \
		ac_cv_pthreads_cflags="" \
		pthreads_working="yes" \
		lt_cv_path_SED="sed"

MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

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
.if defined(WITH_FPM) && defined(WITH_CGI)
	@${REINPLACE_CMD} -e 's,BUILD_CGI=\"\\$$\(.*\)\\$$(EXTRA_LIBS),BUILD_CGI=\"\\$$\1\\$$(EXTRA_LIBS) \\$$(SAPI_EXTRA_LIBS),g' \
		${WRKSRC}/sapi/cgi/config9.m4
.endif

pre-configure:
	@${CAT} ${WRKSRC}/acinclude.m4 ${WRKSRC}/build/libtool.m4 > ${WRKSRC}/aclocal.m4

post-build:
	@${ECHO_CMD} "PHP_VER=52" > ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_VERSION=${PORTVERSION}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_SAPI=${PHP_SAPI}" >> ${WRKDIR}/php.conf

post-install:
	@${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKSRC}/php.ini-recommended ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKDIR}/php.conf ${PREFIX}/etc
	@${TOUCH} ${PREFIX}/include/php/ext/php_config.h
.if defined(WITH_FPM) && defined(WITH_CGI)
	@${INSTALL_DATA} ${WRKDIR}/php-fpm.conf.sample ${PREFIX}/etc
	@${MKDIR} `dirname ${PHP_FPM_PID}`
	@${MKDIR} `dirname ${PHP_FPM_LOG}`
	@cd ${PREFIX}/etc && ${CP} -n php-fpm.conf.sample php-fpm.conf
.endif
.if defined(WITH_APACHE)
	@${CAT} ${PKGMESSAGE}
.endif

.else
.include "${MASTERDIR}/Makefile.ext"
.endif
.include <bsd.port.post.mk>
