# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-postgres

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to PostGreSQL

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc

USE_PGSQL=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/base/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"
