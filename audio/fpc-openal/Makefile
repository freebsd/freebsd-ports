# New ports collection makefile for:	fpc-openal
# Date created: 	2010-04-22
# Whom: 		Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	audio lang
PKGNAMESUFFIX=	-openal

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to openal library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	OPENAL	"Install openal library"	on

.include "${MASTERDIR}/Makefile"
