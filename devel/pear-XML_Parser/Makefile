# Ports collection makefile for:  pear-XML_Parser
# Date created:			  03 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Parser
PORTVERSION=	1.2.6
CATEGORIES=	devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR XML parsing class based on PHP's bundled expat

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		Parser/Simple.php Parser.php
TESTS=		001.phpt 002.phpt 003.phpt 004.phpt 005.phpt test2.xml test3.xml
EXAMPLES=	xml_parser_file.php xml_parser_file.xml xml_parser_handler.php \
		xml_parser_simple1.php xml_parser_simple1.xml xml_parser_simple2.php \
		xml_parser_simple2.xml xml_parser_simple_handler.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
