# New ports collection makefile for:	fpc-fpvectorial
# Date created:		2010-04-22
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-fpvectorial

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal fpvectorial unit

USE_FPC=	fcl-image paszlib

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
