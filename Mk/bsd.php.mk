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
# If the port requires a predefined set of PHP extensions, they can be
# listed in this way:
#
# USE_PHP=	ext1 ext2 ext3
#
# The port can set these options in its Makefile before bsd.ports.pre.mk:
#
# DEFAULT_PHP_VER=N - Use PHP version N if PHP is not yet installed.
# BROKEN_WITH_PHP=N - The port doesn't work with PHP version N.
# USE_PHPIZE=yes    - Use to build a PHP extension.
# USE_PHPEXT=yes    - Use to build, install and register a PHP extension.
# USE_PHP_BUILD=yes - Set PHP also as a build dependency.
# WANT_PHP_CLI=yes  - Want the CLI version of PHP.
# WANT_PHP_CGI=yes  - Want the CGI version of PHP.
# WANT_PHP_MOD=yes  - Want the Apache Module for PHP.
# WANT_PHP_WEB=yes  - Want the Apache Module or the CGI version of PHP.
#
# You may combine multiple WANT_PHP_* knobs.
# Don't specify any WANT_PHP_* knob if your port will work with every PHP SAPI.
#

PHP_Include_MAINTAINER=	ale@FreeBSD.org

.if exists(${LOCALBASE}/etc/php.conf)
.include "${LOCALBASE}/etc/php.conf"
PHP_EXT_DIR!=	${LOCALBASE}/bin/php-config --extension-dir | ${SED} -ne 's,^${LOCALBASE}/lib/php/\(.*\),\1,p'
.else
DEFAULT_PHP_VER?=	4

PHP_VER?=	${DEFAULT_PHP_VER}
.if ${PHP_VER} == 4
PHP_EXT_DIR=	20020429
.else
PHP_EXT_DIR=	20050922
.endif

HTTPD?=		${LOCALBASE}/sbin/httpd
.if exists(${HTTPD})
APACHE_VERSION!=	${HTTPD} -V | ${SED} -ne 's/^Server version: Apache\/\([0-9]\)\.\([0-9]*\).*/\1\2/p'
.	if ${APACHE_VERSION} > 13
APXS?=		${LOCALBASE}/sbin/apxs
APACHE_MPM!=	${APXS} -q MPM_NAME
.		if ${APACHE_MPM} == "worker"
PHP_EXT_DIR:=	${PHP_EXT_DIR}-zts
.		endif
.	endif
.elif defined(APACHE_PORT)
APACHE_VERSION!=	${ECHO_CMD} ${APACHE_PORT} | ${SED} -ne 's,.*/apache\([0-9]*\).*,\1,p'
.	if ${APACHE_VERSION} > 13 && defined(WITH_MPM) && ${WITH_MPM} == "worker"
PHP_EXT_DIR:=	${PHP_EXT_DIR}-zts
.	endif
.endif

.if defined(WITH_DEBUG)
PHP_EXT_DIR:=	${PHP_EXT_DIR}-debug
.endif
PHP_SAPI?=	""
.endif
PHP_EXT_INC?=	""

.if defined(BROKEN_WITH_PHP)
.	for VER in ${BROKEN_WITH_PHP}
.		if ${PHP_VER} == "${VER}"
BROKEN=		Doesn't work with PHP version : ${PHP_VER} (Doesn't support PHP ${BROKEN_WITH_PHP})
.		endif
.	endfor
.endif

.if defined(WANT_PHP_WEB)
.	if defined(WANT_PHP_CGI) || defined(WANT_PHP_MOD)
check-makevars::
		@${ECHO_CMD} "If you define WANT_PHP_WEB you cannot set also WANT_PHP_CGI"
		@${ECHO_CMD} "or WANT_PHP_MOD. Use only one of them."
		@${FALSE}
.	else
.	if defined(PHP_VERSION) && ${PHP_SAPI:Mcgi} == "" && ${PHP_SAPI:Mmod} == ""
check-makevars::
		@${ECHO_CMD} "This port requires the Apache Module or the CGI version of PHP, but you have"
		@${ECHO_CMD} "already installed a PHP port without them."
		@${FALSE}
.	endif
.	endif
.else

.if defined(WANT_PHP_CGI)
.	if defined(PHP_VERSION) && ${PHP_SAPI:Mcgi} == ""
check-makevars::
		@${ECHO_CMD} "This port requires the CGI version of PHP, but you have already"
		@${ECHO_CMD} "installed a PHP port without CGI."
		@${FALSE}
.	endif
.else

.if defined(WANT_PHP_CLI)
.	if defined(PHP_VERSION) && ${PHP_SAPI:Mcli} == ""
check-makevars::
		@${ECHO_CMD} "This port requires the CLI version of PHP, but you have already"
		@${ECHO_CMD} "installed a PHP port without CLI."
		@${FALSE}
.	endif
.else

