# New ports collection makefile for:	fpc-svgalib
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-svgalib

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the SVGA graphics library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	SVGA	"Install svgalib low level console graphics library"	off

.include "${MASTERDIR}/Makefile"
