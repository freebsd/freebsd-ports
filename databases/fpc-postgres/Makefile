# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-postgres

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to PostGreSQL

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/base/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	PGSQL	"Install PostgreSQL client"	on

.include "${MASTERDIR}/Makefile"
