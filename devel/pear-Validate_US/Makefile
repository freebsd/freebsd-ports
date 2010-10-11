# Ports collection makefile for:  pear-Validate_US
# Date created:			  Oct 11, 2010
# Whom:				  Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Validate_US
PORTVERSION=	0.5.4
CATEGORIES=	devel www pear

MAINTAINER=	wen@FreeBSD.org
COMMENT=	PEAR data validation class for US

BUILD_DEPENDS=	pear-Validate>=0.5.0:${PORTSDIR}/devel/pear-Validate
RUN_DEPENDS=	pear-Validate>=0.5.0:${PORTSDIR}/devel/pear-Validate

FILES=		Validate/US.php
TESTS=		validate_US.phpt validate_functions.inc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
