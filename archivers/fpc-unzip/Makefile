# New ports collection makefile for:	fpc-unzip
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	archivers lang
PKGNAMESUFFIX=	-unzip

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal routines for unzipping zip files

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils
RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
