# New ports collection makefile for:	fpc-fpmkunit
# Date created:				2006-09-11
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fpmkunit

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal build system unit

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
