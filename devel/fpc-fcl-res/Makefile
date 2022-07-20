CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-res

COMMENT=	Free Pascal resource handlers (FCL)

USES=		fpc
USE_FPC=	rtl-objpas fcl-base tplylib

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
