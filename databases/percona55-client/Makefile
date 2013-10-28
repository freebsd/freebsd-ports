# $FreeBSD$

PORTNAME=	percona
PKGNAMESUFFIX=	55-client

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../percona55-server

PKGMESSAGE=	mustnotexist
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS_INSTALL=	mysql[0-9][0-9]-client-* mariadb[0-9][0-9]-client-* percona5.[0-46-9]-client-* percona[0-46-9][0-9]-client-*

CMAKE_ARGS+=	-DWITHOUT_SERVER=1

USE_LDCONFIG=	${PREFIX}/lib/mysql

MANPAGES=	comp_err.1 msql2mysql.1 mysql.1 mysql_config.1 mysql_find_rows.1 \
		mysql_waitpid.1 mysqlaccess.1 mysqladmin.1 mysqlbinlog.1 \
		mysqlcheck.1 mysqldump.1 mysqlimport.1 mysqlshow.1 mysqlslap.1

CLIENT_ONLY=	yes

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
