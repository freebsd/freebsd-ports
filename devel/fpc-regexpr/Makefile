CATEGORIES=	devel lang
PKGNAMESUFFIX=	-regexpr

COMMENT=	Free Pascal regular expression routines

USES=		fpc
USE_FPC=	rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
