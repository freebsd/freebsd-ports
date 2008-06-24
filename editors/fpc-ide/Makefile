# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	editors lang
PKGNAMESUFFIX=	-ide

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal integrated IDE/compiler

USE_FPC=	gdbint graph ibase libasync hash mysql netdb odbc oracle pasjpeg \
		paszlib pthreads postgres regexpr sqlite fcl-base fv

UNITPREFIX=	# none
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR} ${FPCSRCDIR}/compiler ${FPCSRCDIR}/rtl ${FPCSRCDIR}/fv

.include "${MASTERDIR}/Makefile"
