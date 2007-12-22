# New ports collection makefile for:	fpc-cairo
# Date created:		2006-09-11
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-cairo

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to cairo library

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils \
		${UNITSDIR}/fcl-base/Package.fpc:${PORTSDIR}/devel/fpc-fcl-base \
		${UNITSDIR}/fcl-image/Package.fpc:${PORTSDIR}/devel/fpc-fcl-image \
		${UNITSDIR}/hash/Package.fpc:${PORTSDIR}/security/fpc-hash \
		${UNITSDIR}/libasync/Package.fpc:${PORTSDIR}/net/fpc-libasync \
		${UNITSDIR}/netdb/Package.fpc:${PORTSDIR}/net/fpc-netdb \
		${UNITSDIR}/pasjpeg/Package.fpc:${PORTSDIR}/graphics/fpc-pasjpeg \
		${UNITSDIR}/paszlib/Package.fpc:${PORTSDIR}/archivers/fpc-paszlib \
		${UNITSDIR}/pthreads/Package.fpc:${PORTSDIR}/devel/fpc-pthreads \
		${UNITSDIR}/x11/Package.fpc:${PORTSDIR}/x11/fpc-x11

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBCAIRO	"Install cairo vector graphics library"	on

.include "${MASTERDIR}/Makefile"
