# New ports collection makefile for:	fpc-tcl
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	lang
PKGNAMESUFFIX=	-tcl

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the tcl/tk interpreter

USE_FPC=	fcl-base

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	TCL	"Install tool commnad language"	on

.include "${MASTERDIR}/Makefile"
