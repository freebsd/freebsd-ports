# New ports collection makefile for:	fpc-hermes
# Date created:		2010-04-22
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-hermes

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal hermes unit

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	HERMES	"Install hermes graphics library"	on

.include "${MASTERDIR}/Makefile"
