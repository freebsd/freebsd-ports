# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php70
PORTVERSION=	1.1
CATEGORIES=	lang
PKGNAMESUFFIX=	-extensions

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	"meta-port" to install PHP extensions

USES=		metaport
USE_PHP=	yes
PHP_DEFAULT=	7.0
IGNORE_WITH_PHP=	55 56
USE_PHP_BUILD=	yes

OPTIONS_DEFINE=	BCMATH BZ2 CALENDAR CTYPE CURL DBA \
		DOM EXIF FILEINFO FILTER FTP GD GETTEXT \
		GMP HASH ICONV INTL IMAP INTERBASE JSON LDAP MBSTRING MCRYPT \
		MYSQLI \
		ODBC OPCACHE OPENSSL PCNTL PDF PDO PDO_DBLIB PDO_FIREBIRD \
		PDO_MYSQL PDO_ODBC PDO_PGSQL PDO_SQLITE PGSQL PHAR POSIX \
		PSPELL READLINE RECODE SESSION SHMOP SIMPLEXML SNMP SOAP \
		SOCKETS SQLITE3 SYBASE_CT SYSVMSG SYSVSEM SYSVSHM \
		TIDY TOKENIZER WDDX XML XMLREADER XMLRPC XMLWRITER XSL \
		ZIP ZLIB

BCMATH_DESC=		bc style precision math functions
BZ2_DESC=		bzip2 library support
CALENDAR_DESC=		calendar conversion support
CTYPE_DESC=		ctype functions
CURL_DESC=		CURL support
DBA_DESC=		dba support
DOM_DESC=		DOM support
EXIF_DESC=		EXIF support
FILEINFO_DESC=		fileinfo support
FILTER_DESC=		input filter support
FTP_DESC=		FTP support
GD_DESC=		GD library support
GETTEXT_DESC=		gettext library support
GMP_DESC=		GNU MP support
HASH_DESC=		HASH Message Digest Framework
ICONV_DESC=		iconv support
IMAP_DESC=		IMAP support
INTL_DESC=		Internationalization(ICU)
INTERBASE_DESC=		Interbase 6 database support (Firebird)
JSON_DESC=		JavaScript Object Serialization support
LDAP_DESC=		OpenLDAP support
MBSTRING_DESC=		multibyte string support
MCRYPT_DESC=		Encryption support
MYSQLI_DESC=		MySQLi database support
ODBC_DESC=		ODBC support
OPCACHE_DESC=		OPcache support
OPENSSL_DESC=		OpenSSL support
PCNTL_DESC=		pcntl support (CLI only)
PDF_DESC=		PDFlib support (implies GD)
PDO_DESC=		PHP Data Objects Interface (PDO)
PDO_DBLIB_DESC=		PDO DBLIB-DB driver
PDO_FIREBIRD_DESC=	PDO Firebird driver
PDO_MYSQL_DESC=		PDO MySQL driver
PDO_ODBC_DESC=		PDO ODBC driver
PDO_PGSQL_DESC=		PDO PostgreSQL driver
PDO_SQLITE_DESC=	PDO sqlite driver
PGSQL_DESC=		PostgreSQL database support
PHAR_DESC=		phar support
POSIX_DESC=		POSIX-like functions
PSPELL_DESC=		pspell support
READLINE_DESC=		readline support (CLI only)
RECODE_DESC=		recode support
SESSION_DESC=		session support
SHMOP_DESC=		shmop support
SIMPLEXML_DESC=		simplexml support
SNMP_DESC=		SNMP support
SOAP_DESC=		SOAP support
SOCKETS_DESC=		sockets support
SQLITE3_DESC=		sqlite3 support
SYBASE_CT_DESC=		Sybase database support
SYSVMSG_DESC=		System V message support
SYSVSEM_DESC=		System V semaphore support
SYSVSHM_DESC=		System V shared memory support
TIDY_DESC=		TIDY support
TOKENIZER_DESC=		tokenizer support
WDDX_DESC=		WDDX support (implies XML)
XML_DESC=		XML support
XMLREADER_DESC=		XMLReader support
XMLRPC_DESC=		XMLRPC-EPI support
XMLWRITER_DESC=		XMLWriter support
XSL_DESC=		XSL support (Implies DOM)
ZIP_DESC=		ZIP support
ZLIB_DESC=		ZLIB support

OPTIONS_DEFAULT=	CTYPE \
			DOM \
			FILTER \
			HASH \
			ICONV \
			JSON \
			OPCACHE \
			PDO \
			PDO_SQLITE \
			PHAR \
			POSIX \
			SESSION \
			SIMPLEXML \
			SQLITE3 \
			TOKENIZER \
			XML \
			XMLREADER \
			XMLWRITER

.include <bsd.port.options.mk>

.for opt in ${OPTIONS_DEFINE}
.	if ${PORT_OPTIONS:M${opt}}
USE_PHP+=	${opt:tl}
.	endif
.endfor

.include <bsd.port.mk>
