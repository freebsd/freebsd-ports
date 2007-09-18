# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			8 January 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-odbc

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to ODBC

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/base/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	ODBC	"Install ODBC library suite for Unix"	on

.include "${MASTERDIR}/Makefile"
