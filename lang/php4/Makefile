# New ports collection makefile for:	php4
# Date created:				Tue Feb 18 11:17:13 CET 2003
# Whom:					Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#
# There are many ways to select which extensions you want to enable, either
# in interactive mode or in batch mode.
#
# By default, the enabled extensions are: CTYPE, MYSQL, OVERLOAD, PCRE, POSIX,
# SESSION, TOKENIZER, XML and ZLIB. This behaviour can be changed overriding
# the PHP4_OPTIONS variable (e.g. PHP4_OPTIONS="EXT1 EXT2 EXT3").
#
# Another way is to use the WITH_<EXT> and WITHOUT_<EXT> knobs, for additional
# and default extensions respectively (implies batch mode).
#
# The last way reads an "extension" file, located in ~/php4_options (the
# location is overridable by the PHP4_OPTFILE variable). You may find an
# example in scripts/php4_options (interactive mode only).
#

PORTNAME=	php4
PORTVERSION=	4.3.4
PORTREVISION=	6
CATEGORIES?=	lang devel www
MASTER_SITES=	http://www.php.net/distributions/:release \
		http://it.php.net/distributions/:release \
		http://fi.php.net/distributions/:release \
		http://de.php.net/distributions/:release \
		http://gr.php.net/distributions/:release \
		http://fr.php.net/distributions/:release \
		http://es.php.net/distributions/:release \
		http://se.php.net/distributions/:release \
		http://downloads.php.net/ilia/:rc \
		http://downloads.php.net/jani/:rc
