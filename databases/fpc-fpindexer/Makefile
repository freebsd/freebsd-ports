# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-fpindexer

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Database indexer with database/flat file backend

USE_FPC=	chm fcl-base fcl-db fcl-xml ibase sqlite

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
