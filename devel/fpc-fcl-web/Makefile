# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			2006-09-11
# Whom: 				Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-web

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Component Library

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		${UNITSDIR}/fcl-base/Package.fpc:${PORTSDIR}/devel/fpc-fcl-base \
		${UNITSDIR}/fcl-xml/Package.fpc:${PORTSDIR}/devel/fpc-fcl-xml \
		${UNITSDIR}/fcl-db/Package.fpc:${PORTSDIR}/devel/fpc-fcl-db

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
