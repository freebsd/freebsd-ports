#!/bin/sh
# $FreeBSD$

if [ -f ${WRKDIR}/Makefile.inc ]; then
	exit
fi

tempfile=`/usr/bin/mktemp -t checklist`

if [ "${BATCH}" ]; then
	echo "${SEL_OPTIONS}" > $tempfile
else
	if [ -f "${OPTION_FILE}" ]; then
		for i in `${CAT} ${OPTION_FILE}`
		do
			export $i
		done
	fi
	/usr/bin/dialog --title "configuration options" --clear --checklist "\n\
Please select desired options:" -1 -1 16 \
BCMATH		"bc style precision math functions" ${WITH_BCMATH:-OFF} \
BZIP2		"bzip2 library support" ${WITH_BZIP2:-OFF} \
CALENDAR	"calendar conversion support" ${WITH_CALENDAR:-OFF} \
CDB		"cdb database support (dba)" ${WITH_CDB:-OFF} \
CRACK		"crack support" ${WITH_CRACK:-OFF} \
CTYPE		"ctype functions" ${WITH_CTYPE:-OFF} \
CURL		"CURL support" ${WITH_CURL:-OFF} \
DB4		"Berkeley DB4 support" ${WITH_DB4:-OFF} \
DBASE		"dBase library support" ${WITH_DBASE:-OFF} \
DBX		"dbx support" ${WITH_DBX:-OFF} \
DIO		"Direct I/O support" ${WITH_DIO:-OFF} \
DOM		"DOM support" ${WITH_DOM:-OFF} \
EXIF		"EXIF support" ${WITH_EXIF:-OFF} \
FILEPRO		"filePro support" ${WITH_FILEPRO:-OFF} \
FTP		"FTP support" ${WITH_FTP:-OFF} \
GD		"GD library support" ${WITH_GD:-OFF} \
GDBM		"GDBM database support (dba)" ${WITH_GDBM:-OFF} \
GETTEXT		"gettext library support" ${WITH_GETTEXT:-OFF} \
GMP		"GNU MP support" ${WITH_GMP:-OFF} \
ICONV		"iconv support" ${WITH_ICONV:-ON} \
IMAP		"IMAP support" ${WITH_IMAP:-OFF} \
INIFILE		"INI file support (dba)" ${WITH_INIFILE:-OFF} \
INTERBASE	"Interbase 6 database support (Firebird)" ${WITH_INTERBASE:-OFF} \
MBSTRING	"multibyte string support" ${WITH_MBSTRING:-OFF} \
MCVE		"MCVE support (implies OPENSSL)" ${WITH_MCVE:-OFF} \
MCRYPT		"Encryption support" ${WITH_MCRYPT:-OFF} \
MHASH		"Crypto-hashing support" ${WITH_MHASH:-OFF} \
MING		"ming shockwave flash support" ${WITH_MING:-OFF} \
MNOGOSEARCH	"mnoGoSearch support" ${WITH_MNOGOSEARCH:-OFF} \
MSSQL		"MS-SQL database support" ${WITH_MSSQL:-OFF} \
MYSQL		"MySQL database support" ${WITH_MYSQL:-OFF} \
MYSQLI		"MySQLi database support" ${WITH_MYSQLI:-OFF} \
NCURSES		"ncurses support (CLI only)" ${WITH_NCURSES:-OFF} \
OPENLDAP	"OpenLDAP support" ${WITH_OPENLDAP:-OFF} \
OPENSSL		"OpenSSL support" ${WITH_OPENSSL:-OFF} \
ORACLE		"Oracle support" ${WITH_ORACLE:-OFF} \
PCNTL		"pcntl support (CLI only)" ${WITH_PCNTL:-OFF} \
PCRE		"Perl Compatible Regular Expression support" ${WITH_PCRE:-OFF} \
POSIX		"POSIX-like functions" ${WITH_POSIX:-OFF} \
POSTGRESQL	"PostgreSQL database support" ${WITH_POSTGRESQL:-OFF} \
PSPELL		"pspell support" ${WITH_PSPELL:-OFF} \
READLINE	"readline support (CLI only)" ${WITH_READLINE:-OFF} \
RECODE		"recode support" ${WITH_RECODE:-OFF} \
SESSION		"session support" ${WITH_SESSION:-OFF} \
SHMOP		"shmop support" ${WITH_SHMOP:-OFF} \
SIMPLEXML	"simplexml support" ${WITH_SIMPLEXML:-OFF} \
SNMP		"SNMP support (implies OPENSSL)" ${WITH_SNMP:-OFF} \
SOAP		"SOAP support" ${WITH_SOAP:-OFF} \
SOCKETS		"sockets support" ${WITH_SOCKETS:-OFF} \
SPL		"Standard PHP Library support" ${WITH_SPL:-ON} \
SQLITE		"sqlite support" ${WITH_SQLITE:-OFF} \
SYBASEDB	"Sybase database support (DB-lib)" ${WITH_SYBASEDB:-OFF} \
SYBASECT	"Sybase database support (CT-lib)" ${WITH_SYBASECT:-OFF} \
SYSVMSG		"System V message support" ${WITH_SYSVMSG:-OFF} \
SYSVSEM		"System V semaphore support" ${WITH_SYSVSEM:-OFF} \
SYSVSHM		"System V shared memory support" ${WITH_SYSVSHM:-OFF} \
TIDY		"TIDY support" ${WITH_TIDY:-OFF} \
TOKENIZER	"tokenizer support" ${WITH_TOKENIZER:-OFF} \
UNIXODBC	"unixODBC support" ${WITH_UNIXODBC:-OFF} \
WDDX		"WDDX support (implies XML)" ${WITH_WDDX:-OFF} \
XML		"XML support" ${WITH_XML:-OFF} \
XMLRPC		"XMLRPC-EPI support (implies ICONV)" ${WITH_XMLRPC:-OFF} \
XSL		"XSL support" ${WITH_XSL:-OFF} \
YP		"YP/NIS support" ${WITH_YP:-OFF} \
ZLIB		"ZLIB support" ${WITH_ZLIB:-OFF} \
2> $tempfile
fi

retval=$?

if [ -s $tempfile ]; then
	set `${CAT} $tempfile | ${SED} 's|"||g'`
fi
rm -f $tempfile

case $retval in
	0)	if [ -z "$*" ]; then
			echo "Nothing selected"
		fi
		;;
	1)	echo "Cancel pressed."
		exit 1
		;;
esac
exec > ${WRKDIR}/Makefile.inc
while [ $1 ]; do
	echo "WITH_$1=yes";
	shift
done
