# Created by: Alex Keda <admin@lissyara.su>
# $FreeBSD$

PORTNAME=	php52
PORTVERSION=	5.2.17
PORTREVISION?=	14
CATEGORIES?=	lang devel www
MASTER_SITES=	${MASTER_SITE_PHP}
MASTER_SITE_SUBDIR=	distributions
DISTNAME=	php-${PORTVERSION}

MAINTAINER=	admin@lissyara.su
COMMENT=	PHP Scripting Language

DEPRECATED=		PHP 5.2 series is strongly discouraged for new \
			installations, migrate now
EXPIRATION_DATE=	2013-09-01

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

# BACKPORTS patch for lang/php52 and all php52-extensions
PATCHFILES=	php52-backports-security-20130320.patch
PATCH_SITES+=	http://php52-backports.googlecode.com/files/

.if !defined(PKGNAMESUFFIX)
USE_AUTOTOOLS=	autoconf
AUTOTOOLSFILES=	scripts/phpize.in

CONFIGURE_ARGS=	\
		--with-layout=GNU \
		--with-config-file-scan-dir=${PREFIX}/etc/php \
		--disable-all \
		--enable-libxml \
		--with-libxml-dir=${LOCALBASE} \
		--enable-reflection \
		--program-prefix=""

USE_GNOME=	libxml2

OPTIONS_DEFINE=	CLI CGI APACHE DEBUG SUHOSIN MULTIBYTE IPV6 MAILHEAD REDIRECT DISCARD \
		FASTCGI FPM PATHINFO LINKTHR

OPTIONS_DEFAULT=	CLI CGI SUHOSIN PATHINFO FASTCGI PATHINFO

CLI_DESC=	Build CLI version
CGI_DESC=	Build CGI version
FPM_DESC=	Build FPM version (experimental)
APACHE_DESC=	Build Apache module
AP2FILTER_DESC=	Use Apache 2.x filter interface (experimental)
SUHOSIN_DESC=	Suhosin protection system
MULTIBYTE_DESC=	zend multibyte support
MAILHEAD_DESC=	mail header patch
LINKTHR_DESC=	Link thread lib (for threaded extensions)
REDIRECT_DESC=	force-cgi-redirect support (CGI only)
DISCARD_DESC=	discard-path support (CGI only)
FASTCGI_DESC=	fastcgi support (CGI only)
FPM_DESC=	fastcgi process manager (CGI only)
PATHINFO_DESC=	path-info-check support (CGI only)

CONFLICTS=	php53-5* php5-5*

MAN1=		php-config.1 phpize.1

.include <bsd.port.pre.mk>

PATCH_DIST_STRIP=	-p1

.if ${PORT_OPTIONS:MFPM} && ${PORT_OPTIONS:MCGI}
. if ! ${PORT_OPTIONS:MFASTCGI}
IGNORE=		FPM requires FastCGI support
. endif
PATCHFILES+=	php-5.2.14-fpm-0.5.14-freebsd.patch.gz
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

.if ${PORT_OPTIONS:MSUHOSIN}
PATCHFILES+=	suhosin-patch-5.2.16-0.9.7.patch.gz:suhosin
PATCH_SITES+=	http://download.suhosin.org/:suhosin
PLIST_SUB+=	SUHOSIN=""
.else
PLIST_SUB+=	SUHOSIN="@comment "
.endif

.if ${PORT_OPTIONS:MMAILHEAD}
#PATCHFILES+=	php-${PORTVERSION}-mail-header.patch:mail
PATCHFILES+=	php-5.2.10-mail-header.patch:mail
PATCH_SITES+=	http://choon.net/opensource/php/:mail
.endif

.if ${PORT_OPTIONS:MCLI}
PHP_SAPI+=	cli
PLIST_SUB+=	CLI=""
MAN1+=		php.1
.else
PLIST_SUB+=	CLI="@comment "
CONFIGURE_ARGS+=--disable-cli
.endif

