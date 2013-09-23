# Created by: Alex Keda <admin@lissyara.su>
# $FreeBSD$

PORTNAME=	php52
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	# none
PKGNAMESUFFIX=	-extensions
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	admin@lissyara.su
COMMENT=	A "meta-port" to install PHP extensions

DEFAULT_PHP_VER=52
IGNORE_WITH_PHP=5 53
USE_PHP_BUILD=	yes

NO_BUILD=	yes

OPTIONS_DEFINE=	BCMATH BZ2 CALENDAR CTYPE CURL DBA DBASE DOM EXIF FILEINFO \
		FILTER FTP GD GETTEXT GMP HASH ICONV IMAP INTERBASE JSON LDAP \
		MBSTRING MCRYPT MHASH MING MSSQL MYSQL MYSQLI NCURSES ODBC \
		OPENSSL PCNTL PCRE PDF PDO PDO_SQLITE PDO_MYSQL PGSQL POSIX \
		PSPELL READLINE RECODE SESSION SHMOP SIMPLEXML SNMP SOAP SOCKETS \
		SPL SQLITE SYBASE_CT SYSVMSH SYSVSEM SYSVSHM TIDY TOKENIZER \
		WDDX XML XMLREADER XMLRPC XMLWRITER XSL ZIP ZLIB
OPTIONS_DEFAULT=	CTYPE DOM FILTER HASH ICONV JSON PCRE PDO PDO_SQLITE \
			PDO_MYSQL POSIX SESSION SIMPLEXML SPL SQLITE TOKENIZER \
			XML XMLREADER XMLWRITER
BCMATH_DESC=		bc style precision math functions
BZ2_DESC=		bzip2 library support
CALENDAR_DESC=		calendar conversion support
CTYPE_DESC=		ctype functions
DBA_DESC=		dba support
DBASE_DESC=		dBase library support
DOM_DESC=		DOM support
EXIF_DESC=		EXIF support
FILEINFO_DESC=		fileinfo support
FILTER_DESC=		input filter support
GETTEXT_DESC=		gettext library support
HASH_DESC=		HASH Message Digest Framework
IMAP_DESC=		IMAP support
INTERBASE_DESC=		Interbase 6 database support (Firebird)
MBSTRING_DESC=		multibyte string support
MCRYPT_DESC=		Encryption support
MHASH_DESC=		Crypto-hashing support
MING_DESC=		ming shockwave flash support
MYSQLI_DESC=		MySQLi database support
NCURSES_DESC=		ncurses support (CLI only)
ODBC_DESC=		unixODBC support
PCNTL_DESC=		pcntl support (CLI only)
PDF_DESC=		PDFlib support (implies GD)
PDO_DESC=		PHP Data Objects Interface (PDO)
PDO_SQLITE_DESC=	PDO sqlite driver
PDO_MYSQL_DESC=		PDO mysql driver
POSIX_DESC=		POSIX-like functions
PSPELL_DESC=		pspell support
READLINE_DESC=		readline support (CLI only)
RECODE_DESC=		recode support
SESSION_DESC=		session support
SHMOP_DESC=		shmop support
SIMPLEXML_DESC=		simplexml support
SOAP_DESC=		SOAP support
SOCKETS_DESC=		sockets support
SPL_DESC=		Standard PHP Library
SYBASE_CT_DESC=		Sybase database support
SYSVMSG_DESC=		System V message support
SYSVSEM_DESC=		System V semaphore support
SYSVSHM_DESC=		System V shared memory support
TIDY_DESC=		TIDY support
TOKENIZER_DESC=		tokenizer support
WDDX_DESC=		WDDX support (implies XML)
XMLREADER_DESC=		XMLReader support
XMLRPC_DESC=		XMLRPC-EPI support
XMLWRITER_DESC=		XMLWriter support
XSL_DESC=		XSL support (Implies DOM)
ZIP_DESC=		ZIP support

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

.for opt in ${OPTIONS_DEFINE}
.	if ${PORT_OPTIONS:M${opt}}
USE_PHP+=	${opt:L}
.	endif
.endfor

do-install: build
	@${DO_NADA}

.include <bsd.port.mk>
