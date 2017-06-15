# $FreeBSD$

PORTNAME=	sqliteodbc
CATEGORIES=	databases
PKGNAMESUFFIX=	-sqlite2

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	ODBC driver for SQLite 2

MASTERDIR=      ${.CURDIR}/../sqliteodbc

BROKEN_aarch64=		Fails to compile: error: passing char * to parameter of incompatible type va_list

.include "${MASTERDIR}/Makefile"
