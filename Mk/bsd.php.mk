#
# bsd.php.mk - Support for PHP-based ports.
#
# Created by: Alex Dupre <ale@FreeBSD.org>
#
# For FreeBSD committers:
# Please send all suggested changes to the maintainer instead of committing
# them to SVN yourself.
#
# $FreeBSD$
#
# Adding 'USE_PHP=yes' to a port includes this Makefile after bsd.ports.pre.mk.
# If the port requires a predefined set of PHP extensions, they can be
# listed in this way:
#
# USE_PHP=	ext1 ext2 ext3
#
# The port can set these options in its Makefile before bsd.port.pre.mk:
#
# DEFAULT_PHP_VER=N - Use PHP version N if PHP is not yet installed.
# IGNORE_WITH_PHP=N - The port doesn't work with PHP version N.
# USE_PHPIZE=yes    - Use to build a PHP extension.
# USE_PHPEXT=yes    - Use to build, install and register a PHP extension.
# USE_ZENDEXT=yes   - Use to build, install and register a Zend extension.
# USE_PHP_BUILD=yes - Set PHP also as a build dependency.
# WANT_PHP_CLI=yes  - Want the CLI version of PHP.
# WANT_PHP_CGI=yes  - Want the CGI version of PHP.
# WANT_PHP_MOD=yes  - Want the Apache Module for PHP.
# WANT_PHP_WEB=yes  - Want the Apache Module or the CGI version of PHP.
# WANT_PHP_EMB=yes  - Want the embedded library version of PHP.
#
# You may combine multiple WANT_PHP_* knobs.
# Don't specify any WANT_PHP_* knob if your port will work with every PHP SAPI.
#
# If you are building PHP-based ports in poudriere(8) with ZTS enabled,
# add WITH_MPM=event to /etc/make.conf to prevent build failures.

.if !defined(_PHPMKINCLUDED)

PHP_Include_MAINTAINER=	ale@FreeBSD.org

_PHPMKINCLUDED=	yes

.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

.if defined(DEFAULT_PHP_VER)
WARNING+=	"DEFAULT_PHP_VER is defined, consider using DEFAULT_VERSIONS=php=${DEFAULT_PHP_VER} instead"
.endif

PHPBASE?=	${LOCALBASE}
.if exists(${PHPBASE}/etc/php.conf)
.include "${PHPBASE}/etc/php.conf"
PHP_EXT_DIR!=	${PHPBASE}/bin/php-config --extension-dir | ${SED} -ne 's,^${PHPBASE}/lib/php/\(.*\),\1,p'

.else
DEFAULT_PHP_VER?=	${PHP_DEFAULT:S/.//}

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
PHP_VER?=	${DEFAULT_PHP_VER}
.if ${PHP_VER} == 70
PHP_EXT_DIR=   20151012
PHP_EXT_INC=    pcre spl
.elif ${PHP_VER} == 56
PHP_EXT_DIR=	20131226
PHP_EXT_INC=	pcre spl
.elif ${PHP_VER} == 55
PHP_EXT_DIR=	20121212
PHP_EXT_INC=	pcre spl
.else
# (rene) default to DEFAULT_VERSIONS
PHP_EXT_DIR=	20131226
PHP_EXT_INC=	pcre spl
.endif

HTTPD?=		${LOCALBASE}/sbin/httpd
.if exists(${HTTPD})
APACHE_THR!=	${HTTPD} -V | ${GREP} threaded
.	if ${APACHE_THR:Myes}
PHP_EXT_DIR:=	${PHP_EXT_DIR}-zts
.	endif
.elif defined(APACHE_PORT) && (${APACHE_PORT:M*worker*} != "" || ${APACHE_PORT:M*event*} != "")
PHP_EXT_DIR:=	${PHP_EXT_DIR}-zts
.elif defined(WITH_MPM) && (${WITH_MPM} == "worker" || ${WITH_MPM} == "event")
PHP_EXT_DIR:=	${PHP_EXT_DIR}-zts
.endif

.if defined(WITH_DEBUG)
PHP_EXT_DIR:=	${PHP_EXT_DIR}-debug
.endif
PHP_SAPI?=	""
.endif	# .if exists(${PHPBASE}/etc/php.conf)
PHP_EXT_INC?=	""

.if defined(IGNORE_WITH_PHP)
.	for VER in ${IGNORE_WITH_PHP}
.		if ${PHP_VER} == "${VER}"
IGNORE=		cannot be installed: doesn't work with lang/php${PHP_VER} port\
		(doesn't support PHP ${IGNORE_WITH_PHP:C/^5/5./})
