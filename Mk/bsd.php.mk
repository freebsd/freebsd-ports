#
# bsd.php.mk - Support for PHP-based ports.
#
# Created by: Alex Dupre <ale@FreeBSD.org>
#
# For FreeBSD committers:
# Please send all suggested changes to the maintainer instead of committing
# them to CVS yourself.
#
# $FreeBSD$
#
# Adding 'USE_PHP=yes' to a port includes this Makefile after bsd.ports.pre.mk.
#
# The port can set these options in its Makefile before bsd.ports.pre.mk:
#
# USE_PHPIZE=yes    - Use to build a PHP extension.
# WANT_PHP_CLI=yes  - Want the CLI version of PHP.
# WANT_PHP_CGI=yes  - Want the CGI version of PHP.
# WANT_PHP_MOD=yes  - Want the Apache Module for PHP.
# WANT_PHP_WEB=yes  - Want the Apache Module or the CGI version of PHP.
# WANT_PHP_PEAR=yes - Want the PEAR framework.
#
# You may combine multiple WANT_PHP_* knobs.
# Don't specify any WANT_PHP_* knob if your port will work with every PHP SAPI.
#

PHP_Include_MAINTAINER=	ale@FreeBSD.org

.if exists(${LOCALBASE}/etc/php.conf)
.include "${LOCALBASE}/etc/php.conf"
.endif

PHP_VER?=	4
.if !defined(PHP_EXT_DIR)
PHP_EXT_DIR=	20020429
.if exists(${LOCALBASE}/include/apache2/httpd.h)
APACHE_MPM!=	${APXS} -q MPM_NAME
.if ${APACHE_MPM} == "worker"
PHP_EXT_DIR:=	${PHP_EXT_DIR}-zts
.endif
.else
.if defined(WITH_APACHE2) && defined(WITH_MPM) && ${WITH_MPM} == "worker"
PHP_EXT_DIR:=	${PHP_EXT_DIR}-zts
.endif
.endif
.if defined(WITH_DEBUG)
PHP_EXT_DIR:=	${PHP_EXT_DIR}-debug
.endif
.endif
.if !defined(WITHOUT_PEAR)
PHP_PEAR?=	yes
.else
PHP_PEAR?=	no
.endif
PHP_SAPI?=	""

.if defined(BROKEN_WITH_PHP)
.       for VER in ${BROKEN_WITH_PHP}
.               if ${PHP_VER} == "${VER}"
BROKEN=         "Doesn't work with PHP version : ${PHP_VER} (Doesn't support PHP ${BROKEN_WITH_PHP})"
.               endif
.       endfor
.endif

.if defined(WANT_PHP_WEB)
.	if defined(WANT_PHP_CGI) || defined(WANT_PHP_MOD)
check-makevars::
		@${ECHO_CMD} "If you define WANT_PHP_WEB you cannot set also WANT_PHP_CGI"
		@${ECHO_CMD} "or WANT_PHP_MOD. Use only one of them."
		@${FALSE}
.	else
.	if defined(PHP_VERSION) && ${PHP_SAPI} == "cli"
check-makevars::
		@${ECHO_CMD} "This port requires the Apache Module or the CGI version of PHP, but you have"
		@${ECHO_CMD} "already installed a conflicting PHP port without them."
		@${FALSE}
.	else
.	if defined(WANT_PHP_CLI) || defined(WANT_PHP_PEAR)
PHP_PORT?=	${PORTSDIR}/lang/php${PHP_VER}
.	else
PHP_PORT?=	${PORTSDIR}/www/mod_php${PHP_VER}
PHP_PEAR?=	no
.	endif
.	endif
.	endif
.else

.if defined(WANT_PHP_CGI)
.	if defined(WANT_PHP_CLI) || defined(WANT_PHP_MOD)
check-makevars::
		@${ECHO_CMD} "The CGI version of PHP avoids the installation of other SAPIs."
		@${ECHO_CMD} "Do not use WANT_PHP_CGI with other WANT_PHP_* knobs."
		@${FALSE}
.	else
.	if defined(PHP_VERSION) && ${PHP_SAPI} != "cgi"
check-makevars::
		@${ECHO_CMD} "This port requires the CGI version of PHP, but you have already"
		@${ECHO_CMD} "installed a conflicting PHP port without CGI."
		@${FALSE}
.	else
PHP_PORT?=	${PORTSDIR}/www/php${PHP_VER}-cgi
PHP_PEAR?=	no
.	endif
.	endif
.else

.if defined(WANT_PHP_CLI) && !defined(WANT_PHP_MOD)
.	if defined(PHP_VERSION) && ${PHP_SAPI} != "full" && ${PHP_SAPI} != "cli"
check-makevars::
		@${ECHO_CMD} "This port requires the CLI version of PHP, but you have already"
		@${ECHO_CMD} "installed a conflicting PHP port without CLI."
		@${FALSE}
.	else
PHP_PORT?=	${PORTSDIR}/lang/php${PHP_VER}-cli
.	endif
.else

.if !defined(WANT_PHP_CLI) && defined(WANT_PHP_MOD)
.	if defined(PHP_VERSION) && (${PHP_SAPI} != "full" && ${PHP_SAPI} != "mod")
check-makevars::
		@${ECHO_CMD} "This port requires the Apache Module for PHP, but you have already"
		@${ECHO_CMD} "installed a conflicting PHP port without the Apache Module."
		@${FALSE}
.	else
.	if defined(WANT_PHP_PEAR)
PHP_PORT?=	${PORTSDIR}/lang/php${PHP_VER}
.	else
PHP_PORT?=	${PORTSDIR}/www/mod_php${PHP_VER}
PHP_PEAR?=	no
.	endif
.	endif
.else

PHP_PORT?=	${PORTSDIR}/lang/php${PHP_VER}

.endif

.endif

.endif

.endif

.if defined(WANT_PHP_PEAR) && ${PHP_PEAR} == "no"
BROKEN=	"This port requires the PEAR framework, but you have already" \
	"installed a PHP port without PEAR"
.endif

RUN_DEPENDS+=	${LOCALBASE}/include/php/main/php.h:${PHP_PORT}

PLIST_SUB+=	PHP_EXT_DIR=${PHP_EXT_DIR}

.if defined(USE_PHPIZE)
BUILD_DEPENDS+=	phpize:${PHP_PORT}
USE_LIBTOOL=	yes
WANT_AUTOMAKE_VER=	15
WANT_AUTOCONF_VER=	253
CONFIGURE_ARGS+=--with-php-config=${LOCALBASE}/bin/php-config

configure-message: phpize

phpize:
	@${ECHO_MSG} "===>  PHPizing for ${DISTNAME}"
	@(cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ${LOCALBASE}/bin/phpize)
.endif
