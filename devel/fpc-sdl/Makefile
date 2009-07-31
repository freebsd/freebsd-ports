# New ports collection makefile for:	fpc-sdl
# Date created:		2009-01-06
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTVERSION=	0
PORTREVISION=	1
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-sdl

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to SDL library

USE_FPC=	pthreads x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	SDL   "Install SDL library"     on

.include "${MASTERDIR}/Makefile"
