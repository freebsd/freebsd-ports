# New ports collection makefile for:	FreeVision
# Date created: 			9 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	archivers devel
PKGNAMESUFFIX=	-paszlib

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit for native compression IO

USE_FPC=	hash

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
