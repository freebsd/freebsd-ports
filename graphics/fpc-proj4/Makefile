# New ports collection makefile for:	fpc-proj4
# Date created:		2010-04-22
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-proj4

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to proj library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	PROJ	"Install proj library"	on

.include "${MASTERDIR}/Makefile"
