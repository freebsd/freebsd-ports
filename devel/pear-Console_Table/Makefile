# Ports collection makefile for:  pear-Console_Table
# Date created:			  31 August 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Console_Table
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP class that makes it easy to build console style tables

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Console
FILES=		Table.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
