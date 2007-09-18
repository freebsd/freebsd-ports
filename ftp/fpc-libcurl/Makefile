# New ports collection makefile for:	fpc-libcurl
# Date created:		2007-09-11
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	ftp lang
PKGNAMESUFFIX=	-libcurl

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to libcurl

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBCURL	"Install curl tools and library "	on

.include "${MASTERDIR}/Makefile"
