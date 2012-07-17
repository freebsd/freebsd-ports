# New ports collection makefile for:	proftpd-mod_sql_odbc
# Date created:		17 July 2012
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mod_sql_odbc
CATEGORIES=	databases ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	ODBC ProFTPD module

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

LATEST_LINK=	${PKGNAMEPREFIX}-${PORTNAME}
MASTERDIR=	${.CURDIR}/../../ftp/proftpd

LIB_DEPENDS=	iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS=	LIBS=-liodbc \
		LD_LIBRARY_PATH="${LOCALBASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib"

INCLUDEDIRS=	${LOCALBASE}/include
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME}

.include "${MASTERDIR}/Makefile"
