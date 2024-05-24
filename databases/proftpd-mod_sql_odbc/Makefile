PORTNAME=	mod_sql_odbc
PORTREVISION=	1
CATEGORIES=	databases ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	ODBC ProFTPD module
WWW=		http://www.proftpd.org/docs/contrib/mod_sql.html

LICENSE=	GPLv2

LIB_DEPENDS=	libiodbc.so:databases/libiodbc

DESCR=		${.CURDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../../ftp/proftpd

USES=		cpe

CONFIGURE_ARGS=	LIBS=-liodbc \
		LD_LIBRARY_PATH="${LOCALBASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib"

INCLUDEDIRS=	${LOCALBASE}/include/libiodbc
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME}

.include "${MASTERDIR}/Makefile"
