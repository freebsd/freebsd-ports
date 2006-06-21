# New ports collection makefile for:	fpc-svgalib
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-svgalib

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free Pascal interface to the SVGA graphics library

RUN_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib

MASTERDIR=	${.CURDIR}/../../lang/fpc

.include "${MASTERDIR}/Makefile"
