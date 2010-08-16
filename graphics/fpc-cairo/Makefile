# New ports collection makefile for:	fpc-cairo
# Date created:		2006-09-11
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-cairo

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to cairo library

USE_FPC=	fcl-async fcl-base fcl-image hash pasjpeg paszlib pthreads \
		x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBCAIRO	"Install cairo vector graphics library"	on

.include "${MASTERDIR}/Makefile"
