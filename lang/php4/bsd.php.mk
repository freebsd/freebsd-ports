# Just include this makefile after bsd.ports.pre.mk
#
# The user/port can now set this options in the makefiles.
#
# USE_PHPIZE=yes   - Use to build a php extension.
# WANT_PHP_CLI=yes - Want the CLI version of PHP.
# WANT_PHP_CGI=yes - Want the CGI version of PHP.
# WANT_PHP_MOD=yes - Want the Apache Module for PHP.
# WANT_PHP_WEB=yes - Want the Apache Module or the CGI version of PHP.
#
# You may combine multiple WANT_PHP_* knobs.
# Don't specify any WANT_PHP_* knob if your port will work with every PHP SAPI.
#

.if exists(${LOCALBASE}/bin/php) && exists(${LOCALBASE}/bin/pear)
HAVE_PHP_CLI=	yes
HAVE_PHP=	yes
PHP_PORT=	${PORTSDIR}/lang/php4-cli
.endif
.if exists(${LOCALBASE}/bin/php) && !exists(${LOCALBASE}/bin/pear)
HAVE_PHP_CGI=	yes
HAVE_PHP=	yes
PHP_PORT=	${PORTSDIR}/www/php4-cgi
.endif
.if exists(${LOCALBASE}/libexec/apache/libphp4.so) || exists(${LOCALBASE}/libexec/apache2/libphp4.so)
HAVE_PHP_MOD=	yes
HAVE_PHP=	yes
PHP_PORT=	${PORTSDIR}/www/mod_php4
.endif
.if defined(HAVE_PHP_CLI) && defined(HAVE_PHP_MOD)
PHP_PORT=	${PORTSDIR}/lang/php4
.endif

.if defined(WANT_PHP_CGI) && (defined(WANT_PHP_CLI) || defined(WANT_PHP_MOD))
.BEGIN:
	@${ECHO_CMD} "The CGI version of PHP avoids the installation of other SAPIs."
	@${ECHO_CMD} "Do not use WANT_PHP_CGI with other WANT_PHP_* knobs."
	@${FALSE}
.endif

.if defined(WANT_PHP_CLI) && !defined(WANT_PHP_MOD)
.if defined(HAVE_PHP) && !defined(HAVE_PHP_CLI)
.BEGIN:
	@${ECHO_CMD} "This port requires the CLI version of PHP, but you have already"
	@${ECHO_CMD} "installed a conflicting PHP port without CLI."
	@${FALSE}
.else
PHP_PORT?=	${PORTSDIR}/lang/php4-cli
.endif
.endif

.if defined(WANT_PHP_WEB)
.if defined(HAVE_PHP) && !defined(HAVE_PHP_CGI) && !defined(HAVE_PHP_MOD)
.BEGIN:
        @${ECHO_CMD} "This port requires the Apache Module or the CGI version of PHP, but you have"
        @${ECHO_CMD} "already installed a conflicting PHP port without them."
        @${FALSE}
.else
PHP_PORT?=	${PORTSDIR}/www/mod_php4
.endif
.endif

.if defined(WANT_PHP_CGI)
.if defined(HAVE_PHP) && !defined(HAVE_PHP_CGI)
.BEGIN:
	@${ECHO_CMD} "This port requires the CGI version of PHP, but you have already"
	@${ECHO_CMD} "installed a conflicting PHP port without CGI."
	@${FALSE}
.else
PHP_PORT?=	${PORTSDIR}/www/php4-cgi
.endif
.endif

.if defined(WANT_PHP_MOD) && !defined(WANT_PHP_CLI)
.if defined(HAVE_PHP) && !defined(HAVE_PHP_MOD)
.BEGIN:
	@${ECHO_CMD} "This port requires the Apache Module for PHP, but you have already"
	@${ECHO_CMD} "installed a conflicting PHP port without the Apache Module."
	@${FALSE}
.else
PHP_PORT?=	${PORTSDIR}/www/mod_php4
.endif
.endif

PHP_PORT?=	${PORTSDIR}/lang/php4
RUN_DEPENDS+=	${LOCALBASE}/include/php/main/php.h:${PHP_PORT}

PHP_EXT_DIR?=	20020429
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
