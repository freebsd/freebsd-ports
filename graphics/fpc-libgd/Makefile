# New ports collection makefile for:	fpc-libgd
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-libgd

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to libgd for producing graphics files

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"
