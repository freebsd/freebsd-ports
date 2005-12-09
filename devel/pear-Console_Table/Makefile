# Ports collection makefile for:  pear-Console_Table
# Date created:			  31 August 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Console_Table
PORTVERSION=	1.0.2
CATEGORIES=	devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP class that makes it easy to build console style tables

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Console
FILES=		Table.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
