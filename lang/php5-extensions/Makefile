# New ports collection makefile for:	php5-extensions
# Date created:			7 Jul 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	php5
PORTVERSION=	1.0
CATEGORIES=	lang
MASTER_SITES=	# none
PKGNAMESUFFIX=	-extensions
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A "meta-port" to install PHP extensions

NO_BUILD=	# none

DEFAULT_PHP_VER=5
BROKEN_WITH_PHP=4

WITH_CTYPE=	yes
WITH_DOM=	yes
WITH_ICONV=	yes
WITH_PCRE=	yes
WITH_POSIX=	yes
WITH_SESSION=	yes
WITH_SIMPLEXML=	yes
WITH_SQLITE=	yes
WITH_TOKENIZER=	yes
WITH_XML=	yes

OPTIONS=	BCMATH          "bc style precision math functions" off \
		BZ2             "bzip2 library support" off \
		CALENDAR        "calendar conversion support" off \
		CTYPE           "ctype functions" on \
		CURL            "CURL support" off \
		DBA             "dba support" off \
		DBASE           "dBase library support" off \
		DBX             "dbx support" off \
		DIO             "Direct I/O support" off \
		DOM             "DOM support" on \
		EXIF            "EXIF support" off \
		FILEINFO        "fileinfo support" off \
		FILEPRO         "filePro support" off \
		FRIBIDI         "FriBidi support" off \
		FTP             "FTP support" off \
		GD              "GD library support" off \
		GETTEXT         "gettext library support" off \
		GMP             "GNU MP support" off \
		ICONV           "iconv support" on \
		IMAGICK         "ImageMagick support" off \
		IMAP            "IMAP support" off \
		INTERBASE       "Interbase 6 database support (Firebird)" off \
		LDAP            "OpenLDAP support" off \
		MBSTRING        "multibyte string support" off \
		MCRYPT          "Encryption support" off \
		MCVE            "MCVE support" off \
		MHASH           "Crypto-hashing support" off \
		MING            "ming shockwave flash support" off \
		MNOGOSEARCH     "mnoGoSearch support" off \
		MSSQL           "MS-SQL database support" off \
		MYSQL           "MySQL database support" off \
		MYSQLI          "MySQLi database support" off \
		NCURSES         "ncurses support (CLI only)" off \
		ODBC            "unixODBC support" off \
		OPENSSL         "OpenSSL support" off \
		ORACLE          "Oracle support" off \
		PANDA           "panda support" off \
		PCNTL           "pcntl support (CLI only)" off \
		PCRE            "Perl Compatible Regular Expression support" on \
		PDF             "PDFlib support (implies GD)" off \
		PGSQL           "PostgreSQL database support" off \
		POSIX           "POSIX-like functions" on \
		PSPELL          "pspell support" off \
		READLINE        "readline support (CLI only)" off \
		RECODE          "recode support" off \
		SESSION         "session support" on \
		SHMOP           "shmop support" off \
		SIMPLEXML       "simplexml support" on \
		SNMP            "SNMP support" off \
		SOAP            "SOAP support" off \
		SOCKETS         "sockets support" off \
		SQLITE          "sqlite support" on \
		SYBASE_CT       "Sybase database support" off \
		SYSVMSG         "System V message support" off \
		SYSVSEM         "System V semaphore support" off \
		SYSVSHM         "System V shared memory support" off \
		TIDY            "TIDY support" off \
		TOKENIZER       "tokenizer support" on \
		WDDX            "WDDX support (implies XML)" off \
		XML             "XML support" on \
		XMLRPC          "XMLRPC-EPI support" off \
		XSL             "XSL support (Implies DOM)" off \
		YAZ             "YAZ support (ANSI/NISO Z39.50)" off \
		YP              "YP/NIS support" off \
		ZIP             "ZIP support" off \
		ZLIB            "ZLIB support" off

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

ALL_OPTIONS=	BCMATH BZ2 CALENDAR CTYPE CURL DBA DBASE DBX DIO \
		DOM EXIF FILEINFO FILEPRO FRIBIDI FTP GD GETTEXT \
		GMP ICONV IMAGICK IMAP INTERBASE LDAP MBSTRING MCRYPT \
		MCVE MHASH MIME_MAGIC MING MNOGOSEARCH MSSQL MYSQL MYSQLI \
		NCURSES ODBC OPENSSL ORACLE PANDA PCNTL PCRE PDF PGSQL POSIX \
		PSPELL READLINE RECODE SESSION SHMOP SIMPLEXML SNMP SOAP \
		SOCKETS SQLITE SYBASE_CT SYSVMSG SYSVSEM SYSVSHM \
		TIDY TOKENIZER WDDX XML XMLRPC XSL YAZ YP ZIP ZLIB

SEL_OPTIONS=	yes
.for opt in ${ALL_OPTIONS}
.	if defined(WITH_${opt}) && !defined(WITHOUT_${opt})
SEL_OPTIONS+=	${opt:L}
.	endif
.endfor
USE_PHP=	${SEL_OPTIONS}

do-build:
	@${DO_NADA}

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
