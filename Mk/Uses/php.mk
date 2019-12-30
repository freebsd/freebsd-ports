# $FreeBSD$
#
# Support for PHP-based ports.
#
# Feature:	php
# Usage:	USES=php
# Valid ARGS:	(none), phpize, ext, zend, build, cli, cgi, mod, web, embed,
#		pecl, flavors, noflavors
#
#	- phpize   : Use to build a PHP extension.
#	- ext      : Use to build, install and register a PHP extension.
#	- zend     : Use to build, install and register a Zend extension.
#	- build    : Set PHP also as a build dependency.
#	- cli      : Want the CLI version of PHP.
#	- cgi      : Want the CGI version of PHP.
#	- mod      : Want the Apache Module for PHP.
#	- web      : Want the Apache Module or the CGI version of PHP.
#	- embed    : Want the embedded library version of PHP.
#	- pecl     : Fetches from PECL.
#	- flavors  : Generates flavors for supported versions.
#		     (implied by phpize,ext,zend,pecl)
#	- noflavors: Prevents generation of flavor.
#
# If the port requires a predefined set of PHP extensions, they can be
# listed in this way:
#
# USE_PHP=	ext1 ext2 ext3
#
# PHP and Zend extensions built with :ext and :zend are automatically enabled
# when the port is installed.  Each port creates a PHP_EXT_INI_FILE file and
# registers the extension in it.
#
# The PHP_EXT_INI_FILE file has a priority number embeded into its name so that
# extensions are loaded in the right order.  The priority is defined by
# PHP_MOD_PRIO and is a number between 00 and 99.
#
# For extensions that do not depend on any extension, the priority is
# automatically set to 20, for extensions that depend on another extension, the
# priority is automatically set to 30.  Some extensions may need to be loaded
# before everyone else (for example opcache), or after an extension with a
# priotity of 30, in that case, add PHP_MOD_PRIO=XX in the port's Makefile.
# For example:
#
# USES=		php:ext
# USE_PHP=	xml wddx
# PHP_MOD_PRIO=	40
#
# The port can set these options in its Makefile before bsd.port.pre.mk:
#
# IGNORE_WITH_PHP=N - The port doesn't work with PHP version N.
#
# You may combine multiple php:* arguments.
# Don't specify any php:* argument if your port will work with every PHP SAPI.
#
# If you are building PHP-based ports in poudriere(8) with ZTS enabled,
# add WITH_MPM=event to /etc/make.conf to prevent build failures.

.if !defined(_INCLUDE_USES_PHP_MK)

PHP_Include_MAINTAINER=	ale@FreeBSD.org

_INCLUDE_USES_PHP_MK=	yes

_PHP_VALID_ARGS=	build cgi cli embed ext flavors mod noflavors pecl \
			phpize web zend
_PHP_UNKNOWN_ARGS=
.for arg in ${php_ARGS}
.  if empty(_PHP_VALID_ARGS:M${arg})
_PHP_UNKNOWN_ARGS+=	${arg}
.  endif
.endfor
.if !empty(_PHP_UNKNOWN_ARGS)
IGNORE=	has unknown USES=php arguments: ${_PHP_UNKNOWN_ARGS}
.endif

.  if ${php_ARGS:Mbuild} && ( ${php_ARGS:Mphpize} || ${php_ARGS:Mext} || ${php_ARGS:Mzend} )
DEV_WARNING+=	"USES=php:build is included in USES=php:phpize, USES=php:ext, and USES=php:zend, so it is not needed"
.  endif
.  if ${php_ARGS:Mflavors} && ( ${php_ARGS:Mphpize} || ${php_ARGS:Mext} || ${php_ARGS:Mzend} || ${php_ARGS:Mpecl} )
DEV_WARNING+=	"USES=php:flavors is included in phpize, ext, zend and pecl, so it is not needed."
.  endif
.  if ${php_ARGS:Mphpize} && ( ${php_ARGS:Mext} || ${php_ARGS:Mzend} )
DEV_WARNING+=	"USES=php:phpize is included in USES=php:ext and USES=php:zend, so it is not needed"
.  endif
.  if ${php_ARGS:Mext} && ${php_ARGS:Mzend}
DEV_WARNING+=	"USES=php:ext is included in USES=php:zend, so it is not needed"
.  endif
.  if ${php_ARGS:Mext} && ${php_ARGS:Mpecl}
DEV_WARNING+=	"USES=php:ext is included in USES=php:pecl, so it is not needed"
.  endif

