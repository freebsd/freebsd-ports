# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	lang
PKGNAMESUFFIX=	-rexx

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the rexx-regina library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	REXX_REGINA
REXX_REGINA_DESC=	Install rexx-regina library
OPTIONS_DEFAULT=	REXX_REGINA

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
