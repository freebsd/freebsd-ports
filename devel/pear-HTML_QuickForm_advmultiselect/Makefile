# Ports collection makefile for:	pear-HTML_QuickForm_advmultiselect
# Date created:				11 November 2005
# Whom:					Chris St Denis <chris@ctgameinfo.com>
#
# $FreeBSD$
#

PORTNAME=	HTML_QuickForm_advmultiselect
PORTVERSION=	1.5.0
CATEGORIES=	devel www pear
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	chris@ctgameinfo.com
COMMENT=	Element for PEAR::HTML_QuickForm that defines a 2 box multi-select

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm \
		${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML/QuickForm
FILES=		advmultiselect.php qfamsHandler.js qfamsHandler-min.js

EXAMPLES=	bluestar-12.gif down.png \
		goldstar-12.gif itdynamic.html \
		qfams_basic_1.php qfams_basic_2.php \
		qfams_custom_1.php qfams_custom_2.php \
		qfams_custom_3.php qfams_custom_4.php \
		qfams_custom_5.php qfams_custom_6.php \
		qfams_custom_7.php qfams_custom_8.php \
		qfams_custom_9.php qfams_multiple_1.php \
		qfams_multiple_2.php qfams_template_1.php \
		up.png

TESTS=		AllTests.php \
		HTML_QuickForm_advmultiselect_TestSuite_Basic.php \
		HTML_QuickForm_advmultiselect_TestSuite_Custom.php \
		HTML_QuickForm_advmultiselect_TestSuite_Exception.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
