# $FreeBSD$

PORTREVISION=	4
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-passrc

COMMENT=	Free Pascal language parsing library (FPC)

USES=		fpc
USE_FPC=	fcl-base fcl-res rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
