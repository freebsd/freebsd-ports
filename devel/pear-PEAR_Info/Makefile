# Ports collection makefile for:  pear-PEAR_Info
# Date created:		2006/07/31
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	PEAR_Info
PORTVERSION=	1.6.1
CATEGORIES=	devel www pear

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Show Information about your PEAR install and its packages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	PEAR
FILES=		Info.php
TESTS=		pear_info.php

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
