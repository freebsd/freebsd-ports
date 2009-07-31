# New ports collection makefile for:	MySQL Workbench
# Date created:				26 June 2009
# Whom:					Maxim Ignatenko
#
# $FreeBSD$
#

PORTVERSION=	5.2.1
PORTREVISION=	1
PKGNAMESUFFIX=	52

MAINTAINER=	gelraen.ua@gmail.com

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3

MASTERDIR=	${.CURDIR}/../mysql-workbench51
MD5_FILE=	${.CURDIR}/distinfo
EXTRA_PATCHES=	${.CURDIR}/files/52-patch-frontend__linux__workbench__Makefile.am \
		${.CURDIR}/files/52-patch-configure.in \
		${.CURDIR}/files/52-patch-ext__ctemplate__ctemplate-src__configure.ac \
		${.CURDIR}/files/52-patch-modules__db__Makefile.am
PLIST=	${.CURDIR}/pkg-plist

CONFLICTS=	mysql-workbench-oss51*

.include "${MASTERDIR}/Makefile"
