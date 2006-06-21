# New ports collection makefile for:	fpc-unzip
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	archivers lang
PKGNAMESUFFIX=	-unzip

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free Pascal routines for unzipping zip files

RUN_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		unzip:${PORTSDIR}/archivers/unzip

MASTERDIR=	${.CURDIR}/../../lang/fpc

.include "${MASTERDIR}/Makefile"
