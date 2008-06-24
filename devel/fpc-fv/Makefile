# New ports collection makefile for:	FreeVision
# Date created: 			8 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fv

MAINTAINER=	acm@FreeBSD.org
COMMENT=	FreeVision is a Free Pascal unit for Delphi support

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
