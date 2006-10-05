# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			2006-06-05
# Whom: 				Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	2
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-fcl

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Component Library

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		${UNITSDIR}/gdbint/Package.fpc:${PORTSDIR}/devel/fpc-gdbint \
		${UNITSDIR}/graph/Package.fpc:${PORTSDIR}/graphics/fpc-graph \
		${UNITSDIR}/ibase/Package.fpc:${PORTSDIR}/databases/fpc-ibase \
		${UNITSDIR}/libasync/Package.fpc:${PORTSDIR}/net/fpc-libasync \
		${UNITSDIR}/hash/Package.fpc:${PORTSDIR}/security/fpc-hash \
		${UNITSDIR}/mysql/Package.fpc:${PORTSDIR}/databases/fpc-mysql \
		${UNITSDIR}/netdb/Package.fpc:${PORTSDIR}/net/fpc-netdb \
		${UNITSDIR}/odbc/Package.fpc:${PORTSDIR}/databases/fpc-odbc \
		${UNITSDIR}/oracle/Package.fpc:${PORTSDIR}/databases/fpc-oracle \
		${UNITSDIR}/pasjpeg/Package.fpc:${PORTSDIR}/graphics/fpc-pasjpeg \
		${UNITSDIR}/paszlib/Package.fpc:${PORTSDIR}/archivers/fpc-paszlib \
		${UNITSDIR}/pthreads/Package.fpc:${PORTSDIR}/devel/fpc-pthreads \
		${UNITSDIR}/postgres/Package.fpc:${PORTSDIR}/databases/fpc-postgres \
		${UNITSDIR}/regexpr/Package.fpc:${PORTSDIR}/devel/fpc-regexpr \
		${UNITSDIR}/sqlite/Package.fpc:${PORTSDIR}/databases/fpc-sqlite

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
