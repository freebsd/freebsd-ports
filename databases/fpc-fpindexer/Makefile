# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-fpindexer

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Database indexer with database/flat file backend

USE_FPC=	chm dblib fcl-base fcl-db fcl-json fcl-xml ibase mysql odbc \
		oracle postgres pxlib sqlite rtl-extra

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
