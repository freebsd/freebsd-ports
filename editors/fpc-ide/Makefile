# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	editors lang
PKGNAMESUFFIX=	-ide

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal integrated IDE/compiler

USE_FPC=	chm fcl-async fcl-base fv gdbint graph ibase hash mysql odbc \
		oracle pasjpeg paszlib pthreads postgres regexpr sqlite

UNITPREFIX=	# none
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR} ${FPCSRCDIR}/compiler ${FPCSRCDIR}/rtl ${FPCSRCDIR}/packages/fv

.include "${MASTERDIR}/Makefile"
