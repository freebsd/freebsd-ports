# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_sql_postgres
CATEGORIES=	databases ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	PostgreSQL ProFTPD module

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

LATEST_LINK=	${PKGNAMEPREFIX}-${PORTNAME}
MASTERDIR=	${.CURDIR}/../../ftp/proftpd

USE_PGSQL=	yes

INCLUDEDIRS=	${LOCALBASE}/include
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME}

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
