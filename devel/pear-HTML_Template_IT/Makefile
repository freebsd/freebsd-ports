# Ports collection makefile for:  pear-HTML_Template_IT
# Date created:			  02 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Template_IT
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR template API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML/Template
FILES=		IT.php ITX.php IT_Error.php
EXAMPLES=	sample_it.php templates/main.tpl.htm
TESTS=		templates/addblock.html templates/blockiteration.html \
		templates/blocks.html templates/globals.html templates/__include.html \
		templates/include.html templates/loadtemplatefile.html \
		templates/replaceblock.html Console_TestListener.php IT_api_testcase.php \
		IT_usage_testcase.php ITX_api_testcase.php ITX_usage_testcase.php test.php

do-install-tests-msg: .USE
	@${ECHO_MSG} "     (These tests require PHPUnit - see"
	@${ECHO_MSG} "     <http://pear.php.net/package-info.php?package=PHPUnit>;;)."

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
