# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			2006-06-05
# Whom: 				Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-bfd

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free Pascal interface for the GNU Binary Format description

RUN_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		${LOCALBASE}/lib/libbfd.a:${PORTSDIR}/devel/libbfd

MASTERDIR=	${.CURDIR}/../../lang/fpc

.include "${MASTERDIR}/Makefile"
