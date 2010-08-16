# New ports collection makefile for:	fpc-rexx
# Date created:		2010-04-22
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	lang
PKGNAMESUFFIX=	-rexx

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the rexx-regina library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	REXX_REGINA	"Install rexx-regina library"	on

.include "${MASTERDIR}/Makefile"
