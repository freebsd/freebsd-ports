# New ports collection makefile for:	fpc-iconv
# Date created:		2009-04-26
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	converters lang
PKGNAMESUFFIX=	-iconvenc

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit to iconv library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
