# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	lang
PKGNAMESUFFIX=	-tcl

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal interface to the tcl/tk interpreter

USE_FPC=	fcl-base

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	TCL
TCL_DESC=	Install tool commnad language
OPTIONS_DEFAULT=	TCL

TCL_USES=	tk:84,run

.include "${MASTERDIR}/Makefile"
