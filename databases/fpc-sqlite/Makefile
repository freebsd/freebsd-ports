# Created by: Alonso Cardenas Marquez <acm@FreeBSD.rog>
# $FreeBSD$

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-sqlite

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal interface to SQLite

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	SQLITE
OPTIONS_DEFAULT=	SQLITE

SQLITE_USES=	sqlite

.include "${MASTERDIR}/Makefile"
