# New ports collection makefile for:	fpc-unzip
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	archivers lang
PKGNAMESUFFIX=	-unzip

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal routines for unzipping zip files

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	UNZIP	"Install unzip tools"	on

.include "${MASTERDIR}/Makefile"
