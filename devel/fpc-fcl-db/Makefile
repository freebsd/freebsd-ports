# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-db

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Component Library

USE_FPC=	dblib fcl-async fcl-base fcl-json fcl-xml hash ibase mysql odbc oracle paszlib postgres \
		pthreads pxlib sqlite

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}
OPT=		-Fuunits/${BUILDNAME} -Fu../units/${BUILDNAME} -Fu../* \
		-Fu../../units/${BUILDNAME} -Fu../../../units/${BUILDNAME} \
		-Fu../sqldb/*

.include "${MASTERDIR}/Makefile"
