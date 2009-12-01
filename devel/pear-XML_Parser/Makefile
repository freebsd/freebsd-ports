# Ports collection makefile for:  pear-XML_Parser
# Date created:			  03 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Parser
PORTVERSION=	1.3.2
CATEGORIES=	devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR XML parsing class based on PHP's bundled expat

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		Parser/Simple.php Parser.php
TESTS=		001.phpt 003.phpt 005.phpt bug-9328.phpt test3.xml \
		002.phpt 004.phpt AllTests.php test2.xml
EXAMPLES=	xml_parser_file.php xml_parser_simple1.xml \
		xml_parser_file.xml xml_parser_simple2.php \
		xml_parser_funcmode.php xml_parser_simple2.xml \
		xml_parser_handler.php xml_parser_simple_handler.php \
		xml_parser_simple1.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
