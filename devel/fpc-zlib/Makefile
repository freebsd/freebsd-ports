# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-zlib

COMMENT=	Free Pascal interface to the zlib compression library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