.		endif
.	endfor
.endif

.if defined(WANT_PHP_WEB)
.	if defined(WANT_PHP_CGI) || defined(WANT_PHP_MOD)
check-makevars::
		@${ECHO_CMD} "If you define WANT_PHP_WEB you cannot set also WANT_PHP_CGI"
		@${ECHO_CMD} "or WANT_PHP_MOD. Use only one of them."
		@${FALSE}
.	endif
.endif

.if defined(WANT_PHP_CGI)
.	if defined(PHP_VERSION) && ${PHP_SAPI:Mcgi} == "" && ${PHP_SAPI:Mfpm} == ""
check-makevars::
		@${ECHO_CMD} "This port requires the CGI version of PHP, but you have already"
		@${ECHO_CMD} "installed a PHP port without CGI."
		@${FALSE}
.	endif
.endif

.if defined(WANT_PHP_CLI)
.	if defined(PHP_VERSION) && ${PHP_SAPI:Mcli} == ""
check-makevars::
		@${ECHO_CMD} "This port requires the CLI version of PHP, but you have already"
		@${ECHO_CMD} "installed a PHP port without CLI."
		@${FALSE}
.	endif
.endif

.if defined(WANT_PHP_EMB)
.	if defined(PHP_VERSION) && ${PHP_SAPI:Membed} == ""
check-makevars::
		@${ECHO_CMD} "This port requires the embedded library version of PHP, but you have already"
		@${ECHO_CMD} "installed a PHP port without the embedded library."
		@${FALSE}
.	endif
.endif

PHP_PORT?=	lang/php${PHP_VER}
MOD_PHP_PORT?=	www/mod_php${PHP_VER}

.if defined(USE_PHP_BUILD)
BUILD_DEPENDS+=	${PHPBASE}/include/php/main/php.h:${PHP_PORT}
.endif
RUN_DEPENDS+=	${PHPBASE}/include/php/main/php.h:${PHP_PORT}
.if defined(WANT_PHP_MOD) || (defined(WANT_PHP_WEB) && defined(PHP_VERSION) && ${PHP_SAPI:Mcgi} == "" && ${PHP_SAPI:Mfpm} == "")
USE_APACHE_RUN=	22+
.include "${PORTSDIR}/Mk/bsd.apache.mk"
RUN_DEPENDS+=	${PHPBASE}/${APACHEMODDIR}/libphp5.so:${MOD_PHP_PORT}
.endif

PLIST_SUB+=	PHP_EXT_DIR=${PHP_EXT_DIR}
SUB_LIST+=	PHP_EXT_DIR=${PHP_EXT_DIR}

.if defined(USE_PHPIZE) || defined(USE_PHPEXT) || defined(USE_ZENDEXT)
BUILD_DEPENDS+=	${PHPBASE}/bin/phpize:${PHP_PORT}
GNU_CONFIGURE=	yes
USE_AUTOTOOLS+=	autoconf:env
CONFIGURE_ARGS+=--with-php-config=${PHPBASE}/bin/php-config

configure-message: phpize-message do-phpize

phpize-message:
	@${ECHO_MSG} "===>  PHPizing for ${PKGNAME}"

do-phpize:
	@(cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ${PHPBASE}/bin/phpize)
.endif

.endif

