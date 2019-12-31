# $FreeBSD$

PORTREVISION=	5
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-fpindexer

COMMENT=	Database indexer with database/flat file backend

USES=		fpc
USE_FPC=	chm dblib fcl-base fcl-db fcl-json fcl-xml ibase mysql odbc \
		oracle postgres pxlib sqlite rtl-extra

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
