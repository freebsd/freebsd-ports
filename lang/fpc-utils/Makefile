# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	lang
PKGNAMESUFFIX=	-utils

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal Compiler utils

USE_FPC=	chm fcl-base fcl-net fcl-passrc fcl-process fcl-res fcl-xml fpmkunit fppkg libcurl paszlib

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}
OPT=		-Fu../fcl/*

.include "${MASTERDIR}/Makefile"
