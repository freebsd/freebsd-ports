# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-pthreads

COMMENT=	Free Pascal wrapper for the pthreads library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
