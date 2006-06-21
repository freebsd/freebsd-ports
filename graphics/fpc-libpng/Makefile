# New ports collection makefile for:	fpc-libpng
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-libpng

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free Pascal interface to libpng, for reading PNG image files

RUN_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

MASTERDIR=	${.CURDIR}/../../lang/fpc

.include "${MASTERDIR}/Makefile"