.  if ( ${php_ARGS:Mphpize} || ${php_ARGS:Mext} || ${php_ARGS:Mzend} || ${php_ARGS:Mpecl} ) && !${php_ARGS:Mnoflavors}
php_ARGS+=	flavors
.  endif

.  if ${php_ARGS:Mnoflavors} && ${php_ARGS:Mflavors}
php_ARGS:=	${php_ARGS:Nflavors}
.  endif

.  if ${php_ARGS:Mpecl}
php_ARGS+=	ext
.    if !defined(USE_GITHUB)
EXTRACT_SUFX=	.tgz
MASTER_SITES=	https://pecl.php.net/get/ \
		http://pecl.php.net/get/
.    endif
PKGNAMEPREFIX=	${PECL_PKGNAMEPREFIX}
DIST_SUBDIR=	PECL
.  endif

PHPBASE?=	${LOCALBASE}

_ALL_PHP_VERSIONS=	72 73 74

# Make the already installed PHP the default one.
.  if exists(${PHPBASE}/etc/php.conf)
.include "${PHPBASE}/etc/php.conf"
.    if !defined(PHP_EXT_DIR)
PHP_EXT_DIR!=	${PHPBASE}/bin/php-config --extension-dir | ${SED} -ne 's,^${PHPBASE}/lib/php/\(.*\),\1,p'
.    endif
_INSTALLED_PHP_VER:=	${PHP_VER}
# If we have an installed version of PHP, and this does not support it, set
# IGNORE to fail early as you cannot install two different versions of PHP at
# the same time anyway.
.    if defined(IGNORE_WITH_PHP) && ${IGNORE_WITH_PHP:M${_INSTALLED_PHP_VER}}
IGNORE=	does not work with PHP versions "${IGNORE_WITH_PHP}" and "${_INSTALLED_PHP_VER}" is installed.
.    endif

