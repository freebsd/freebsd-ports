# $FreeBSD$

PORTREVISION=	5
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-sdo

COMMENT=	Free Pascal Service Data Objects implementation (FCL)

USES=		fpc
USE_FPC=	dblib fcl-base fcl-db fcl-json fcl-xml ibase mysql odbc \
		oracle postgres pxlib rtl-extra sqlite

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
