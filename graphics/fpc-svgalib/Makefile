# New ports collection makefile for:	fpc-svgalib
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-svgalib

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the SVGA graphics library

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils
LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"
