# Created by: John Merryweather Cooper
# $FreeBSD$

PORTREVISION=	5
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-ibase

COMMENT=	Free Pascal interface to interbase

USES=		fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	IBASE
IBASE_DESC=	Install Interbase/Firebird client
OPTIONS_DEFAULT=	IBASE

IBASE_USES=	firebird

.include "${MASTERDIR}/Makefile"
