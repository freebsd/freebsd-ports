# New ports collection makefile for:	fpc-tcl
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	lang
PKGNAMESUFFIX=	-tcl

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the tcl/tk interpreter

USE_FPC=	fcl-base gdbint graph ibase libasync hash mysql netdb odbc \
		oracle pasjpeg paszlib pthreads postgres regexpr sqlite

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	TCL	"Install tool commnad language"	on

.include "${MASTERDIR}/Makefile"
