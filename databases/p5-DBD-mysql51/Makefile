# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	51

COMMENT=	MySQL 5.1 driver for the Perl5 Database Interface (DBI)

DEPRECATED=	EOL upstream, use databases/p5-DBD-mysql instead
EXPIRATION_DATE=	2015-11-10

CONFLICTS_INSTALL=	p5-DBD-mysql-[0-9]* p5-DBD-mysql5[02-9]-[0-9]*

WANT_MYSQL_VER=	51

MASTERDIR=	${.CURDIR}/../p5-DBD-mysql

.include "${MASTERDIR}/Makefile"
