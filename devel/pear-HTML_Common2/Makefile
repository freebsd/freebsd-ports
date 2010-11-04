# Ports collection makefile for:  pear-HTML_Common2
# Date created:			  27 December 2006
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML_Common2
PORTVERSION=	2.0.0
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR::HTML_Common2 is a base class for other HTML classes

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		HTML/Common2.php
TESTS=		HTML_Common2_Test.php AllTests.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
