# Ports collection makefile for:  pear-PHPUnit
# Date created:			  24 February 2004
# Whom:				  Gerrit Beine (<gerrit@beine-computer.de>)
#
# $FreeBSD$
#

PORTNAME=	PHPUnit
PORTVERSION=	1.3.3
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.phpunit.de/get/

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	PEAR regression testing framework for unit tests

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

MANUAL_PACKAGE_BUILD=	attempts to contact pear.phpunit.de during install phase

CHANNEL=	pear.phpunit.de
SUB_FILES=	pear-deinstall pear-install
SUB_LIST+=	CHANNEL=${CHANNEL}
PKGINSTALL=	${WRKDIR}/pear-install
PKGDEINSTALL=	${WRKDIR}/pear-deinstall

NO_LATEST_LINK=	yes

FILES=		PHPUnit.php PHPUnit/GUI/Gtk.php PHPUnit/GUI/HTML.php \
		PHPUnit/GUI/HTML.tpl PHPUnit/GUI/SetupDecorator.php \
		PHPUnit/Assert.php PHPUnit/RepeatedTest.php PHPUnit/Skeleton.php \
		PHPUnit/TestCase.php PHPUnit/TestDecorator.php \
		PHPUnit/TestFailure.php PHPUnit/TestListener.php \
		PHPUnit/TestResult.php PHPUnit/TestSuite.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
