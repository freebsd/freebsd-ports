# Ports collection makefile for:  pear-HTML_Template_IT
# Date created:			  02 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Template_IT
DISTVERSION=	1.3.0a1
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Integrated template API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML/Template
FILES=		IT.php ITX.php IT_Error.php
EXAMPLES=	sample_it.php sample_itx_addblockfile.php \
		templates/addblockfile_list.tpl.htm \
		templates/addblockfile_main.tpl.htm \
		templates/main.tpl.htm
TESTS=		Console_TestListener.php ITX_api_testcase.php \
		ITX_usage_testcase.php IT_api_testcase.php \
		IT_usage_testcase.php templates/__include.html \
		templates/addblock.html templates/blockiteration.html \
		templates/blocks.html templates/globals.html \
		templates/include.html templates/loadtemplatefile.html \
		templates/replaceblock.html test.php

do-install-tests-msg: .USE
	@${ECHO_MSG} "     (These tests require PHPUnit - see"
	@${ECHO_MSG} "     <http://pear.php.net/package-info.php?package=PHPUnit>;;)."

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
