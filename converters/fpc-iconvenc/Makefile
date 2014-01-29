# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	converters lang
PKGNAMESUFFIX=	-iconvenc

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit to iconv library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

# added to main port to make it compile on 10 with iconv in libc
#USES=	iconv

.include "${MASTERDIR}/Makefile"
