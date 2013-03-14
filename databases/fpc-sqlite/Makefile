# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-sqlite

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to SQLite

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	SQLITE
OPTIONS_DEFAULT=	SQLITE

.include "${MASTERDIR}/Makefile"
