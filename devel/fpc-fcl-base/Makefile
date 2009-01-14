# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			2006-09-11
# Whom: 				Jose Alonso Cardenas Marquez <acm@FreeBS.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-base

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Component Library

USE_FPC=	hash paszlib pthreads

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
