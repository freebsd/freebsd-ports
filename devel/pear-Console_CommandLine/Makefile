# Ports collection makefile for:  pear-Console_CommandLine
# Date created:			  21 December 2007
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Console_CommandLine
PORTVERSION=	0.2.1
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A full featured command line options and arguments parser

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	Console
FILES=		CommandLine.php CommandLine/Action.php CommandLine/Command.php\
		CommandLine/Renderer.php CommandLine/Element.php CommandLine/MessageProvider.php \
		CommandLine/Outputter.php CommandLine/Result.php CommandLine/Argument.php \
		CommandLine/Exception.php CommandLine/Option.php CommandLine/XmlParser.php \
		CommandLine/Action/Callback.php CommandLine/Action/Counter.php \
		CommandLine/Action/Help.php CommandLine/Action/StoreArray.php \
		CommandLine/Action/StoreFalse.php CommandLine/Action/StoreFloat.php \
		CommandLine/Action/StoreInt.php CommandLine/Action/StoreString.php \
		CommandLine/Action/StoreTrue.php CommandLine/Action/Version.php \
		CommandLine/MessageProvider/Default.php CommandLine/Outputter/Default.php \
		CommandLine/Renderer/Default.php
DATA=		xmlschema.rng
EXAMPLES=	ex1.php ex2.php ex2.xml
_EXAMPLESDIR=	docs/examples
TESTS=		console_commandline_addargument.phpt console_commandline_parse_1.phpt \
		console_commandline_parse_4.phpt tests.inc.php console_commandline_addcommand.phpt \
		console_commandline_parse_2.phpt console_commandline_parse_5.phpt \
		console_commandline_addoption.phpt console_commandline_parse_3.phpt \
		console_commandline_parse_6.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
