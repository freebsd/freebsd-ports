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

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/base/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
