# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-xml

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal XML and DOM library (FCL)

USE_FPC=	fcl-base fcl-res rtl-objpas iconvenc
USE_FPC_RUN=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
