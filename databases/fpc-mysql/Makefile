# New ports collection makefile for:	Free Pascal mysql Unit
# Date created: 			9 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-mysql

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to MySQL

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc

USE_MYSQL=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/base/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"