.if ${PORT_OPTIONS:MCGI}
PHP_SAPI+=	cgi
PLIST_SUB+=	CGI=""
.if ${PORT_OPTIONS:MREDIRECT}
CONFIGURE_ARGS+=--enable-force-cgi-redirect
.endif
.if ${PORT_OPTIONS:MDISCARD}
CONFIGURE_ARGS+=--enable-discard-path
.endif
.if ${PORT_OPTIONS:MFASTCGI}
CONFIGURE_ARGS+=--enable-fastcgi
.endif
.if ! ${PORT_OPTIONS:MPATHINFO}
CONFIGURE_ARGS+=--disable-path-info-check
.endif
.else
PLIST_SUB+=	CGI="@comment "
CONFIGURE_ARGS+=--disable-cgi
.endif

.if ${PORT_OPTIONS:MAPACHE}
PHP_SAPI+=	mod
USE_APACHE=	22+
.include "${PORTSDIR}/Mk/bsd.apache.mk"
CONFIGURE_ARGS+=--with-apxs2=${APXS}
PKGMESSAGE=	${PKGDIR}/pkg-message.mod
MODULENAME=	libphp5
SHORTMODNAME=	php5
PLIST_SUB+=	APACHE=""
.else
PLIST_SUB+=	APACHE="@comment "
.endif

.if ! ${PORT_OPTIONS:MREGEX_TYPE} || ${WITH_REGEX_TYPE} == "php"
CONFIGURE_ARGS+=--with-regex=php
.elif ${PORT_OPTIONS:MREGEX_TYPE} && ${WITH_REGEX_TYPE} == "system"
CONFIGURE_ARGS+=--with-regex=system
.elif ${PORT_OPTIONS:MREGEX_TYPE} && ${WITH_REGEX_TYPE} == "apache"
CONFIGURE_ARGS+=--with-regex=apache
.endif

.if ! ${PORT_OPTIONS:MZEND_VM} || ${WITH_ZEND_VM} == "CALL"
CONFIGURE_ARGS+=--with-zend-vm=CALL
.elif ${PORT_OPTIONS:MZEND_VM} && ${WITH_ZEND_VM} == "SWITCH"
CONFIGURE_ARGS+=--with-zend-vm=SWITCH
.elif ${PORT_OPTIONS:MZEND_VM} && ${WITH_ZEND_VM} == "GOTO"
CONFIGURE_ARGS+=--with-zend-vm=GOTO
.endif

CONFIGURE_ENV+=	ac_cv_pthreads_lib="" \
		ac_cv_pthreads_cflags="" \
		pthreads_working="yes" \
		lt_cv_path_SED="sed"

.if ${PORT_OPTIONS:MLINKTHR}
CONFIGURE_ENV+=	LIBS="${LIBS} ${PTHREAD_LIBS}"
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MMULTIBYTE}
CONFIGURE_ARGS+=--enable-zend-multibyte
.endif

.if ! ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--disable-ipv6
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/ext/php_config.h
	@${REINPLACE_CMD} "s|^\(extension_dir\)|; \1|" ${WRKSRC}/php.ini-*
.if ${PORT_OPTIONS:MFPM} && ${PORT_OPTIONS:MCGI}
	@${REINPLACE_CMD} -e 's,BUILD_CGI=\"\\$$\(.*\)\\$$(EXTRA_LIBS),BUILD_CGI=\"\\$$\1\\$$(EXTRA_LIBS) \\$$(SAPI_EXTRA_LIBS),g' \
		${WRKSRC}/sapi/cgi/config9.m4
.endif

# Work around issues with newer (>=2.64) autoconf
pre-configure:
	@${REINPLACE_CMD} -E 's:^((m4_)?divert)[(]([0-9]*)[)]:\1(600\3):' \
		${WRKSRC}/configure.in `${FIND} ${WRKSRC} -name '*.m4'`
	@${RM} ${WRKSRC}/configure
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
.if ${PORT_OPTIONS:MFPM} && ${PORT_OPTIONS:MCGI}
	@${INSTALL_DATA} ${WRKDIR}/php-fpm.conf.sample ${PREFIX}/etc
	@${MKDIR} `dirname ${PHP_FPM_PID}`
	@${MKDIR} `dirname ${PHP_FPM_LOG}`
	@cd ${PREFIX}/etc && ${CP} -n php-fpm.conf.sample php-fpm.conf || ${TRUE}
.endif
.if ${PORT_OPTIONS:MAPACHE}
	@${CAT} ${PKGMESSAGE}
.endif

.else
.include "${MASTERDIR}/Makefile.ext"
.endif
.include <bsd.port.post.mk>
