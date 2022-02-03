CATEGORIES=	databases lang
PKGNAMESUFFIX=	-sqlite

COMMENT=	Free Pascal interface to SQLite

USES=		fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	SQLITE

SQLITE_USES=	sqlite

.include "${MASTERDIR}/Makefile"
