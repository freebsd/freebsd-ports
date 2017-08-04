# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-pdf

COMMENT=	Free Pascal pdf (FCL)

USE_FPC=	fcl-base fcl-image fcl-res pasjpeg rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
