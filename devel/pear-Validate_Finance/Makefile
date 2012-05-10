# Ports collection makefile for:  pear-Validate
# Date created:			  8 November 2006
# Whom:				  Anish Mistry (<amistry@am-productions.biz>)
#
# $FreeBSD$
#

PORTNAME=	Validate_Finance
PORTVERSION=	0.5.6
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Finance Validation class

BUILD_DEPENDS=	pear-Validate>=0.5.0:${PORTSDIR}/devel/pear-Validate
RUN_DEPENDS=	pear-Validate>=0.5.0:${PORTSDIR}/devel/pear-Validate

FILES=		Validate/Finance.php \
		Validate/Finance/IBAN.php \
		Validate/Finance/ISIN.php

TESTS=		validate_Finance.phpt validate_ISIN.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