.if defined(WANT_PHP_MOD)
.	if defined(PHP_VERSION) && ${PHP_SAPI:Mmod} == ""
check-makevars::
		@${ECHO_CMD} "This port requires the Apache Module for PHP, but you have already"
		@${ECHO_CMD} "installed a PHP port without the Apache Module."
		@${FALSE}
.	endif
.endif

.endif

.endif

.endif

PHP_PORT=	${PORTSDIR}/lang/php${PHP_VER}

.if defined(USE_PHP_BUILD)
BUILD_DEPENDS+=	${LOCALBASE}/include/php/main/php.h:${PHP_PORT}
.endif
RUN_DEPENDS+=	${LOCALBASE}/include/php/main/php.h:${PHP_PORT}

PLIST_SUB+=	PHP_EXT_DIR=${PHP_EXT_DIR}
SUB_LIST+=	PHP_EXT_DIR=${PHP_EXT_DIR}

.if defined(USE_PHPIZE) || defined(USE_PHPEXT)
BUILD_DEPENDS+=	phpize:${PHP_PORT}
GNU_CONFIGURE=	YES
USE_AUTOTOOLS+=	autoconf:259:env
CONFIGURE_ARGS+=--with-php-config=${LOCALBASE}/bin/php-config

configure-message: phpize-message do-phpize

phpize-message:
	@${ECHO_MSG} "===>  PHPizing for ${PKGNAME}"

do-phpize:
	@(cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ${LOCALBASE}/bin/phpize)
.endif

