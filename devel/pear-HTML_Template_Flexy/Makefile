# Ports collection makefile for:  pear-HTML_Template_Flexy
# Date created:			  04 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Template_Flexy
PORTVERSION=	1.3.11
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An extremely powerful Tokenizer driven Template engine

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

LATEST_LINK=	pear-HTML_Template_Flexy
OPTIONS=	PEAR_HTML_JAVASCRIPT "PEAR::HTML_Javascript support" off \
		PEAR_FILE_GETTEXT "PEAR::File_Gettext support" off \
		PEAR_TRANSLATION2 "PEAR::Translation2 support" off

PEAR_CATSRC=	yes
CATEGORY=	HTML/Template
FILES=		Flexy.php Flexy/example.ini Flexy/Element.php \
		Flexy/Element/Xul.php Flexy/Factory.php Flexy/Assign.php \
		Flexy/Plugin.php Flexy/Plugin/Savant.php Flexy/SmartyAPI.php \
		Flexy/Translator.php Flexy/templates/translator.html \
		Flexy/compileAll.php Flexy/Tree.php Flexy/Tokenizer.php \
		Flexy/Token.php Flexy/Token/Tag.php Flexy/Token/EndTag.php \
		Flexy/Token/If.php Flexy/Token/Else.php Flexy/Token/End.php \
		Flexy/Token/Foreach.php Flexy/Token/Var.php \
		Flexy/Token/Method.php Flexy/Token/Processing.php \
		Flexy/Token/Text.php Flexy/Test.php Flexy/Compiler.php \
		Flexy/Compiler/Flexy.php Flexy/Compiler/Flexy/Tag.php \
		Flexy/Compiler/Flexy/CustomFlexyAttributes.php \
		Flexy/Compiler/Flexy/Flexy.php Flexy/Compiler/Standard.php \
		Flexy/Compiler/Standard/Tag.php \
		Flexy/Compiler/Standard/Flexy.php Flexy/Compiler/Regex.php \
		Flexy/Compiler/Regex/BodyOnly.php Flexy/Compiler/Regex/Php.php \
		Flexy/Compiler/Regex/RtfSimpleTags.php \
		Flexy/Compiler/Regex/SimpleTags.php \
		Flexy/Compiler/Regex/Mail.php Flexy/Compiler/Regex/Xml.php \
		Flexy/Compiler/Regex/Math.php Flexy/Compiler/SmartyConvertor.php
TESTS=		testsuite.php test_blocks.html.phpt test_bug_2959.html.phpt \
		test_conditions.html.phpt test_error_foreach.html.phpt \
		test_flexy_tojavascript.html.phpt test_forms.html.phpt \
		test_function.html.phpt test_globals.html.phpt \
		test_image_view.html.phpt test_include.html.phpt \
		test_javascript.html.phpt test_looping.html.phpt \
		test_methods.html.phpt test_namespaces.html.phpt \
		test_plugin_modifiers.html.phpt test_raw_php.html.phpt \
		test_raw_text.html.phpt test_style.html.phpt \
		test_variables.html.phpt templates/blocks.html \
		templates/bug_2959.html templates/conditions.html \
		templates/error_foreach.html templates/flexy_tojavascript.html \
		templates/forms.html templates/function.html \
		templates/globals.html templates/image_view.html \
		templates/include.html templates/javascript.html \
		templates/looping.html templates/methods.html \
		templates/namespaces.html templates/plugin_modifiers.html \
		templates/raw_php.html templates/raw_text.html \
		templates/style.html templates/variables.html \
		smarty/smartytest.php

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_HTML_JAVASCRIPT)
RUN_DEPENDS+=	${PEARDIR}/HTML/Javascript.php:${PORTSDIR}/devel/pear-HTML_Javascript
.endif

.if defined(WITH_PEAR_FILE_GETTEXT)
RUN_DEPENDS+=	${PEARDIR}/File/Gettext.php:${PORTSDIR}/sysutils/pear-File_Gettext
.endif

.if defined(WITH_PEAR_TRANSLATION2)
RUN_DEPENDS+=	${PEARDIR}/Translation2.php:${PORTSDIR}/sysutils/pear-Translation2
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