.if defined(_POSTMKINCLUDED) && (defined(USE_PHPEXT) || defined(USE_ZENDEXT))
PHP_MODNAME?=	${PORTNAME}
PHP_HEADER_DIRS?=	""

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_LIB} ${WRKSRC}/modules/${PHP_MODNAME}.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
.	for header in . ${PHP_HEADER_DIRS}
		@${MKDIR} ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/${header}
		@${INSTALL_DATA} ${WRKSRC}/${header}/*.h \
			${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/${header}
.	endfor
	@${RM} -f ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/config.h
	@${GREP} "#define \(COMPILE\|HAVE\|USE\)_" ${WRKSRC}/config.h \
		> ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/config.h
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/php

add-plist-info: add-plist-phpext
add-plist-phpext:
	@${ECHO_CMD} "lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so" \
		>> ${TMPPLIST}
	@${FIND} -P ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME} ! -type d 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	@${ECHO_CMD} "@exec echo \#include \\\"ext/${PHP_MODNAME}/config.h\\\" >> %D/include/php/ext/php_config.h" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec cp %D/include/php/ext/php_config.h %D/include/php/ext/php_config.h.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec grep -v ext/${PHP_MODNAME}/config.h %D/include/php/ext/php_config.h.orig > %D/include/php/ext/php_config.h || true" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rm %D/include/php/ext/php_config.h.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@dir etc/php" \
		>> ${TMPPLIST}
.if defined(USE_ZENDEXT)
	@${ECHO_CMD} "@exec echo zend_extension=%D/lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so >> %D/etc/php/extensions.ini" \
		>> ${TMPPLIST}
.else
	@${ECHO_CMD} "@exec echo extension=${PHP_MODNAME}.so >> %D/etc/php/extensions.ini" \
		>> ${TMPPLIST}
.endif
	@${ECHO_CMD} "@unexec cp %D/etc/php/extensions.ini %D/etc/php/extensions.ini.orig" \
		>> ${TMPPLIST}
.if defined(USE_ZENDEXT)
	@${ECHO_CMD} "@unexec grep -v zend_extension=%D/lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}\\\.so %D/etc/php/extensions.ini.orig > %D/etc/php/extensions.ini || true" \
		>> ${TMPPLIST}
.else
	@${ECHO_CMD} "@unexec grep -v extension=${PHP_MODNAME}\\\.so %D/etc/php/extensions.ini.orig > %D/etc/php/extensions.ini || true" \
		>> ${TMPPLIST}
.endif
	@${ECHO_CMD} "@unexec rm %D/etc/php/extensions.ini.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec [ -s %D/etc/php/extensions.ini ] || rm %D/etc/php/extensions.ini" \
		>> ${TMPPLIST}

package-message: php-ini

php-ini:
	@${ECHO_CMD} "****************************************************************************"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "The following line has been added to your ${PREFIX}/etc/php/extensions.ini"
	@${ECHO_CMD} "configuration file to automatically load the installed extension:"
	@${ECHO_CMD} ""
.if defined(USE_ZENDEXT)
	@${ECHO_CMD} "zend_extension=${PREFIX}/lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so"
.else
	@${ECHO_CMD} "extension=${PHP_MODNAME}.so"
.endif
	@${ECHO_CMD} ""
	@${ECHO_CMD} "****************************************************************************"
.endif

# Extensions
.if defined(_POSTMKINCLUDED) && ${USE_PHP:tl} != "yes"
# non-version specific components
_USE_PHP_ALL=	apc bcmath bitset bz2 calendar ctype curl dba dom \
		exif fileinfo filter ftp gd gettext gmp \
		hash iconv igbinary imap interbase intl json ldap mbstring mcrypt \
		memcache mysqli odbc opcache \
		openssl pcntl pcre pdf pdo pdo_dblib pdo_firebird pdo_mysql \
		pdo_odbc pdo_pgsql pdo_sqlite phar pgsql posix \
		pspell radius readline recode session shmop simplexml snmp soap\
		sockets spl sqlite3 sysvmsg sysvsem sysvshm \
		tidy tokenizer wddx xml xmlreader xmlrpc xmlwriter xsl zip zlib
# version specific components
_USE_PHP_VER55=	${_USE_PHP_ALL} mssql mysql sybase_ct
_USE_PHP_VER56=	${_USE_PHP_ALL} mssql mysql sybase_ct
_USE_PHP_VER70=	${_USE_PHP_ALL}

apc_DEPENDS=	www/pecl-APC
bcmath_DEPENDS=	math/php${PHP_VER}-bcmath
.if ${PHP_VER} == 70
bitset_DEPENDS=	math/pecl-bitset
.else
bitset_DEPENDS=	math/pecl-bitset2
.endif
bz2_DEPENDS=	archivers/php${PHP_VER}-bz2
calendar_DEPENDS=	misc/php${PHP_VER}-calendar
ctype_DEPENDS=	textproc/php${PHP_VER}-ctype
curl_DEPENDS=	ftp/php${PHP_VER}-curl
dba_DEPENDS=	databases/php${PHP_VER}-dba
dbase_DEPENDS=	databases/php${PHP_VER}-dbase
dom_DEPENDS=	textproc/php${PHP_VER}-dom
exif_DEPENDS=	graphics/php${PHP_VER}-exif
fileinfo_DEPENDS=	sysutils/php${PHP_VER}-fileinfo
filter_DEPENDS=	security/php${PHP_VER}-filter
ftp_DEPENDS=	ftp/php${PHP_VER}-ftp
gd_DEPENDS=	graphics/php${PHP_VER}-gd
gettext_DEPENDS=devel/php${PHP_VER}-gettext
gmp_DEPENDS=	math/php${PHP_VER}-gmp
hash_DEPENDS=	security/php${PHP_VER}-hash
iconv_DEPENDS=	converters/php${PHP_VER}-iconv
igbinary_DEPENDS=	converters/pecl-igbinary
imap_DEPENDS=	mail/php${PHP_VER}-imap
interbase_DEPENDS=	databases/php${PHP_VER}-interbase
.if ${PHP_VER} == 70
intl_DEPENDS=	devel/php${PHP_VER}-intl
.else
intl_DEPENDS=	devel/pecl-intl
.endif
json_DEPENDS=	devel/php${PHP_VER}-json
ldap_DEPENDS=	net/php${PHP_VER}-ldap
mbstring_DEPENDS=	converters/php${PHP_VER}-mbstring
mcrypt_DEPENDS=	security/php${PHP_VER}-mcrypt
memcache_DEPENDS=	databases/pecl-memcache
mhash_DEPENDS=	security/php${PHP_VER}-mhash
mssql_DEPENDS=	databases/php${PHP_VER}-mssql
mysql_DEPENDS=	databases/php${PHP_VER}-mysql
mysqli_DEPENDS=	databases/php${PHP_VER}-mysqli
ncurses_DEPENDS=devel/php${PHP_VER}-ncurses
odbc_DEPENDS=	databases/php${PHP_VER}-odbc
oci8_DEPENDS=	databases/php${PHP_VER}-oci8
opcache_DEPENDS=	www/php${PHP_VER}-opcache
openssl_DEPENDS=security/php${PHP_VER}-openssl
pcntl_DEPENDS=	devel/php${PHP_VER}-pcntl
pdf_DEPENDS=	print/pecl-pdflib
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
radius_DEPENDS=	net/pecl-radius
readline_DEPENDS=	devel/php${PHP_VER}-readline
recode_DEPENDS=	converters/php${PHP_VER}-recode
session_DEPENDS=www/php${PHP_VER}-session
shmop_DEPENDS=	devel/php${PHP_VER}-shmop
simplexml_DEPENDS=	textproc/php${PHP_VER}-simplexml
snmp_DEPENDS=	net-mgmt/php${PHP_VER}-snmp
soap_DEPENDS=	net/php${PHP_VER}-soap
sockets_DEPENDS=net/php${PHP_VER}-sockets
spl_DEPENDS=	devel/php${PHP_VER}-spl
sqlite_DEPENDS=	databases/php${PHP_VER}-sqlite
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

.	for extension in ${USE_PHP}
.		if ${_USE_PHP_VER${PHP_VER}:M${extension}} != ""
.			if ${PHP_EXT_INC:M${extension}} == ""
.				if defined(USE_PHP_BUILD)
BUILD_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/${extension}.so:${${extension}_DEPENDS}
.				endif
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/${extension}.so:${${extension}_DEPENDS}
.			endif
.		else
ext=		${extension}
.			if ${ext} == "mhash"
.				if defined(USE_PHP_BUILD)
BUILD_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/hash.so:${hash_DEPENDS}
.				endif
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/hash.so:${hash_DEPENDS}
.			elif ${ext:tl} != "yes"
check-makevars::
			@${ECHO_CMD} "Unknown extension ${extension} for PHP ${PHP_VER}."
			@${FALSE}
.			endif
.		endif
.	endfor
.endif
