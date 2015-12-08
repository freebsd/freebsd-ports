# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-extra

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal extra libraries (FCL)

USE_FPC=	fcl-base fcl-res rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
