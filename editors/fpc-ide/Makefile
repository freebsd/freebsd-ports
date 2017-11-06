# Created by: John Merryweather Cooper et al
# $FreeBSD$

CATEGORIES=	editors lang
PKGNAMESUFFIX=	-ide

COMMENT=	Free Pascal integrated IDE/compiler

USE_FPC=	chm fv gdbint regexpr rtl-extra rtl-console fcl-xml

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR} ${FPCSRCDIR}/rtl ${FPCSRCDIR}/compiler

.include "${MASTERDIR}/Makefile"
