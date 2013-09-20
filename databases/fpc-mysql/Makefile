# Created by: John Merryweather Cooper
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-mysql

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to MySQL

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	MYSQL
MYSQL_DESC=	Install MySQL client
OPTIONS_DEFAULT=	MYSQL

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
