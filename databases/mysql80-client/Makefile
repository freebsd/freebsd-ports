# Created by: "Mahdi Mokhtari <mokhi64@gmail.com>"
# $FreeBSD$

PORTNAME=	mysql
PORTREVISION=	0
PKGNAMESUFFIX=	80-client

COMMENT=	Multithreaded SQL database (client)

LICENSE+=	LGPL21

MASTERDIR=	${.CURDIR}/../mysql80-server

PKGMESSAGE=	${.CURDIR}/pkg-message
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS_INSTALL=	mysql8[1-9]-client-* \
			mysql[0-79][0-9]-client-* \
			mariadb[0-9][0-9]-client-* \
			percona[0-9][0-9]-client-*

CMAKE_ARGS+=	-DWITHOUT_SERVER=1 -DINSTALL_SUPPORTFILESDIR=0

USE_LDCONFIG+=	${PREFIX}/lib/mysql

MMAN1=		comp_err.1 msql2mysql.1 mysql.1 mysql_config.1 mysql_config_editor.1 mysql_find_rows.1 \
		mysql_waitpid.1 mysqlaccess.1 mysqladmin.1 mysqlbinlog.1 \
		mysqlcheck.1 mysqldump.1 mysqlimport.1 mysqlshow.1 mysqlslap.1

CLIENT_ONLY=	yes

# issue 166367: adding symlinks for back-compatibility with ${lib}_r
post-install:
	@${LN} -s libmysqlclient.a ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient_r.a
	@${LN} -s libmysqlclient.so ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient_r.so
	@${LN} -s libmysqlclient.so.21 ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient_r.so.21

.include "${MASTERDIR}/Makefile"
