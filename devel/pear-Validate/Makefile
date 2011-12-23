# Ports collection makefile for:  pear-Validate
# Date created:			  25 August 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@php.net>)
#
# $FreeBSD$
#

PORTNAME=	Validate
PORTVERSION=	0.8.5
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Validation class

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		Validate.php

TESTS=		email.phpt email_domaincheck.phpt \
		multiple.phpt multicard.phpt \
		number.phpt testdate.phpt \
		testdate_minmax.phpt \
		uri.phpt uri_domaincheck.phpt

DOCS=		sample_multiple.php Example_Locale.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
