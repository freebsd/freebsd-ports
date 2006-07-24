# New ports collection makefile for:	fpc-fpgtk
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-fpgtk

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Component Library for create programs with gtk

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils \
		${UNITSDIR}/fcl/Package.fpc:${PORTSDIR}/devel/fpc-fcl \
		${UNITSDIR}/gdbint/Package.fpc:${PORTSDIR}/devel/fpc-gdbint \
		${UNITSDIR}/ibase/Package.fpc:${PORTSDIR}/databases/fpc-ibase \
		${UNITSDIR}/libasync/Package.fpc:${PORTSDIR}/net/fpc-libasync \
		${UNITSDIR}/md5/Package.fpc:${PORTSDIR}/security/fpc-md5 \
		${UNITSDIR}/mysql/Package.fpc:${PORTSDIR}/databases/fpc-mysql \
		${UNITSDIR}/netdb/Package.fpc:${PORTSDIR}/net/fpc-netdb \
		${UNITSDIR}/odbc/Package.fpc:${PORTSDIR}/databases/fpc-odbc \
		${UNITSDIR}/oracle/Package.fpc:${PORTSDIR}/databases/fpc-oracle \
		${UNITSDIR}/pasjpeg/Package.fpc:${PORTSDIR}/graphics/fpc-pasjpeg \
		${UNITSDIR}/paszlib/Package.fpc:${PORTSDIR}/archivers/fpc-paszlib \
		${UNITSDIR}/pthreads/Package.fpc:${PORTSDIR}/devel/fpc-pthreads \
		${UNITSDIR}/postgres/Package.fpc:${PORTSDIR}/databases/fpc-postgres \
		${UNITSDIR}/regexpr/Package.fpc:${PORTSDIR}/devel/fpc-regexpr \
		${UNITSDIR}/sqlite/Package.fpc:${PORTSDIR}/databases/fpc-sqlite \
		${UNITSDIR}/gtk/Package.fpc:${PORTSDIR}/x11-toolkits/fpc-gtk \
		${UNITSDIR}/x11/Package.fpc:${PORTSDIR}/x11/fpc-x11 \
		${UNITSDIR}/opengl/Package.fpc:${PORTSDIR}/graphics/fpc-opengl

USE_GNOME=	gtk12

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
