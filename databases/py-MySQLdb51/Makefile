# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PKGNAMESUFFIX=	51

COMMENT=	Access a MySQL database through Python (Using MySQL 5.1 Client)

CONFLICTS=	py*-MySQLdb-devel-[0-9]* py*-MySQLdb-[0-9]* py*-MySQLdb[45][0-9]-[0-9]*

WANT_MYSQL_VER=	51

MASTERDIR=	${.CURDIR}/../py-MySQLdb

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
