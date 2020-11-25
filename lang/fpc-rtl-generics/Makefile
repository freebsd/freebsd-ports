# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	lang
PKGNAMESUFFIX=	-rtl-generics

COMMENT=	Free Pascal generics unit

USES=		fpc
USE_FPC=	rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
