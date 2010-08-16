# New ports collection makefile for:	fpc-sndfile
# Date created: 	2010-04-22
# Whom: 		Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	audio lang
PKGNAMESUFFIX=	-sndfile

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Interface to sndfile library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBSNDFILE	"Install sndfile library"	on

.include "${MASTERDIR}/Makefile"
