# Ports collection makefile for:  pear-PHPUnit
# Date created:			  24 February 2004
# Whom:				  Gerrit Beine (<gerrit@beine-computer.de>)
#
# $FreeBSD$
#

PORTNAME=	PHPUnit
PORTVERSION=	1.3.2
CATEGORIES=	devel www pear

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	PEAR regression testing framework for unit tests

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		PHPUnit.php PHPUnit/GUI/Gtk.php PHPUnit/GUI/HTML.php \
		PHPUnit/GUI/HTML.tpl PHPUnit/GUI/SetupDecorator.php \
		PHPUnit/Assert.php PHPUnit/RepeatedTest.php PHPUnit/Skeleton.php \
		PHPUnit/TestCase.php PHPUnit/TestDecorator.php \
		PHPUnit/TestFailure.php PHPUnit/TestListener.php \
		PHPUnit/TestResult.php PHPUnit/TestSuite.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
