# New ports collection makefile for:	Free Pascal ibase Unit
# Date created: 			9 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-ibase

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to interbase

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
LIB_DEPENDS=	fbembed.1:${PORTSDIR}/databases/firebird-client

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/base/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"
