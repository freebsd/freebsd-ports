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
		${UNITSDIR}/fcl-db/Package.fpc:${PORTSDIR}/devel/fpc-fcl-db \
		${UNITSDIR}/hash/Package.fpc:${PORTSDIR}/security/fpc-hash \
		${UNITSDIR}/ibase/Package.fpc:${PORTSDIR}/databases/fpc-ibase \
		${UNITSDIR}/libasync/Package.fpc:${PORTSDIR}/net/fpc-libasync \
		${UNITSDIR}/mysql/Package.fpc:${PORTSDIR}/databases/fpc-mysql \
		${UNITSDIR}/netdb/Package.fpc:${PORTSDIR}/net/fpc-netdb \
		${UNITSDIR}/odbc/Package.fpc:${PORTSDIR}/databases/fpc-odbc \
		${UNITSDIR}/oracle/Package.fpc:${PORTSDIR}/databases/fpc-oracle \
		${UNITSDIR}/paszlib/Package.fpc:${PORTSDIR}/archivers/fpc-paszlib \
		${UNITSDIR}/postgres/Package.fpc:${PORTSDIR}/databases/fpc-postgres \
		${UNITSDIR}/pthreads/Package.fpc:${PORTSDIR}/devel/fpc-pthreads \
		${UNITSDIR}/sqlite/Package.fpc:${PORTSDIR}/databases/fpc-sqlite

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
