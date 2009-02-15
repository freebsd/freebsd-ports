# Ports collection makefile for:  pear-Validate
# Date created:			  25 August 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@php.net>)
#
# $FreeBSD$
#

PORTNAME=	Validate
PORTVERSION=	0.8.2
CATEGORIES=	devel www pear

MAINTAINER=	amistry@am-productions.biz
COMMENT=	PEAR Validation class

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Validate.php

TESTS=		number.phpt testdate.phpt email.phpt multiple.phpt \
		multicard.phpt uri.phpt

DOCS=		sample_multiple.php Example_Locale.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
