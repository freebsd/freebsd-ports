# Ports collection makefile for:  pear-DB_ldap
# Date created:			  08 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	DB_ldap
PORTVERSION=	1.2.0
CATEGORIES=	databases net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR DB compliant interface to LDAP servers

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	DB
FILES=		ldap.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
