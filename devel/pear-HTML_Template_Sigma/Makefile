# Ports collection makefile for:  pear-HTML_Template_Sigma
# Date created:			  21 July 2005
# Whom:				  Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	HTML_Template_Sigma
PORTVERSION=	1.1.2
CATEGORIES=	devel www pear

MAINTAINER=	klammer@webonaut.com
COMMENT=	PEAR template API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML/Template
FILES=		Sigma.php
EXAMPLES=	templates/example_1.html templates/example_2.html templates/example_3.html \
		templates/example_4.html templates/example_3_add.html \
		templates/example_3_include.html templates/example_3_replace_1.html \
		templates/example_3_replace_2.html example_1.php example_2.php \
		example_3.php example_4.php
TESTS=		templates/addblock.html templates/blockiteration.html templates/blocks.html \
		templates/callback.html templates/globals.html templates/__include.html \
		templates/include.html templates/loadtemplatefile.html \
		templates/replaceblock.html Console_TestListener.php Sigma_api_testcase.php \
		Sigma_usage_testcase.php Sigma_cache_testcase.php test.php
_EXAMPLESDIR=	docs

do-install-tests-msg: .USE
	@${ECHO_MSG} "     (These tests require PHPUnit - see"
	@${ECHO_MSG} "     <http://pear.php.net/package-info.php?package=PHPUnit>;;)."

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
