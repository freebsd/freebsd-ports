# Ports collection makefile for:  pear-HTML_Template_Flexy
# Date created:			  04 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Template_Flexy
PORTVERSION=	1.1.2
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	An extremely powerful Tokenizer driven Template engine

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-HTML_Template_Flexy
OPTIONS=	PEAR_HTML_JAVASCRIPT "PEAR::HTML_Javascript support" off \
		PEAR_FILE_GETTEXT "PEAR::File_Gettext support" off \
		PEAR_TRANSLATION2 "PEAR::Translation2 support" off

USE_PHP=	yes

CATEGORY=	HTML/Template
FILES=		Flexy.php Flexy/example.ini Flexy/Element.php \
		Flexy/Element/Xul.php Flexy/Factory.php Flexy/Assign.php \
		Flexy/Plugin.php Flexy/Plugin/Savant.php Flexy/SmartyAPI.php \
		Flexy/Translator.php Flexy/templates/translator.html \
		Flexy/compileAll.php Flexy/Tree.php Flexy/Tokenizer.php \
		Flexy/Token.php Flexy/Token/Tag.php Flexy/Token/EndTag.php \
		Flexy/Token/If.php Flexy/Token/Else.php Flexy/Token/End.php \
		Flexy/Token/Foreach.php Flexy/Token/Var.php Flexy/Token/Method.php \
		Flexy/Token/Processing.php Flexy/Token/Text.php Flexy/Test.php \
		Flexy/Compiler.php Flexy/Compiler/Flexy.php \
		Flexy/Compiler/Flexy/Tag.php Flexy/Compiler/Flexy/Flexy.php \
		Flexy/Compiler/Standard.php Flexy/Compiler/Standard/Tag.php \
		Flexy/Compiler/Standard/Flexy.php Flexy/Compiler/Regex.php \
		Flexy/Compiler/Regex/BodyOnly.php Flexy/Compiler/Regex/Php.php \
		Flexy/Compiler/Regex/RtfSimpleTags.php \
		Flexy/Compiler/Regex/SimpleTags.php Flexy/Compiler/Regex/Mail.php \
		Flexy/Compiler/Regex/Xml.php Flexy/Compiler/Regex/Math.php \
		Flexy/Compiler/SmartyConvertor.php
TESTS=		test.php treeTest.php templates/blocks.html templates/conditions.html \
		templates/error_foreach.html templates/flexy_tojavascript.html \
		templates/forms.html templates/function.html templates/globals.html \
		templates/image_view.html templates/includes.html \
		templates/javascript.html templates/looping.html templates/methods.html \
		templates/namespaces.html templates/raw_php.html \
		templates/raw_text.html templates/variables.html smarty/smartytest.php

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 430
IGNORE=		"You need PHP 4.3.0 or later to install PEAR::HTML_Template_Flexy"
.endif

.if !defined(WITH_PEAR_HTML_JAVASCRIPT)
BUILD_DEPENDS+=	${PEARDIR}/HTML/Javascript.php:${PORTSDIR}/devel/pear-HTML_Javascript
.endif

.if defined(WITH_PEAR_FILE_GETTEXT)
BUILD_DEPENDS+= ${PEARDIR}/File/Gettext.php:${PORTSDIR}/sysutils/pear-File_Gettext
.endif

.if defined(WITH_PEAR_TRANSLATION2)
BUILD_DEPENDS+=	${PEARDIR}/Translation2.php:${PORTSDIR}/sysutils/pear-Translation2
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
