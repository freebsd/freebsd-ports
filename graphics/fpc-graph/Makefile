# New ports collection makefile for:	fpc-graph
# Date created:		2006-09-05
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-graph

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to graphical applications

USE_FPC=	x11 sdl pthreads

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
