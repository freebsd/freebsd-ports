# $FreeBSD$

PORTNAME=	sqliteodbc
CATEGORIES=	databases
PKGNAMESUFFIX=	-sqlite2

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	ODBC driver for SQLite 2

MASTERDIR=	${.CURDIR}/../sqliteodbc

DEPRECATED=	SQLite2 has stopped development in 2005, please move to SQLite3
EXPIRATION_DATE=	2020-07-27

BROKEN_aarch64=	fails to compile: error: passing char * to parameter of incompatible type va_list
BROKEN_armv6=	fails to compile: error: passing char * to parameter of incompatible type va_list
BROKEN_armv7=	fails to compile: error: passing char * to parameter of incompatible type va_list

.include "${MASTERDIR}/Makefile"
