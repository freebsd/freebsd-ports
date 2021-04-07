PORTREVISION=	2
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-db

COMMENT=	Free Pascal Database Library (FCL)

USES=		fpc
USE_FPC=	fcl-base fcl-xml rtl-objpas rtl-extra ibase mysql odbc \
		oracle postgres sqlite dblib pxlib fcl-json

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
