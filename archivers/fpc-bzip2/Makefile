# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	archivers lang
PKGNAMESUFFIX=	-bzip2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal bzip2 unit

USE_FPC=	yes

NO_STAGE=	yes
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
