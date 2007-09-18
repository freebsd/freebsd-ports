# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			2006-09-11
# Whom: 				Jose Alonso Cardenas Marquez <acm@FreeBS.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl-base

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Component Library

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		${UNITSDIR}/libasync/Package.fpc:${PORTSDIR}/net/fpc-libasync \
		${UNITSDIR}/hash/Package.fpc:${PORTSDIR}/security/fpc-hash \
		${UNITSDIR}/netdb/Package.fpc:${PORTSDIR}/net/fpc-netdb \
		${UNITSDIR}/paszlib/Package.fpc:${PORTSDIR}/archivers/fpc-paszlib \
		${UNITSDIR}/pthreads/Package.fpc:${PORTSDIR}/devel/fpc-pthreads

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
