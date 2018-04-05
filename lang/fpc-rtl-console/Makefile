# $FreeBSD$

CATEGORIES=	lang
PKGNAMESUFFIX=	-rtl-console

COMMENT=	Free Pascal console abstraction unit (RTL)

USES=		fpc
USE_FPC=	rtl-extra

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
