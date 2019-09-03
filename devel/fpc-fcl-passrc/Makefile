# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-passrc
PORTREVISION=	3

COMMENT=	Free Pascal language parsing library (FPC)

USES=		fpc
USE_FPC=	fcl-base fcl-res rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
