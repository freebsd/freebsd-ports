# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_sql_mysql
CATEGORIES=	databases ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	MySQL ProFTPD module

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

LATEST_LINK=	${PKGNAMEPREFIX}-${PORTNAME}
MASTERDIR=	${.CURDIR}/../../ftp/proftpd

USE_MYSQL=	yes

INCLUDEDIRS=	${LOCALBASE}/include:${LOCALBASE}/include/mysql
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME}

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