.  else
PHP_VER?=	${PHP_DEFAULT:S/.//}
.  endif # .if exists(${PHPBASE}/etc/php.conf)

# Use the "default" php version as the first version for flavors, so that it
# gets to be the default flavor.
_ALL_FLAVOR_VERSIONS=	${PHP_VER} ${_ALL_PHP_VERSIONS:N${PHP_VER}}

# If we want flavors, fill in FLAVORS with the allowed PHP versions, if some
# cannot be used, or all of them if they all can.
# Then if there is no flavor set, use the first one as the default.
.  if ${php_ARGS:Mflavors}
.    if empty(FLAVORS)
.      if defined(IGNORE_WITH_PHP)
.        for _v in ${_ALL_FLAVOR_VERSIONS}
.          if empty(IGNORE_WITH_PHP:M${_v})
# Avoid a leading space in FLAVORS.
.            if empty(FLAVORS)
FLAVORS:=	php${_v}
.            else
FLAVORS:=	${FLAVORS} php${_v}
.            endif
.          endif
.        endfor
.      else # defined(IGNORE_WITH_PHP)
FLAVORS:=	${_ALL_FLAVOR_VERSIONS:S/^/php/}
.      endif # defined(IGNORE_WITH_PHP)
.    endif
.    if empty(FLAVOR)
FLAVOR=	${FLAVORS:[1]}
.    endif
.  endif

.if ${PHP_VER} == 74 && (${ARCH:Mmips*} || (${ARCH:Mpowerpc*} && !exists(/usr/bin/clang)) || ${ARCH} == sparc64)
USE_GCC=	yes
.endif

# This variable is for dependencies lines, so you write:
# ${PHP_PKGNAMEPREFIX}foo:devel/php-foo@${PHP_FLAVOR}
PHP_FLAVOR=	php${PHP_VER}

# So, we have PHP flavors, set PHP_VER accordingly.
.  if ${FLAVOR:Mphp[0-9][0-9]}
PHP_VER=	${FLAVOR:S/^php//}
.  endif

# If lang/php is not installed, or if we have a php flavor but want a non
# default one, we need to overwrite those.
.  if empty(PHP_EXT_DIR) || empty(PHP_EXT_INC) || \
	(${FLAVOR:Mphp[0-9][0-9]} && ${FLAVOR} != ${FLAVORS:[1]})
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
.    if ${PHP_VER} == 74
PHP_EXT_DIR=   20190902
PHP_EXT_INC=    hash pcre spl
.    elif ${PHP_VER} == 73
PHP_EXT_DIR=   20180731
PHP_EXT_INC=    pcre spl
.    elif ${PHP_VER} == 72
PHP_EXT_DIR=   20170718
PHP_EXT_INC=    pcre spl
.    else
# (rene) default to DEFAULT_VERSIONS
PHP_EXT_DIR=	20170718
PHP_EXT_INC=	pcre spl
.    endif

# Try to figure out what the PHP_EXT_DIR should be WRT the
# installed Apache port.
HTTPD?=		${LOCALBASE}/sbin/httpd
.    if exists(${HTTPD})
APACHE_THR!=	${HTTPD} -V | ${AWK} '/threaded/ {print $2}'
.      if ${APACHE_THR:Myes}
PHP_EXT_DIR:=	${PHP_EXT_DIR}-zts
.      endif
.    elif defined(APACHE_PORT) && (${APACHE_PORT:M*worker*} != "" || ${APACHE_PORT:M*event*} != "")
PHP_EXT_DIR:=	${PHP_EXT_DIR}-zts
.    elif defined(WITH_MPM) && (${WITH_MPM} == "worker" || ${WITH_MPM} == "event")
PHP_EXT_DIR:=	${PHP_EXT_DIR}-zts
.    endif

.    if defined(WITH_DEBUG)
PHP_EXT_DIR:=	${PHP_EXT_DIR}-debug
.    endif
PHP_SAPI?=	""
.  endif # empty(PHP_EXT_DIR) || empty(PHP_EXT_INC) || (${FLAVOR:Mphp[0-9][0-9]} && ${FLAVOR} != ${FLAVORS:[1]})

# Set a few PKGNAME(PRE|SUF)FIX to be used in ports.
PHP_PKGNAMEPREFIX=	php${PHP_VER}-
PHP_PKGNAMESUFFIX=	-php${PHP_VER}
PECL_PKGNAMEPREFIX=	php${PHP_VER}-pecl-

.  if defined(IGNORE_WITH_PHP)
.    for VER in ${IGNORE_WITH_PHP}
.      if ${PHP_VER} == "${VER}"
_IGNORE_PHP_SET=
IGNORE=		cannot be installed: doesn't work with lang/php${PHP_VER} port\
		(doesn't support PHP ${IGNORE_WITH_PHP:C/^(7)/\1./})
.      endif
.    endfor
.  endif

.  if ${php_ARGS:Mweb}
.    if ${php_ARGS:Mcgi} || ${php_ARGS:Mmod}
check-makevars::
		@${ECHO_CMD} "If you use :web you cannot also use :cgi"
		@${ECHO_CMD} "or :mod. Use only one of them."
		@${FALSE}
.    endif
.  endif

.  if ${php_ARGS:Mcgi}
.    if defined(PHP_VERSION) && ${PHP_SAPI:Mcgi} == "" && ${PHP_SAPI:Mfpm} == ""
check-makevars::
		@${ECHO_CMD} "This port requires the CGI version of PHP, but you have already"
		@${ECHO_CMD} "installed a PHP port without CGI."
		@${FALSE}
.    endif
.  endif

.  if ${php_ARGS:Mcli}
.    if defined(PHP_VERSION) && ${PHP_SAPI:Mcli} == ""
check-makevars::
		@${ECHO_CMD} "This port requires the CLI version of PHP, but you have already"
		@${ECHO_CMD} "installed a PHP port without CLI."
		@${FALSE}
.    endif
.  endif

.  if ${php_ARGS:Membed}
.    if defined(PHP_VERSION) && ${PHP_SAPI:Membed} == ""
check-makevars::
		@${ECHO_CMD} "This port requires the embedded library version of PHP, but you have already"
		@${ECHO_CMD} "installed a PHP port without the embedded library."
		@${FALSE}
.    endif
.  endif

PHP_PORT?=	lang/php${PHP_VER}
MOD_PHP_PORT?=	www/mod_php${PHP_VER}

.  if ${php_ARGS:Mbuild}
BUILD_DEPENDS+=	${PHPBASE}/include/php/main/php.h:${PHP_PORT}
.  endif
RUN_DEPENDS+=	${PHPBASE}/include/php/main/php.h:${PHP_PORT}
.  if  ${php_ARGS:Mmod} || (${php_ARGS:Mweb} && defined(PHP_VERSION) && ${PHP_SAPI:Mcgi} == "" && ${PHP_SAPI:Mfpm} == "")
USE_APACHE_RUN=	22+
.include "${PORTSDIR}/Mk/Uses/apache.mk"
# libphpX.so only has the major version number in it, so remove the last digit of PHP_VER to get it.
RUN_DEPENDS+=	${PHPBASE}/${APACHEMODDIR}/libphp${PHP_VER:C/.$//}.so:${MOD_PHP_PORT}
.  endif

PLIST_SUB+=	PHP_EXT_DIR=${PHP_EXT_DIR}
SUB_LIST+=	PHP_EXT_DIR=${PHP_EXT_DIR}

.  if ${php_ARGS:Mphpize} || ${php_ARGS:Mext} || ${php_ARGS:Mzend}
BUILD_DEPENDS+=	${PHPBASE}/bin/phpize:${PHP_PORT} \
		autoconf>0:devel/autoconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-php-config=${PHPBASE}/bin/php-config

_USES_configure+=	190:phpize-message 250:do-phpize

phpize-message:
	@${ECHO_MSG} "===>  PHPizing for ${PKGNAME}"

do-phpize:
	@(cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ${PHPBASE}/bin/phpize)
.  endif

_USES_POST+=php
.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_PHP_POST_MK)

_INCLUDE_USES_PHP_POST_MK=yes

.  if ${php_ARGS:Mext} || ${php_ARGS:Mzend}
PHP_MODNAME?=	${PORTNAME}
PHP_EXT_PKGMESSAGE=	${WRKDIR}/php-ext-pkg-message
_PKGMESSAGES+=	${PHP_EXT_PKGMESSAGE}
PHP_HEADER_DIRS+=	.
# If there is no priority defined, we wing it.
.    if !defined(PHP_MOD_PRIO)
.      if defined(USE_PHP)
# If an extension needs another, put it after the others.
PHP_MOD_PRIO=	30
.      else
# Otherwise, put it where it with everybody.
PHP_MOD_PRIO=	20
.      endif
.    endif
PHP_EXT_INI_FILE=	etc/php/ext-${PHP_MOD_PRIO}-${PHP_MODNAME}.ini

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_LIB} ${WRKSRC}/modules/${PHP_MODNAME}.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
.    for header in ${PHP_HEADER_DIRS}
		@${MKDIR} ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/${header}
		@${INSTALL_DATA} ${WRKSRC}/${header}/*.h \
			${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/${header}
.    endfor
	@${RM} ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/config.h
	@${EGREP} "#define (COMPILE|HAVE|USE)_" ${WRKSRC}/config.h \
		> ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/config.h
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/php
.    if ${php_ARGS:Mzend}
	@${ECHO_CMD} "zend_extension=${PHP_MODNAME}.so" > ${STAGEDIR}${PREFIX}/${PHP_EXT_INI_FILE}
.    else
	@${ECHO_CMD} "extension=${PHP_MODNAME}.so" > ${STAGEDIR}${PREFIX}/${PHP_EXT_INI_FILE}
.    endif

_USES_stage+=	899:add-plist-phpext
add-plist-phpext:
	@${ECHO_CMD} "lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so" \
		>> ${TMPPLIST}
	@${FIND} -P ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME} ! -type d 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec echo \#include \\\"ext/${PHP_MODNAME}/config.h\\\" >> %D/include/php/ext/php_config.h" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@preunexec cp %D/include/php/ext/php_config.h %D/include/php/ext/php_config.h.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@preunexec grep -v ext/${PHP_MODNAME}/config.h %D/include/php/ext/php_config.h.orig > %D/include/php/ext/php_config.h || true" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@preunexec ${RM} %D/include/php/ext/php_config.h.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "${PHP_EXT_INI_FILE}" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "[" > ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "{" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "  message: <<EOD" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "This file has been added to automatically load the installed extension:" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "${PREFIX}/${PHP_EXT_INI_FILE}" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "EOD" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "  type: install" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "}" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "]" >> ${PHP_EXT_PKGMESSAGE}
.  endif

# Extensions
.  if defined(USE_PHP) && ${USE_PHP:tl} != "yes"
# non-version specific components
_USE_PHP_ALL=	bcmath bitset bz2 calendar ctype curl dba dom \
		enchant exif fileinfo filter ftp gd gettext gmp \
		hash iconv igbinary imap intl json ldap mbstring mcrypt \
		memcache memcached mysqli odbc opcache \
		openssl pcntl pcre pdf pdo pdo_dblib pdo_firebird pdo_mysql \
		pdo_odbc pdo_pgsql pdo_sqlite phar pgsql posix \
		pspell radius readline redis session shmop simplexml snmp soap\
		sockets spl sqlite3 sysvmsg sysvsem sysvshm \
		tidy tokenizer xml xmlreader xmlrpc xmlwriter xsl zip zlib
# version specific components
_USE_PHP_VER72=	${_USE_PHP_ALL} interbase recode sodium wddx
_USE_PHP_VER73=	${_USE_PHP_ALL} interbase recode sodium wddx
_USE_PHP_VER74=	${_USE_PHP_ALL} ffi sodium

bcmath_DEPENDS=	math/php${PHP_VER}-bcmath
bitset_DEPENDS=	math/pecl-bitset@${PHP_FLAVOR}
bz2_DEPENDS=	archivers/php${PHP_VER}-bz2
calendar_DEPENDS=	misc/php${PHP_VER}-calendar
ctype_DEPENDS=	textproc/php${PHP_VER}-ctype
curl_DEPENDS=	ftp/php${PHP_VER}-curl
dba_DEPENDS=	databases/php${PHP_VER}-dba
dbase_DEPENDS=	databases/php${PHP_VER}-dbase
dom_DEPENDS=	textproc/php${PHP_VER}-dom
enchant_DEPENDS=	textproc/php${PHP_VER}-enchant
exif_DEPENDS=	graphics/php${PHP_VER}-exif
ffi_DEPENDS=	devel/php${PHP_VER}-ffi
fileinfo_DEPENDS=	sysutils/php${PHP_VER}-fileinfo
filter_DEPENDS=	security/php${PHP_VER}-filter
ftp_DEPENDS=	ftp/php${PHP_VER}-ftp
gd_DEPENDS=	graphics/php${PHP_VER}-gd
gettext_DEPENDS=devel/php${PHP_VER}-gettext
gmp_DEPENDS=	math/php${PHP_VER}-gmp
hash_DEPENDS=	security/php${PHP_VER}-hash
iconv_DEPENDS=	converters/php${PHP_VER}-iconv
igbinary_DEPENDS=	converters/pecl-igbinary@${PHP_FLAVOR}
imap_DEPENDS=	mail/php${PHP_VER}-imap
interbase_DEPENDS=	databases/php${PHP_VER}-interbase
intl_DEPENDS=	devel/php${PHP_VER}-intl
json_DEPENDS=	devel/php${PHP_VER}-json
ldap_DEPENDS=	net/php${PHP_VER}-ldap
mbstring_DEPENDS=	converters/php${PHP_VER}-mbstring
mcrypt_DEPENDS=	security/pecl-mcrypt@${PHP_FLAVOR}
memcache_DEPENDS=	databases/pecl-memcache@${PHP_FLAVOR}
memcached_DEPENDS=	databases/pecl-memcached@${PHP_FLAVOR}
mssql_DEPENDS=	databases/php${PHP_VER}-mssql
mysqli_DEPENDS=	databases/php${PHP_VER}-mysqli
odbc_DEPENDS=	databases/php${PHP_VER}-odbc
opcache_DEPENDS=	www/php${PHP_VER}-opcache
openssl_DEPENDS=security/php${PHP_VER}-openssl
pcntl_DEPENDS=	devel/php${PHP_VER}-pcntl
pdf_DEPENDS=	print/pecl-pdflib@${PHP_FLAVOR}
pdo_DEPENDS=	databases/php${PHP_VER}-pdo
pdo_dblib_DEPENDS=	databases/php${PHP_VER}-pdo_dblib
pdo_firebird_DEPENDS=	databases/php${PHP_VER}-pdo_firebird
pdo_mysql_DEPENDS=	databases/php${PHP_VER}-pdo_mysql
pdo_odbc_DEPENDS=	databases/php${PHP_VER}-pdo_odbc
pdo_pgsql_DEPENDS=	databases/php${PHP_VER}-pdo_pgsql
pdo_sqlite_DEPENDS=	databases/php${PHP_VER}-pdo_sqlite
pgsql_DEPENDS=	databases/php${PHP_VER}-pgsql
phar_DEPENDS=	archivers/php${PHP_VER}-phar
posix_DEPENDS=	sysutils/php${PHP_VER}-posix
pspell_DEPENDS=	textproc/php${PHP_VER}-pspell
radius_DEPENDS=	net/pecl-radius@${PHP_FLAVOR}
readline_DEPENDS=	devel/php${PHP_VER}-readline
recode_DEPENDS=	converters/php${PHP_VER}-recode
redis_DEPENDS=	databases/pecl-redis@${PHP_FLAVOR}
session_DEPENDS=www/php${PHP_VER}-session
shmop_DEPENDS=	devel/php${PHP_VER}-shmop
simplexml_DEPENDS=	textproc/php${PHP_VER}-simplexml
snmp_DEPENDS=	net-mgmt/php${PHP_VER}-snmp
soap_DEPENDS=	net/php${PHP_VER}-soap
sockets_DEPENDS=net/php${PHP_VER}-sockets
sodium_DEPENDS=	security/php${PHP_VER}-sodium
sqlite3_DEPENDS=databases/php${PHP_VER}-sqlite3
sybase_ct_DEPENDS=	databases/php${PHP_VER}-sybase_ct
sysvmsg_DEPENDS=devel/php${PHP_VER}-sysvmsg
sysvsem_DEPENDS=devel/php${PHP_VER}-sysvsem
sysvshm_DEPENDS=devel/php${PHP_VER}-sysvshm
tidy_DEPENDS=	www/php${PHP_VER}-tidy
tokenizer_DEPENDS=	devel/php${PHP_VER}-tokenizer
wddx_DEPENDS=	textproc/php${PHP_VER}-wddx
xml_DEPENDS=	textproc/php${PHP_VER}-xml
xmlreader_DEPENDS=	textproc/php${PHP_VER}-xmlreader
xmlrpc_DEPENDS=	net/php${PHP_VER}-xmlrpc
xmlwriter_DEPENDS=	textproc/php${PHP_VER}-xmlwriter
xsl_DEPENDS=	textproc/php${PHP_VER}-xsl
zip_DEPENDS=	archivers/php${PHP_VER}-zip
zlib_DEPENDS=	archivers/php${PHP_VER}-zlib

.    for extension in ${USE_PHP}
ext=		${extension}
.      if !empty(_USE_PHP_VER${PHP_VER}:M${extension:S/:build//})
.        if empty(PHP_EXT_INC:M${extension:S/:build//})
.          if !empty(php_ARGS:Mbuild) || !empty(ext:M*\:build)
BUILD_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/${extension:S/:build//}.so:${${extension:S/:build//}_DEPENDS}
.          endif
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/${extension:S/:build//}.so:${${extension:S/:build//}_DEPENDS}
.        endif
.      else
.        if ${ext:tl} != "yes" && !defined(_IGNORE_PHP_SET)
check-makevars::
			@${ECHO_CMD} "Unknown extension ${extension:S/:build//} for PHP ${PHP_VER}."
			@${FALSE}
.        endif
.      endif
.    endfor
.  endif
.endif
