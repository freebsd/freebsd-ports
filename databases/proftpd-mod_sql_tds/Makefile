# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_sql_tds
DISTVERSION=	4.13
PORTREVISION=	1
CATEGORIES=	databases ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	TDS ProFTPD module

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../../ftp/proftpd

LIB_DEPENDS+=	libsybdb.so.5:databases/freetds
_PROFTPD_MODULE_DISTFILES=	mod_sql_tds-4.13${EXTRACT_SUFX}:sql_tds
_PROFTPD_MODULE_EXTRACT_ONLY=	mod_sql_tds-4.13${EXTRACT_SUFX}
_PROFTPD_MODULE_MASTER_SITES=	http://labratsoftware.com/mod_sql_tds/:sql_tds \
		                LOCAL/beech:sql_tds

INCLUDEDIRS=	${LOCALBASE}/include
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME}

post-extract:
	@${MV} ${WRKDIR}/mod_sql_tds.c ${WRKSRC}/contrib

post-patch:
	@${REINPLACE_CMD} -e 's| ERROR_MSG| PR_ERROR_MSG|g' \
		-e 's| HANDLED| PR_HANDLED|g' \
		${WRKSRC}/contrib/mod_sql_tds.c

.include "${MASTERDIR}/Makefile"
