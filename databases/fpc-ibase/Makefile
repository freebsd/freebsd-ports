# New ports collection makefile for:	Free Pascal ibase Unit
# Date created: 			9 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-ibase

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free Pascal interface to interbase

RUN_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
LIB_DEPENDS=	fbembed.1:${PORTSDIR}/databases/firebird-client

MASTERDIR=	${.CURDIR}/../../lang/fpc

.include "${MASTERDIR}/Makefile"
