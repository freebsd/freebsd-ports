# Ports collection makefile for:  pear-XML_RSS
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_RSS
PORTVERSION=	1.0.0
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR RSS parser

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser

FILES=		XML/RSS.php
TESTS=		test.rss XML_RSS_Infrastructure_Test.php \
		XML_RSS_Parsing_Test.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
