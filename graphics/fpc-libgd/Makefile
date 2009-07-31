# New ports collection makefile for:	fpc-libgd
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-libgd

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to libgd for producing graphics files

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBGD	"Install gd graphic library"	on

.include "${MASTERDIR}/Makefile"
