# Ports collection makefile for:  pear-XML_Parser
# Date created:			  03 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Parser
PORTVERSION=	1.2.4
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR XML parsing class based on PHP's bundled expat

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		Parser.php Parser/Simple.php
TESTS=		001.phpt 002.phpt 003.phpt 004.phpt 005.phpt test2.xml test3.xml
EXAMPLES=	xml_parser_file.php xml_parser_file.xml xml_parser_handler.php		\
		xml_parser_simple1.php xml_parser_simple1.xml xml_parser_simple2.php	\
		xml_parser_simple2.xml xml_parser_simple_handler.php

do-install-tests-msg: .USE
	@${ECHO_MSG} "     (These tests require PHPUnit - see"
	@${ECHO_MSG} "     the port devel/pear-PHPUnit)."

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
