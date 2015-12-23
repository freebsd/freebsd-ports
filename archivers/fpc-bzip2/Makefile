# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

CATEGORIES=	archivers lang
PKGNAMESUFFIX=	-bzip2

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal bzip2 unit

USE_FPC=	rtl-extra

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
