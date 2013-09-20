# Created by: John Merryweather Cooper
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-ibase

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to interbase

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	IBASE
IBASE_DESC=	Install Interbase/Firebird client
OPTIONS_DEFAULT=	IBASE

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
