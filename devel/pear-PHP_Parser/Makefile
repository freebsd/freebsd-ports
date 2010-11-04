# Ports collection makefile for:  pear-PHP_Parser
# Date created:			  05 August 2007
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PHP_Parser
PORTVERSION=	0.2.2
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PHP Grammar Parser

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	PHP
FILES=		Parser.php Parser/Core.php Parser/Core.y \
		Parser/Tokenizer.php
TESTS=		basic.phpt unticked_statement1.phpt \
		files/basic.inc files/unticked_statement1.inc
DOCS=		PHP_Parser_MsgServer.cls
_DOCSDIR=	docs/tutorials/PHP_Parser
EXAMPLES=	test.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
