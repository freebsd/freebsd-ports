# Created by: John Merryweather Cooper

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-mysql

COMMENT=	Free Pascal interface to MySQL

USES=		fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	MYSQL
MYSQL_DESC=	Install MySQL client

MYSQL_USES=	mysql

.include "${MASTERDIR}/Makefile"
