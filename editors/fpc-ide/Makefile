# Created by: John Merryweather Cooper et al
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	editors lang
PKGNAMESUFFIX=	-ide

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal integrated IDE/compiler

USE_FPC=	chm fcl-async fcl-base fv gdbint graph ibase hash mysql odbc \
		oracle pasjpeg paszlib pthreads postgres regexpr sqlite

FPCDIR=		# none
UNITPREFIX=	# none
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR} ${FPCSRCDIR}/compiler ${FPCSRCDIR}/rtl ${FPCSRCDIR}/packages/fv

.include "${MASTERDIR}/Makefile"
