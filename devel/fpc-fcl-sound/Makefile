# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-sound

COMMENT=	Free Pascal sound loading, storing and converion (FCL)

USE_FPC=	fcl-base fcl-res rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
