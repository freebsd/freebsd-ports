# New ports collection makefile for:	fpc-libpng
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-libpng

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to libpng, for reading PNG image files

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils \
		${UNITSDIR}/zlib/Package.fpc:${PORTSDIR}/devel/fpc-zlib

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBPNG	"Install png library for manipulating PNG images"	on

.include "${MASTERDIR}/Makefile"
