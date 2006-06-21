# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

CATEGORIES=	databases lang
PKGNAMESUFFIX=	-postgres

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free Pascal interface to PostGreSQL

RUN_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc

USE_PGSQL=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc

.include "${MASTERDIR}/Makefile"
