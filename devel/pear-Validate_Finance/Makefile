# Ports collection makefile for:  pear-Validate
# Date created:			  8 November 2006
# Whom:				  Anish Mistry (<amistry@am-productions.biz>)
#
# $FreeBSD$
#

PORTNAME=	Validate_Finance
PORTVERSION=	0.5.3
CATEGORIES=	devel www pear

MAINTAINER=	amistry@am-productions.biz
COMMENT=	PEAR Finance Validation class

BUILD_DEPENDS=	pear-Validate>=0.5.0:${PORTSDIR}/devel/pear-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Validate/Finance
FILES=		Validate/Finance.php Validate/Finance/IBAN.php

TESTS=		validate_Finance.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>

