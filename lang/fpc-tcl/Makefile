# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	lang
PKGNAMESUFFIX=	-tcl

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the tcl/tk interpreter

USE_FPC=	fcl-base

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	TCL
TCL_DESC=	Install tool commnad language
OPTIONS_DEFAULT=	TCL

.include "${MASTERDIR}/Makefile"
