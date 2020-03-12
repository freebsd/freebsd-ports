# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mysql
PORTREVISION=	1
PKGNAMESUFFIX=	56-client

COMMENT=	Multithreaded SQL database (client)

LICENSE+=	LGPL21

BROKEN_sparc64=	Does not build: reports unsupported compiler

MASTERDIR=	${.CURDIR}/../mysql56-server

PKGMESSAGE=	${.CURDIR}/pkg-message
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS_INSTALL=	mysql5[0-57-9]-client-* \
			mysql[0-46-9][0-9]-client-* \
			mariadb[0-9][0-9]-client-* \
			percona[0-9][0-9]-client-*

CMAKE_ARGS+=	-DWITHOUT_SERVER=1

USE_LDCONFIG+=	${PREFIX}/lib/mysql

MMAN1=		comp_err.1 msql2mysql.1 mysql.1 mysql_config.1 mysql_config_editor.1 mysql_find_rows.1 \
		mysql_waitpid.1 mysqlaccess.1 mysqladmin.1 mysqlbinlog.1 \
		mysqlcheck.1 mysqldump.1 mysqlimport.1 mysqlshow.1 mysqlslap.1

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"
