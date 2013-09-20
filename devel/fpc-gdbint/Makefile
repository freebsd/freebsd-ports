# Created by: John Merryweather Cooper et al
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	devel
PKGNAMESUFFIX=	-gdbint

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit providing interface to gdb

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
