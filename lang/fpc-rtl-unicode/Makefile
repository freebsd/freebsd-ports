# $FreeBSD$

CATEGORIES=	lang
PKGNAMESUFFIX=	-rtl-unicode

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal compatibility unit with Delphi

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
