# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-json
PORTREVISION=	1

COMMENT=	Free Pascal JavaScript Object Notation implemenation (FCL)

USES=		fpc
USE_FPC=	fcl-base rtl-objpas fcl-res

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
