# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-dblib

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal DB-Library and FreeTDS unit

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
