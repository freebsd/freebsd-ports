# Ports collection makefile for:  pear-Console_CommandLine
# Date created:			  21 December 2007
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Console_CommandLine
PORTVERSION=	1.1.0
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A full featured command line options and arguments parser

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		Console/CommandLine.php Console/CommandLine/Action.php Console/CommandLine/Command.php\
		Console/CommandLine/Renderer.php Console/CommandLine/Element.php Console/CommandLine/MessageProvider.php \
		Console/CommandLine/Outputter.php Console/CommandLine/Result.php Console/CommandLine/Argument.php \
		Console/CommandLine/Exception.php Console/CommandLine/Option.php Console/CommandLine/XmlParser.php \
		Console/CommandLine/Action/Callback.php Console/CommandLine/Action/Counter.php \
		Console/CommandLine/Action/Help.php Console/CommandLine/Action/Password.php \
		Console/CommandLine/Action/StoreArray.php \
		Console/CommandLine/Action/StoreFalse.php Console/CommandLine/Action/StoreFloat.php \
		Console/CommandLine/Action/StoreInt.php Console/CommandLine/Action/StoreString.php \
		Console/CommandLine/Action/StoreTrue.php Console/CommandLine/Action/Version.php \
		Console/CommandLine/MessageProvider/Default.php Console/CommandLine/Outputter/Default.php \
		Console/CommandLine/Renderer/Default.php
DATA=		xmlschema.rng
EXAMPLES=	ex1.php ex2.php ex2.xml
_EXAMPLESDIR=	docs/examples
TESTS=		AllTests.php console_commandline_accept.phpt \
		console_commandline_addargument.phpt \
		console_commandline_addcommand.phpt \
		console_commandline_addoption.phpt \
		console_commandline_addoption_errors_1.phpt \
		console_commandline_addoption_errors_2.phpt \
		console_commandline_addoption_errors_3.phpt \
		console_commandline_addoption_errors_4.phpt \
		console_commandline_addoption_errors_5.phpt \
		console_commandline_addoption_errors_6.phpt \
		console_commandline_addoption_errors_7.phpt \
		console_commandline_fromxmlfile.phpt \
		console_commandline_fromxmlfile_error.phpt \
		console_commandline_fromxmlstring.phpt \
		console_commandline_parse_1.phpt console_commandline_parse_2.phpt \
		console_commandline_parse_3.phpt console_commandline_parse_4.phpt \
		console_commandline_parse_5.phpt console_commandline_parse_6.phpt \
		console_commandline_parse_7.phpt console_commandline_parse_8.phpt \
		console_commandline_parse_9.phpt console_commandline_parse_10.phpt \
		console_commandline_parse_11.phpt console_commandline_parse_12.phpt \
		console_commandline_parse_13.phpt console_commandline_parse_14.phpt \
		console_commandline_parse_15.phpt console_commandline_parse_16.phpt \
		console_commandline_parse_17.phpt console_commandline_parse_18.phpt \
		console_commandline_webrequest_1.phpt \
		console_commandline_webrequest_2.phpt \
		console_commandline_webrequest_3.phpt \
		test.xml tests.inc.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
