# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-net

COMMENT=	Free Pascal network interfaces (FCL)

USES=		fpc
USE_FPC=	fcl-base fcl-xml fcl-passrc fcl-async rtl-extra

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
