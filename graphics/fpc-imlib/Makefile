# New ports collection makefile for:	fpc-imlib
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-imlib

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to imlib library

USE_FPC=	gtk1 x11 opengl

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	IMLIB	"Install imlib graphic library"	on

.include "${MASTERDIR}/Makefile"
