# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

CATEGORIES=	editors lang
PKGNAMESUFFIX=	-ide

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free Pascal integrated IDE/compiler

RUN_DEPENDS=	${UNITSDIR}/fv/Package.fpc:${PORTSDIR}/devel/fpc-fv

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
UNITPREFIX=	# none
MASTERDIR=	${.CURDIR}/../../lang/fpc

.include "${MASTERDIR}/Makefile"