.if defined(WITHOUT_CLI) && !defined(WITHOUT_APACHE)
PKGNAMEPREFIX=	mod_
.else
.if defined(WITHOUT_APACHE)
.if defined(WITHOUT_CLI)
PKGNAMESUFFIX=	-cgi
.else
PKGNAMESUFFIX=	-cli
.endif
.endif
.endif
DISTNAME=	php-${PORTVERSION:S/.r/RC/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:release

MAINTAINER?=	ale@FreeBSD.org
COMMENT?=	PHP Scripting Language (Apache Module and CLI)
.if defined(WITHOUT_APACHE)
.if defined(WITHOUT_CLI)
COMMENT=	PHP Common Gateway Interface
.else
COMMENT=	PHP Command Line Interpreter
.endif
.else
.if defined(WITHOUT_CLI)
COMMENT=	PHP Apache Module
.endif
.endif

USE_BZIP2=	yes
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
USE_BISON=	yes
USE_REINPLACE=	yes

WITH_PTHREAD_LIBS?=	${PTHREAD_LIBS:S/-l//}
WITH_PTHREAD_CFLAGS?=	${PTHREAD_CFLAGS}

CONFIGURE_ENV=	ac_cv_pthreads_lib=${WITH_PTHREAD_LIBS} \
		ac_cv_pthreads_cflags=${WITH_PTHREAD_CFLAGS}

CONFIGURE_ARGS=	--enable-versioning \
		--enable-memory-limit \
		--with-layout=GNU \
		--with-zlib-dir=/usr \
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

EXT_DIR=	20020429
SAPI_FILE=	"@comment "

CONFLICTS=	php4-cli-4* mod_php4-4* php4-cgi-4*
.if defined(WITHOUT_APACHE)
.if defined(WITHOUT_CLI)
CONFLICTS=	php4-4* php4-cli-4* mod_php4-4*
.else
CONFLICTS=	php4-4* php4-cgi-4* mod_php4-4*
.endif
.else
.if defined(WITHOUT_CLI)
CONFLICTS=	php4-4* php4-cli-4* php4-cgi-4*
.endif
.endif
CONFLICTS+=	php5-5* php5-cli-5* mod_php5-5* php5-cgi-5*

.if defined(WITHOUT_APACHE)
.if defined(WITHOUT_CLI)
.if defined(WITH_FASTCGI)
CONFIGURE_ARGS+=--enable-fastcgi
.else
CONFIGURE_ARGS+=--enable-discard-path
.endif
SAPI_FILE=	bin/php
.endif
PLIST_SUB+=	APACHE="@comment "
.else
PLIST_SUB+=	APACHE=""
.endif
.if defined(WITHOUT_CLI)
CONFIGURE_ARGS+=--disable-cli
PLIST_SUB+=	CLI="@comment "
.else
.if !defined(WITHOUT_PEAR)
CONFIGURE_ARGS+=--with-pear
PLIST_SUB+=	PEAR=""
.else
PLIST_SUB+=	PEAR="@comment "
.endif
MAN1=		php.1
PLIST_SUB+=	CLI=""
.endif

ALL_OPTIONS=	BCMATH BZIP2 CALENDAR CDB CRACK CTYPE CURL DB4 DBASE DBX DIO \
		DOMXML DOMXSLT EXIF FILEPRO FRIBIDI FTP GD GDBM GETTEXT \
		GMP HYPERWAVE ICONV IMAP INTERBASE INIFILE MBSTRING MCAL MCVE \
		MCRYPT MHASH MIME MING MNOGOSEARCH MSSQL MYSQL NCURSES \
		OPENLDAP OPENSSL ORACLE OVERLOAD PCNTL PCRE PDFLIB POSIX \
		POSTGRESQL PSPELL READLINE RECODE SESSION SHMOP SNMP SOCKETS \
		SYBASEDB SYBASECT SYSVSEM SYSVSHM TOKENIZER UNIXODBC WDDX XML \
		XMLRPC XSLT YAZ YP ZIP ZLIB

.for opt in ${ALL_OPTIONS}
.if defined(WITH_${opt}) || defined(WITHOUT_${opt})
BATCH=		yes
.endif
.endfor

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

WRKDIR?=	${WRKDIRPREFIX}${.CURDIR}/work
PHP4_OPTFILE?=	${HOME}/php4_options

PHP4_OPTIONS?=	CTYPE MYSQL OVERLOAD PCRE POSIX SESSION TOKENIZER XML ZLIB

.for opt in ${ALL_OPTIONS}
.if defined(WITH_${opt})
SEL_OPTIONS+=	${opt}
.endif
.endfor
.for opt in ${PHP4_OPTIONS}
.if !defined(WITHOUT_${opt})
SEL_OPTIONS+=	${opt}
.if !exists(${WRKDIR}/Makefile.inc)
WITH_${opt}=	yes
.endif
.endif
SCRIPTS_ENV+=	WITH_${opt}=ON
.endfor

SCRIPTS_ENV+=	SEL_OPTIONS="${SEL_OPTIONS}" \
		OPTION_FILE="${PHP4_OPTFILE}" \
		WRKDIR="${WRKDIR}" \
		CAT="${CAT}" \
		SED="${SED}"

.if exists(${WRKDIR}/Makefile.inc)
.include "${WRKDIR}/Makefile.inc"
.endif

.if !defined(WITHOUT_CLI) && !defined(WITHOUT_PEAR)
WITH_PCRE=	yes
WITH_XML=	yes
WITH_XMLRPC=	yes
.endif

.if defined(WITH_CDB) || defined(WITH_DB4) || defined(WITH_GDBM) || defined(WITH_INIFILE)
WITH_DBA=	yes
.endif

.if defined(WITH_DOMXSLT)
WITH_DOMXML=	yes
.endif

.if defined(WITH_XMLRPC) || defined(WITH_XSLT)
WITH_ICONV_DEP=	yes
.endif

.if defined(WITH_MCVE) || defined(WITH_SNMP)
WITH_OPENSSL_DEP=	yes
.endif

.if defined(WITH_XMLRPC) || defined(WITH_XSLT)
WITH_XML_DEP=	yes
.endif

.if defined(WITH_WDDX)
WITH_XML=	yes
.endif

.if defined(WITH_BCMATH)
CONFIGURE_ARGS+=--enable-bcmath
.endif

.if defined(WITH_BZIP2)
.if exists(/usr/bin/bzip2)
BZIP2BASE=	/usr
.else
BZIP2BASE=	${LOCALBASE}
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif
CONFIGURE_ARGS+=--with-bz2=${BZIP2BASE}
.endif

.if defined(WITH_CALENDAR)
CONFIGURE_ARGS+=--enable-calendar
.endif

.if defined(WITH_CDB)
CONFIGURE_ARGS+=--with-cdb
.endif

.if defined(WITH_CRACK)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib
RUN_DEPENDS+=	${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib
CONFIGURE_ARGS+=--with-crack=${LOCALBASE}
.endif

.if defined(WITH_CTYPE)
CONFIGURE_ARGS+=--enable-ctype
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=	curl.2:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-curl=${LOCALBASE}
.endif

.if defined(WITH_DB4)
WITH_DB4_VER?=	41
.if ${WITH_DB4_VER} == 4
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
.else
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
.endif
CONFIGURE_ARGS+=--with-db4=${LOCALBASE}
.endif

.if defined(WITH_DBA)
CONFIGURE_ARGS+=--enable-dba
.endif

.if defined(WITH_DBASE)
CONFIGURE_ARGS+=--enable-dbase
.endif

.if defined(WITH_DBX)
CONFIGURE_ARGS+=--enable-dbx
.endif

.if defined(WITH_DIO)
CONFIGURE_ARGS+=--enable-dio
.endif

.if defined(WITH_DOMXML)
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=--with-dom=${LOCALBASE}
.endif

.if defined(WITH_DOMXSLT)
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
CONFIGURE_ARGS+=--with-dom-xslt=${LOCALBASE} --with-dom-exslt=${LOCALBASE}
.endif

.if defined(WITH_EXIF)
CONFIGURE_ARGS+=--enable-exif
.endif

.if defined(WITH_FILEPRO)
CONFIGURE_ARGS+=--enable-filepro
.endif

.if defined(WITH_FRIBIDI)
LIB_DEPENDS+=	fribidi.0:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=--with-fribidi=${LOCALBASE}
.endif

.if defined(WITH_FTP)
CONFIGURE_ARGS+=--enable-ftp
.endif

.if defined(WITH_GD)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--with-gd \
		--enable-gd-native-ttf \
		--enable-gd-jis-conv \
		--with-freetype-dir=${LOCALBASE} \
		--with-jpeg-dir=${LOCALBASE} \
		--with-png-dir=${LOCALBASE}
.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	Xpm.4:${PORTSDIR}/x11/XFree86-4-libraries
CONFIGURE_ARGS+=--with-xpm-dir=${LOCALBASE}
.endif
.if defined(WITH_LZW)
CONFIGURE_ARGS+=--enable-gd-lzw-gif
.endif
.endif

.if defined(WITH_GDBM)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=--with-gdbm=${LOCALBASE}
.endif

.if defined(WITH_GETTEXT)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--with-gettext=${LOCALBASE}
.endif

.if defined(WITH_GMP)
LIB_DEPENDS+=	gmp.6:${PORTSDIR}/math/libgmp4
CONFIGURE_ARGS+=--with-gmp=${LOCALBASE}
.endif

.if defined(WITH_HYPERWAVE)
CONFIGURE_ARGS+=--with-hyperwave
.endif

.if defined(WITH_ICONV) || defined(WITH_ICONV_DEP)
LIB_DEPENDS+=	iconv.3:${PORTSDIR}/converters/libiconv
CONFIGURE_ARGS+=--with-iconv-dir=${LOCALBASE}
.endif

.if defined(WITH_ICONV)
CONFIGURE_ARGS+=--with-iconv=${LOCALBASE}
.endif

.if defined(WITH_INIFILE)
CONFIGURE_ARGS+=--with-inifile
.endif

.if defined(WITH_INTERBASE)
LIB_DEPENDS+=	gds.1:${PORTSDIR}/databases/firebird
CONFIGURE_ARGS+=--with-interbase=${LOCALBASE}/firebird
.endif

.if defined(WITH_MBSTRING)
CONFIGURE_ARGS+=--enable-mbstring
.endif

.if defined(WITH_MCAL)
LIB_DEPENDS+=	mcal.0:${PORTSDIR}/misc/libmcal
CONFIGURE_ARGS+=--with-mcal=${LOCALBASE}
.endif

.if defined(WITH_MCVE)
LIB_DEPENDS+=	mcve.3:${PORTSDIR}/devel/libmcve
CONFIGURE_ARGS+=--with-mcve=${LOCALBASE}
.endif

.if defined(WITH_MCRYPT)
LIB_DEPENDS+=	mcrypt.8:${PORTSDIR}/security/libmcrypt
LIB_DEPENDS+=	ltdl.4:${PORTSDIR}/devel/libltdl
CONFIGURE_ARGS+=--with-mcrypt=${LOCALBASE}
.endif

.if defined(WITH_MHASH)
LIB_DEPENDS+=	mhash.2:${PORTSDIR}/security/mhash
CONFIGURE_ARGS+=--with-mhash=${LOCALBASE}
.endif

.if defined(WITH_MIME)
CONFIGURE_ARGS+=--with-mime-magic=/usr/share/misc/magic.mime
.endif

.if defined(WITH_MING)
LIB_DEPENDS+=	ming.3:${PORTSDIR}/graphics/ming
CONFIGURE_ARGS+=--with-ming=${LOCALBASE}
.endif

.if defined(WITH_MNOGOSEARCH)
LIB_DEPENDS+=	udmsearch.1:${PORTSDIR}/www/mnogosearch
CONFIGURE_ARGS+=--with-mnogosearch=${LOCALBASE}
.endif

.if defined(WITH_MSSQL)
LIB_DEPENDS+=	sybdb.4:${PORTSDIR}/databases/freetds-msdblib
CONFIGURE_ARGS+=--with-mssql=${LOCALBASE}
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
.endif

.if defined(WITH_OPENSSL) || defined(WITH_OPENSSL_DEP)
USE_OPENSSL=	yes
LDFLAGS+=	-lcrypto -lssl
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--with-openssl-dir=${OPENSSLBASE}
.endif

.if defined(WITH_OPENSSL)
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

.if defined(WITH_ORACLE)
BUILD_DEPENDS+=	${LOCALBASE}/oracle7/lib/libcore3.a:${PORTSDIR}/databases/oracle7-client
RUN_DEPENDS+=	${LOCALBASE}/oracle7/lib/libcore3.a:${PORTSDIR}/databases/oracle7-client
CONFIGURE_ARGS+=--with-oracle=${LOCALBASE}/oracle7
.endif

.if defined(WITH_OVERLOAD)
CONFIGURE_ARGS+=--enable-overload
.endif

.if defined(WITH_PCNTL)
CONFIGURE_ARGS+=--enable-pcntl
.endif

.if defined(WITH_PCRE)
CONFIGURE_ARGS+=--with-pcre-regex=yes
.endif

.if defined(WITH_PDFLIB)
LIB_DEPENDS+=	pdf.6:${PORTSDIR}/print/pdflib
CONFIGURE_ARGS+=--with-pdflib=${LOCALBASE}
.endif

.if defined(WITH_POSIX)
CONFIGURE_ARGS+=--enable-posix
.endif

.if defined(WITH_POSTGRESQL)
POSTGRESQL_PORT?=	databases/postgresql-client
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}
.endif

.if defined(WITH_PSPELL)
LIB_DEPENDS+=	aspell.15:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--with-pspell=${LOCALBASE}
.endif

.if defined(WITH_READLINE)
CONFIGURE_ARGS+=--with-readline
.endif

.if defined(WITH_RECODE)
LIB_DEPENDS+=	recode.3:${PORTSDIR}/converters/recode
CONFIGURE_ARGS+=--with-recode=${LOCALBASE}
.endif

.if defined(WITH_SESSION)
CONFIGURE_ARGS+=--enable-session
.endif

.if defined(WITH_SHMOP)
CONFIGURE_ARGS+=--enable-shmop
.endif

.if defined(WITH_SOCKETS)
CONFIGURE_ARGS+=--enable-sockets
.endif

.if defined(WITH_SYBASEDB)
LIB_DEPENDS+=	sybdb.4:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=--with-sybase=${LOCALBASE}
.endif

.if defined(WITH_SYBASECT)
LIB_DEPENDS+=	ct.2:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=--with-sybase-ct=${LOCALBASE}
.endif

.if defined(WITH_SYSVSEM)
CONFIGURE_ARGS+=--enable-sysvsem
.endif

.if defined(WITH_SYSVSHM)
CONFIGURE_ARGS+=--enable-sysvshm
.endif

.if defined(WITH_TOKENIZER)
CONFIGURE_ARGS+=--enable-tokenizer
.endif

.if defined(WITH_UNIXODBC)
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=--with-unixODBC=${LOCALBASE}
.endif

.if defined(WITH_WDDX)
CONFIGURE_ARGS+=--enable-wddx
.endif

.if defined(WITH_XML) || defined(WITH_XML_DEP)
LIB_DEPENDS+=	expat.4:${PORTSDIR}/textproc/expat2
CONFIGURE_ARGS+=--with-expat-dir=${LOCALBASE}
.endif

.if defined(WITH_XML)
CONFIGURE_ARGS+=--enable-xml
.endif

.if defined(WITH_XMLRPC)
CONFIGURE_ARGS+=--with-xmlrpc
.endif

.if defined(WITH_XSLT)
LIB_DEPENDS+=	sablot.70:${PORTSDIR}/textproc/sablotron
CONFIGURE_ARGS+=--enable-xslt --with-xslt-sablot=${LOCALBASE}
.endif

.if defined(WITH_YAZ)
LIB_DEPENDS+=	yaz.2:${PORTSDIR}/net/yaz
CONFIGURE_ARGS+=--with-yaz=${LOCALBASE}/bin
.endif

.if defined(WITH_YP)
CONFIGURE_ARGS+=--enable-yp
.endif

.if defined(WITH_ZIP)
LIB_DEPENDS+=	zzip.10:${PORTSDIR}/devel/zziplib
CONFIGURE_ARGS+=--with-zip=${LOCALBASE}
.endif

.if defined(WITH_ZLIB)
CONFIGURE_ARGS+=--with-zlib=yes
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_APACHE)
.if exists(${LOCALBASE}/include/apache2/apr.h)
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

PLIST_SUB+=	SAPI_FILE=${SAPI_FILE} \
		EXT_DIR=${EXT_DIR}

.if ${OSVERSION} < 400014 || defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if defined(WITH_IMAP)
LIB_DEPENDS+=	c-client4.8:${PORTSDIR}/mail/cclient
.if !exists(${LOCALBASE}/lib/libc-client4.so)
.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=--with-imap=${LOCALBASE} --with-imap-ssl=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-imap=${LOCALBASE}
.endif
.else
WITH_IMAP_SSL!=	/usr/bin/ldd ${LOCALBASE}/lib/libc-client4.so | ${GREP} libssl || ${TRUE}
.if !empty(WITH_IMAP_SSL)
CONFIGURE_ARGS+=--with-imap=${LOCALBASE} --with-imap-ssl=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-imap=${LOCALBASE}
.endif
.endif
.endif

.if defined(WITH_NCURSES)
.if ${OSVERSION} < 400000
NCURSESBASE=	${LOCALBASE}
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.else
NCURSESBASE=	/usr
.endif
CONFIGURE_ARGS+=--with-ncurses=${NCURSESBASE}
.endif

.if defined(WITH_SNMP)
.if exists(${LOCALBASE}/lib/libsnmp.so.4) || defined(WITH_SNMP4)
LIB_DEPENDS+=	snmp.4:${PORTSDIR}/net/net-snmp4
.else
LIB_DEPENDS+=	netsnmp.6:${PORTSDIR}/net/net-snmp
.endif
CONFIGURE_ARGS+=--with-snmp=${LOCALBASE} --enable-ucd-snmp-hack
.endif

pre-patch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.php

post-patch:
	@${REINPLACE_CMD} -e "s|orainst/unix.rgs|ocommon/install/partial.prd|g" \
		${WRKSRC}/configure
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/pear/scripts/pearcmd.php > ${WRKSRC}/pear/scripts/pear

pre-configure:
	@${ECHO_CMD} ""
.if defined(WITH_IMAP) && defined(WITH_RECODE)
	@${ECHO_CMD} "You cannot define WITH_IMAP *and* WITH_RECODE!"
	@${FALSE}
.endif
.if defined(WITH_IMAP) && defined(WITH_YAZ)
	@${ECHO_CMD} "You cannot define WITH_IMAP *and* WITH_YAZ!"
	@${FALSE}
.endif
.if defined(WITH_RECODE) && defined(WITH_YAZ)
	@${ECHO_CMD} "You cannot define WITH_RECODE *and* WITH_YAZ!"
	@${FALSE}
.endif
.if defined(WITH_SYBASEDB) && defined(WITH_SYBASECT)
	@${ECHO_CMD} "You cannot define WITH_SYBASEDB *and* WITH_SYBASECT!"
	@${FALSE}
.endif
.if defined(WITH_GD) && !defined(WITH_LZW)
	@${ECHO_CMD} "To enable LZW-compressed GIF support in GD define the WITH_LZW knob."
	@${ECHO_CMD} ""
.endif
.if !defined(WITHOUT_APACHE) && !defined(WITHOUT_CLI)
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
	@${ECHO_CMD} "PHP_PORT=${.CURDIR}" >> ${WRKDIR}/php.conf
.if !defined(WITHOUT_CLI) && !defined(WITHOUT_PEAR)
	@${ECHO_CMD} "PHP_PEAR=yes" >> ${WRKDIR}/php.conf
.else
	@${ECHO_CMD} "PHP_PEAR=no" >> ${WRKDIR}/php.conf
.endif
.if !defined(WITHOUT_APACHE) && !defined(WITHOUT_CLI)
	@${ECHO_CMD} "PHP_SAPI=full" >> ${WRKDIR}/php.conf
.else
.if defined(WITHOUT_APACHE) && !defined(WITHOUT_CLI)
	@${ECHO_CMD} "PHP_SAPI=cli" >> ${WRKDIR}/php.conf
.endif
.if !defined(WITHOUT_APACHE) && defined(WITHOUT_CLI)
	@${ECHO_CMD} "PHP_SAPI=mod" >> ${WRKDIR}/php.conf
.endif
.if defined(WITHOUT_APACHE) && defined(WITHOUT_CLI)
	@${ECHO_CMD} "PHP_SAPI=cgi" >> ${WRKDIR}/php.conf
.endif
.endif
.if !defined(WITHOUT_CLI)
	@${ECHO_CMD} "You may run the tests from the PHP test framework, typing 'make test' now."
	@${ECHO_CMD} "(It is safe to ignore errors about timestamp-related tests,"
	@${ECHO_CMD} "since they are due to the different FreeBSD mktime() implementation)."
	@${ECHO_CMD} ""
.endif

.if !defined(WITHOUT_CLI)
test: all
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${.TARGET})
.endif

post-install:
.if !defined(WITHOUT_CLI) && !defined(WITHOUT_PEAR)
	@${INSTALL_SCRIPT} ${WRKSRC}/pear/scripts/pear ${PREFIX}/bin
.endif
	@${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKSRC}/php.ini-recommended ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKDIR}/php.conf ${PREFIX}/etc
	@${TOUCH} ${PREFIX}/lib/php/${EXT_DIR}/.keepme
.if !defined(WITHOUT_APACHE)
	@${ECHO_CMD} "*****************************************************************************"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Make sure index.php is part of your DirectoryIndex."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You should add the following lines to your Apache configuration file:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "AddType application/x-httpd-php .php"
	@${ECHO_CMD} "AddType application/x-httpd-php-source .phps"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "*****************************************************************************"
.endif

.include <bsd.port.post.mk>
