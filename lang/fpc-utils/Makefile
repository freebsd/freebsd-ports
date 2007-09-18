# New ports collection makefile for:	fpc-utils
# Date created: 			2006-07-12
# Whom: 				Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	lang
PKGNAMESUFFIX=	-utils

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Compiler utils

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		${UNITSDIR}/fcl-base/Package.fpc:${PORTSDIR}/devel/fpc-fcl-base \
		${UNITSDIR}/fcl-passrc/Package.fpc:${PORTSDIR}/devel/fpc-fcl-passrc \
		${UNITSDIR}/fcl-xml/Package.fpc:${PORTSDIR}/devel/fpc-fcl-xml \
		${UNITSDIR}/gdbint/Package.fpc:${PORTSDIR}/devel/fpc-gdbint \
		${UNITSDIR}/graph/Package.fpc:${PORTSDIR}/graphics/fpc-graph \
		${UNITSDIR}/ibase/Package.fpc:${PORTSDIR}/databases/fpc-ibase \
		${UNITSDIR}/libasync/Package.fpc:${PORTSDIR}/net/fpc-libasync \
		${UNITSDIR}/libcurl/Package.fpc:${PORTSDIR}/ftp/fpc-libcurl \
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
EXTRACTUNITDIR+=	${WRKUNITDIR} ${FPCSRCDIR}/fcl/inc

.include "${MASTERDIR}/Makefile"
