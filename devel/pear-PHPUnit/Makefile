# Ports collection makefile for:  pear-PHPUnit
# Date created:			  24 February 2004
# Whom:				  Gerrit Beine (<gerrit@beine-computer.de>)
#
# $FreeBSD$
#

PORTNAME=	PHPUnit
PORTVERSION=	0.6.2
CATEGORIES=	devel www pear

MAINTAINER=	gerrit@beine-computer.de
COMMENT=	Regression testing framework for unit tests

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		PHPUnit.php \
		PHPUnit/Assert.php PHPUnit/RepeatedTest.php PHPUnit/TestCase.php \
		PHPUnit/TestDecorator.php PHPUnit/TestFailure.php PHPUnit/TestListener.php \
		PHPUnit/TestResult.php PHPUnit/TestSuite.php \
		PHPUnit/GUI/HTML.php PHPUnit/GUI/HTML.tpl PHPUnit/GUI/SetupDecorator.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
