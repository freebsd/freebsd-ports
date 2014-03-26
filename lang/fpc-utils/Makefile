# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	lang
PKGNAMESUFFIX=	-utils

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Compiler utils

USE_FPC=	chm fcl-base fcl-net fcl-passrc fcl-process fcl-res fppkg libcurl

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}
OPT=		-Fu../fcl/*

.include "${MASTERDIR}/Makefile"