.if defined(USE_PHPEXT)
PHP_MODNAME?=	${PORTNAME}
PHP_HEADER_DIRS?=	""

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/${PHP_MODNAME}.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}
.	for header in . ${PHP_HEADER_DIRS}
		@${MKDIR} ${PREFIX}/include/php/ext/${PHP_MODNAME}/${header}
		@${INSTALL_DATA} ${WRKSRC}/${header}/*.h \
			${PREFIX}/include/php/ext/${PHP_MODNAME}/${header}
.	endfor
	@${GREP} "#define \(COMPILE\|HAVE\|USE\)_" ${WRKSRC}/config.h \
		> ${PREFIX}/include/php/ext/${PHP_MODNAME}/config.h
	@${ECHO_CMD} \#include \"ext/${PHP_MODNAME}/config.h\" \
		>> ${PREFIX}/include/php/ext/php_config.h
	@${MKDIR} ${PREFIX}/etc/php
	@${ECHO_CMD} extension=${PHP_MODNAME}.so \
		>> ${PREFIX}/etc/php/extensions.ini

add-plist-info: add-plist-phpext
add-plist-phpext:
	@${ECHO_CMD} "lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/php/${PHP_EXT_DIR} 2> /dev/null || true" \
		>> ${TMPPLIST}
	@${FIND} -P ${PREFIX}/include/php/ext/${PHP_MODNAME} ! -type d 2>/dev/null | \
		${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -P -d ${PREFIX}/include/php/ext/${PHP_MODNAME} -type d 2>/dev/null | \
		${SED} -ne 's,^${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}
	@${ECHO_CMD} "@exec echo \#include \\\"ext/${PHP_MODNAME}/config.h\\\" >> %D/include/php/ext/php_config.h" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec cp %D/include/php/ext/php_config.h %D/include/php/ext/php_config.h.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec grep -v ext/${PHP_MODNAME}/config.h %D/include/php/ext/php_config.h.orig > %D/include/php/ext/php_config.h || true" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rm %D/include/php/ext/php_config.h.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@exec mkdir -p %D/etc/php" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@exec echo extension=${PHP_MODNAME}.so >> %D/etc/php/extensions.ini" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec cp %D/etc/php/extensions.ini %D/etc/php/extensions.ini.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec grep -v extension=${PHP_MODNAME}\\\.so %D/etc/php/extensions.ini.orig > %D/etc/php/extensions.ini || true" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rm %D/etc/php/extensions.ini.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec [ -s %D/etc/php/extensions.ini ] || rm %D/etc/php/extensions.ini" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/etc/php 2> /dev/null || true" \
		>> ${TMPPLIST}

security-check: php-ini

php-ini:
	@${ECHO_CMD} "****************************************************************************"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "The following line has been added to your ${PREFIX}/etc/php/extensions.ini"
	@${ECHO_CMD} "configuration file to automatically load the installed extension:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "extension=${PHP_MODNAME}.so"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "****************************************************************************"
.endif

# Extensions
.if ${USE_PHP:L} != "yes"
# non-version specific components
_USE_PHP_ALL=	bcmath bz2 calendar ctype curl dba dbase \
		exif fileinfo filepro fribidi ftp gd gettext gmp \
		hash iconv imagick imap interbase ldap mbstring mcrypt \
		mhash ming mssql mysql ncurses odbc \
		openssl panda pcntl pcre pdf pgsql posix \
		pspell radius readline recode session shmop snmp \
		sockets sybase_ct sysvmsg sysvsem sysvshm \
		tokenizer wddx xml xmlrpc yaz zip zlib
# version specific components
_USE_PHP_VER4=	${_USE_PHP_ALL} crack dbx dio domxml mcal mcve \
		mnogosearch oracle overload pfpro xslt yp
_USE_PHP_VER5=	${_USE_PHP_ALL} dom mysqli pdo simplexml soap sqlite \
		tidy xmlreader xmlwriter xsl

bcmath_DEPENDS=	math/php${PHP_VER}-bcmath
bz2_DEPENDS=	archivers/php${PHP_VER}-bz2
calendar_DEPENDS=	misc/php${PHP_VER}-calendar
crack_DEPENDS=	security/php${PHP_VER}-crack
ctype_DEPENDS=	textproc/php${PHP_VER}-ctype
curl_DEPENDS=	ftp/php${PHP_VER}-curl
dba_DEPENDS=	databases/php${PHP_VER}-dba
dbase_DEPENDS=	databases/php${PHP_VER}-dbase
dbx_DEPENDS=	databases/php${PHP_VER}-dbx
dio_DEPENDS=	devel/php${PHP_VER}-dio
dom_DEPENDS=	textproc/php${PHP_VER}-dom
domxml_DEPENDS=	textproc/php${PHP_VER}-domxml
exif_DEPENDS=	graphics/php${PHP_VER}-exif
fileinfo_DEPENDS=	sysutils/pecl-fileinfo
filepro_DEPENDS=databases/php${PHP_VER}-filepro
fribidi_DEPENDS=converters/pecl-fribidi
ftp_DEPENDS=	ftp/php${PHP_VER}-ftp
gd_DEPENDS=	graphics/php${PHP_VER}-gd
gettext_DEPENDS=devel/php${PHP_VER}-gettext
gmp_DEPENDS=	math/php${PHP_VER}-gmp
hash_DEPENDS=	security/pecl-hash
iconv_DEPENDS=	converters/php${PHP_VER}-iconv
imagick_DEPENDS=graphics/pecl-imagick
imap_DEPENDS=	mail/php${PHP_VER}-imap
interbase_DEPENDS=	databases/php${PHP_VER}-interbase
ldap_DEPENDS=	net/php${PHP_VER}-ldap
mbstring_DEPENDS=	converters/php${PHP_VER}-mbstring
mcal_DEPENDS=	misc/php${PHP_VER}-mcal
mcrypt_DEPENDS=	security/php${PHP_VER}-mcrypt
mcve_DEPENDS=	devel/php${PHP_VER}-mcve
mhash_DEPENDS=	security/php${PHP_VER}-mhash
ming_DEPENDS=	graphics/php${PHP_VER}-ming
mnogosearch_DEPENDS=	www/php${PHP_VER}-mnogosearch
mssql_DEPENDS=	databases/php${PHP_VER}-mssql
mysql_DEPENDS=	databases/php${PHP_VER}-mysql
mysqli_DEPENDS=	databases/php${PHP_VER}-mysqli
ncurses_DEPENDS=devel/php${PHP_VER}-ncurses
odbc_DEPENDS=	databases/php${PHP_VER}-odbc
openssl_DEPENDS=security/php${PHP_VER}-openssl
oracle_DEPENDS=	databases/php${PHP_VER}-oracle
overload_DEPENDS=lang/php${PHP_VER}-overload
panda_DEPENDS=	print/pecl-panda
pcntl_DEPENDS=	devel/php${PHP_VER}-pcntl
pcre_DEPENDS=	devel/php${PHP_VER}-pcre
pdf_DEPENDS=	print/pecl-pdflib
pdo_DEPENDS=	databases/pecl-PDO
pfpro_DEPENDS=	finance/php${PHP_VER}-pfpro
pgsql_DEPENDS=	databases/php${PHP_VER}-pgsql
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
sqlite_DEPENDS=	databases/php${PHP_VER}-sqlite
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
xslt_DEPENDS=	textproc/php${PHP_VER}-xslt
yaz_DEPENDS=	net/pecl-yaz
yp_DEPENDS=	net/php${PHP_VER}-yp
zip_DEPENDS=	archivers/pecl-zip
zlib_DEPENDS=	archivers/php${PHP_VER}-zlib

.	for extension in ${USE_PHP}
.		if ${_USE_PHP_VER${PHP_VER}:M${extension}} != ""
.			if ${PHP_EXT_INC:M${extension}} == ""
.				if defined(USE_PHP_BUILD)
BUILD_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/${extension}.so:${PORTSDIR}/${${extension}_DEPENDS}
.				endif
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/${extension}.so:${PORTSDIR}/${${extension}_DEPENDS}
.			endif
.		else
isyes=		${extension}
.			if ${isyes:L} != "yes"
check-makevars::
				@${ECHO_CMD} "Unknown extension ${extension} for PHP ${PHP_VER}."
				@${FALSE}
.			endif
.		endif
.	endfor
.endif
