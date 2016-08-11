# Created by: John Merryweather Cooper
# $FreeBSD$

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-ibase

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal interface to interbase

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	IBASE
IBASE_DESC=	Install Interbase/Firebird client
OPTIONS_DEFAULT=	IBASE

IBASE_USES=	firebird

.include "${MASTERDIR}/Makefile"
