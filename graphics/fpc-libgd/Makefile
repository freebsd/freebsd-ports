# New ports collection makefile for:	fpc-libgd
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-libgd

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free Pascal interface to libgd for producing graphics files

RUN_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

MASTERDIR=	${.CURDIR}/../../lang/fpc

.include "${MASTERDIR}/Makefile"
