PORTNAME=	mod_sql_mysql
PORTREVISION=	1
CATEGORIES=	databases ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	MySQL ProFTPD module
WWW=		http://www.proftpd.org/docs/contrib/mod_sql.html

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../../ftp/proftpd

USES=		cpe mysql

INCLUDEDIRS=	${LOCALBASE}/include:${LOCALBASE}/include/mysql
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME}

.include "${MASTERDIR}/Makefile"
