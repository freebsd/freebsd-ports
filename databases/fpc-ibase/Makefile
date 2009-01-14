# New ports collection makefile for:	Free Pascal ibase Unit
# Date created: 			9 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	databases lang
PKGNAMESUFFIX=	-ibase

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to interbase

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	IBASE	"Install Interbase/Firebird client"	on

.include "${MASTERDIR}/Makefile"
