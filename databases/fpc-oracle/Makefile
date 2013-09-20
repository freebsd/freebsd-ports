# Created by: John Merryweather Cooper et al
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-oracle

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to Oracle

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	ORACLE
ORACLE_DESC=	Install oracle client

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
