# $FreeBSD$

PORTREVISION=	5
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-js

COMMENT=	Free Pascal Javascript scanner/parser/syntax tree (FCL)

USES=		fpc
USE_FPC=	fcl-base fcl-res rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
