# New ports collection makefile for:	php4-extensions
# Date created:			7 Jul 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	php4
PORTVERSION=	1.0
CATEGORIES=	lang
MASTER_SITES=	# none
PKGNAMESUFFIX=	-extensions
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A "meta-port" to install PHP extensions

DEFAULT_PHP_VER=4
IGNORE_WITH_PHP=5
USE_PHP_BUILD=	yes

NO_BUILD=	yes

WITH_CTYPE=	yes
WITH_MYSQL=	yes
WITH_OVERLOAD=	yes
WITH_PCRE=	yes
WITH_POSIX=	yes
WITH_SESSION=	yes
WITH_TOKENIZER=	yes
WITH_XML=	yes
WITH_ZLIB=	yes

OPTIONS=	BCMATH          "bc style precision math functions" off \
		BZ2             "bzip2 library support" off \
		CALENDAR        "calendar conversion support" off \
		CRACK           "crack support" off \
		CTYPE           "ctype functions" on \
		CURL            "CURL support" off \
		DBA             "dba support" off \
		DBASE           "dBase library support" off \
		DBX             "dbx support" off \
		DIO             "Direct I/O support" off \
		DOMXML          "DOM support" off \
		EXIF            "EXIF support" off \
		FILEINFO        "fileinfo support" off \
		FILEPRO         "filePro support" off \
		FRIBIDI         "FriBidi support" off \
		FTP             "FTP support" off \
		GD              "GD library support" off \
		GETTEXT         "gettext library support" off \
		GMP             "GNU MP support" off \
		ICONV           "iconv support" off \
		IMAP            "IMAP support" off \
		INTERBASE       "Interbase 6 database support (Firebird)" off \
		LDAP            "OpenLDAP support" off \
		MBSTRING        "multibyte string support" off \
		MCAL            "Modular Calendar Access Library support" off \
		MCRYPT          "Encryption support" off \
		MCVE            "MCVE support" off \
		MHASH           "Crypto-hashing support" off \
		MSSQL           "MS-SQL database support" off \
		MYSQL           "MySQL database support" on \
		NCURSES         "ncurses support (CLI only)" off \
		ODBC            "unixODBC support" off \
		OPENSSL         "OpenSSL support" off \
		ORACLE          "Oracle support" off \
		OVERLOAD        "user-space object overloading support" on \
		PCNTL           "pcntl support (CLI only)" off \
		PCRE            "Perl Compatible Regular Expression support" on \
		PDF             "PDFlib support (implies GD)" off \
		PFPRO		"PayFlow Pro support" off \
		PGSQL           "PostgreSQL database support" off \
		POSIX           "POSIX-like functions" on \
		PSPELL          "pspell support" off \
		READLINE        "readline support (CLI only)" off \
		RECODE          "recode support" off \
		SESSION         "session support" on \
		SHMOP           "shmop support" off \
		SNMP            "SNMP support" off \
		SOCKETS         "sockets support" off \
		SYBASE_CT       "Sybase database support" off \
		SYSVMSG         "System V message support" off \
		SYSVSEM         "System V semaphore support" off \
		SYSVSHM         "System V shared memory support" off \
		TOKENIZER       "tokenizer support" on \
		WDDX            "WDDX support (implies XML)" off \
		XML             "XML support" on \
		XMLRPC          "XMLRPC-EPI support" off \
		XSLT            "XSLT Sablotron support" off \
		YAZ             "YAZ support (ANSI/NISO Z39.50)" off \
		YP              "YP/NIS support" off \
		ZIP             "ZIP support" off \
		ZLIB            "ZLIB support" on

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

ALL_OPTIONS=	BCMATH BZ2 CALENDAR CRACK CTYPE CURL DBA DBASE DBX DIO \
		DOMXML EXIF FILEINFO FILEPRO FRIBIDI FTP GD GETTEXT \
		GMP ICONV IMAP INTERBASE LDAP MBSTRING MCAL MCRYPT \
		MCVE MHASH MIME_MAGIC MSSQL MYSQL NCURSES \
		ODBC OPENSSL ORACLE OVERLOAD PCNTL PCRE PDF PFPRO \
		PGSQL POSIX PSPELL READLINE RECODE SESSION SHMOP SNMP SOCKETS \
		SYBASE_CT SYSVMSG SYSVSEM SYSVSHM TOKENIZER \
		WDDX XML XMLRPC XSLT YAZ YP ZIP ZLIB

SEL_OPTIONS=	yes
.for opt in ${ALL_OPTIONS}
.	if defined(WITH_${opt}) && !defined(WITHOUT_${opt})
SEL_OPTIONS+=	${opt:L}
.	endif
.endfor
USE_PHP=	${SEL_OPTIONS}

do-install: build
	@${DO_NADA}

.include <bsd.port.mk>
