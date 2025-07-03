PORTNAME=	php83
PORTVERSION=	1.0
CATEGORIES=	lang
PKGNAMESUFFIX=	-extensions

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	"meta-port" to install PHP extensions (8.3.X branch)
WWW=		https://www.php.net/

USES=		metaport php

IGNORE_WITH_PHP=	81 82 84 85
PHP_VER=	83

OPTIONS_DEFINE=		BCMATH BZ2 CALENDAR CTYPE CURL DBA DOM ENCHANT EXIF FFI \
			FILEINFO FILTER FTP GD GETTEXT GMP ICONV IMAP INTL LDAP \
			MBSTRING MYSQLI ODBC OPCACHE PCNTL PDO PDO_DBLIB \
			PDO_FIREBIRD PDO_MYSQL PDO_ODBC PDO_PGSQL PDO_SQLITE \
			PGSQL PHAR POSIX PSPELL READLINE SESSION SHMOP \
			SIMPLEXML SNMP SOAP SOCKETS SODIUM SQLITE3 SYSVMSG \
			SYSVSEM SYSVSHM TIDY TOKENIZER XML XMLREADER XMLWRITER \
			XSL ZIP ZLIB
OPTIONS_DEFAULT=	CTYPE DOM FILTER ICONV OPCACHE PDO PDO_SQLITE PHAR \
			POSIX SESSION SIMPLEXML SQLITE3 TOKENIZER XML XMLREADER \
			XMLWRITER

BCMATH_DESC=		bc style precision math functions
BZ2_DESC=		bzip2 library support
CALENDAR_DESC=		calendar conversion support
CTYPE_DESC=		ctype functions
CURL_DESC=		CURL support
DBA_DESC=		dba support
DOM_DESC=		DOM support
ENCHANT_DESC=		Enchant spelling support
EXIF_DESC=		EXIF support
FFI_DESC=		Foreign Function Interface support
FILEINFO_DESC=		fileinfo support
FILTER_DESC=		input filter support
FTP_DESC=		FTP support
GD_DESC=		GD library support
GETTEXT_DESC=		gettext library support
GMP_DESC=		GNU MP support
ICONV_DESC=		iconv support
IMAP_DESC=		IMAP support
INTL_DESC=		Internationalization(ICU)
LDAP_DESC=		OpenLDAP support
MBSTRING_DESC=		multibyte string support
MYSQLI_DESC=		MySQLi database support
ODBC_DESC=		ODBC support
OPCACHE_DESC=		OPcache support
PCNTL_DESC=		pcntl support (CLI only)
PDO_DBLIB_DESC=		PDO DBLIB-DB driver
PDO_DESC=		PHP Data Objects Interface (PDO)
PDO_FIREBIRD_DESC=	PDO Firebird driver
PDO_MYSQL_DESC=		PDO MySQL driver
PDO_ODBC_DESC=		PDO ODBC driver
PDO_PGSQL_DESC=		PDO PostgreSQL driver
PDO_SQLITE_DESC=	PDO sqlite driver
PHAR_DESC=		phar support
POSIX_DESC=		POSIX-like functions
PSPELL_DESC=		pspell support
READLINE_DESC=		readline support (CLI only)
SESSION_DESC=		session support
SHMOP_DESC=		shmop support
SIMPLEXML_DESC=		simplexml support
SNMP_DESC=		SNMP support
SOAP_DESC=		SOAP support
SOCKETS_DESC=		sockets support
SODIUM_DESC=		Sodium encryption support
SQLITE3_DESC=		sqlite3 support
SYSVMSG_DESC=		System V message support
SYSVSEM_DESC=		System V semaphore support
SYSVSHM_DESC=		System V shared memory support
TIDY_DESC=		TIDY support
TOKENIZER_DESC=		tokenizer support
XMLREADER_DESC=		XMLReader support
XMLWRITER_DESC=		XMLWriter support
XML_DESC=		XML support
XSL_DESC=		XSL support (Implies DOM)
ZIP_DESC=		ZIP support
ZLIB_DESC=		ZLIB support

.include <bsd.port.options.mk>

.for opt in ${OPTIONS_DEFINE}
. if ${PORT_OPTIONS:M${opt}}
USE_PHP+=	${opt:tl}
. endif
.endfor

.include <bsd.port.mk>
