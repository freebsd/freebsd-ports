# $FreeBSD$

PORTREVISION=	4
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-pdf

COMMENT=	Free Pascal pdf (FCL)

USES=		fpc
USE_FPC=	fcl-base fcl-image fcl-res fcl-xml pasjpeg rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
