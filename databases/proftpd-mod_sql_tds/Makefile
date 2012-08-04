# New ports collection makefile for:	proftpd-mod_sql_tds
# Date created:		17 July 2012
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mod_sql_tds
CATEGORIES=	databases ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	TDS ProFTPD module

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

LATEST_LINK=	${PKGNAMEPREFIX}-${PORTNAME}
MASTERDIR=	${.CURDIR}/../../ftp/proftpd

LIB_DEPENDS+=	sybdb.5:${PORTSDIR}/databases/freetds
_PROFTPD_MODULE_DISTFILES=	mod_sql_tds-4.13${EXTRACT_SUFX}:sql_tds
_PROFTPD_MODULE_EXTRACT_ONLY=	mod_sql_tds-4.13${EXTRACT_SUFX}

INCLUDEDIRS=	${LOCALBASE}/include
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME}

post-extract:
	@${MV} ${WRKDIR}/mod_sql_tds.c ${WRKSRC}/contrib

.include "${MASTERDIR}/Makefile"
