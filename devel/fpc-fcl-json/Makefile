# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-json

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal JavaScript Object Notation implemenation (FCL)

USE_FPC=	fcl-base rtl-objpas fcl-res

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
