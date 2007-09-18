# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			2006-09-11
# Whom: 				Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-db

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Component Library

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		${UNITSDIR}/ibase/Package.fpc:${PORTSDIR}/databases/fpc-ibase \
		${UNITSDIR}/mysql/Package.fpc:${PORTSDIR}/databases/fpc-mysql \
		${UNITSDIR}/odbc/Package.fpc:${PORTSDIR}/databases/fpc-odbc \
		${UNITSDIR}/oracle/Package.fpc:${PORTSDIR}/databases/fpc-oracle \
		${UNITSDIR}/postgres/Package.fpc:${PORTSDIR}/databases/fpc-postgres \
		${UNITSDIR}/sqlite/Package.fpc:${PORTSDIR}/databases/fpc-sqlite

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
