# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-base

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Component Library

USE_FPC=	hash paszlib pthreads

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
