# New ports collection makefile for:	Free Pascal mysql Unit
# Date created: 			9 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-mysql

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to MySQL

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	MYSQL	"Install MySQL client"	on

.include "${MASTERDIR}/Makefile"
