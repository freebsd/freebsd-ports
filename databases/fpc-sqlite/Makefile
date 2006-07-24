# New ports collection makefile for:	fpc-sqlite
# Date created: 			2006-06-05
# Whom: 				Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-sqlite

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to SQLite

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc

USE_SQLITE=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/base/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
