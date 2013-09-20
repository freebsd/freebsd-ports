# Created by: John Merryweather Cooper et al
# $FreeBSD$

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

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
