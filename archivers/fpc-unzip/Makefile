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

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	UNZIP	"Install unzip tools"	on

.include "${MASTERDIR}/Makefile"
