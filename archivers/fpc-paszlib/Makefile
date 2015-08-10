# Created by: John Merryweather Cooper
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	archivers devel
PKGNAMESUFFIX=	-paszlib

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal unit for native compression IO

USE_FPC=	hash
USE_FPC_RUN=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
