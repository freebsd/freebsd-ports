# New ports collection makefile for:	fpc-a52
# Date created: 	2010-04-22
# Whom: 		Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	audio lang
PKGNAMESUFFIX=	-a52

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to a52 library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBA52	"Install a52 library"	on

.include "${MASTERDIR}/Makefile"
