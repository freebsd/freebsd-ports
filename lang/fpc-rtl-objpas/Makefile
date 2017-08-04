# $FreeBSD$

CATEGORIES=	lang
PKGNAMESUFFIX=	-rtl-objpas

COMMENT=	Free Pascal compatibility unit with Delphi

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
