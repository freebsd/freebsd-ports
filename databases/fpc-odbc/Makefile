# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			8 January 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-odbc

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to ODBC

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
LIB_DEPENDS=	odbc.1:${PORTSDIR}/databases/unixODBC

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/base/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"
