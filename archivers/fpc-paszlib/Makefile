# Created by: John Merryweather Cooper
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	archivers devel
PKGNAMESUFFIX=	-paszlib

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit for native compression IO

USE_FPC=	hash

NO_STAGE=	yes
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
