CATEGORIES=	databases lang
PKGNAMESUFFIX=	-postgres

COMMENT=	Free Pascal interface to PostGreSQL

USES=		fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	PGSQL
PGSQL_DESC=	Install PostgreSQL client

PGSQL_USES=	pgsql

.include "${MASTERDIR}/Makefile"
