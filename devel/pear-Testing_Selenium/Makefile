# Ports collection makefile for:  pear-Testing_Selenium
# Date created:			  15 December 2007
# Whom:				  Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	Testing_Selenium
PORTVERSION=	0.4.3
CATEGORIES=	devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Binding - Once more unto the breach

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		Selenium/Exception.php \
		ChangeLog \
		Selenium.php \
		readme \
		todo
EXAMPLES=	example.php
TESTS=		html/bug8893.html \
		html/bug9119.html \
		html/bug9189.html \
		AllTests.php \
		BugTest.php \
		GoogleTest.php \
		SeleniumTest.php
_TESTSDIR=	tests

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
