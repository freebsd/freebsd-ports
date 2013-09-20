# Created by: John Merryweather Cooper
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-odbc

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to ODBC

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	ODBC
ODBC_DESC=	Install ODBC library suite for Unix

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
