# $FreeBSD$

CATEGORIES=	lang
PKGNAMESUFFIX=	-pastojs

COMMENT=	Pascal to javascript transpiler

USES=		fpc
USE_FPC=	fcl-base fcl-js fcl-json fcl-passrc fcl-res rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
