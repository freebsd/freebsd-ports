# Ports collection makefile for:  pear-PHP_ParserGenerator
# Date created:			  05 August 2007
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PHP_ParserGenerator
PORTVERSION=	0.1.7
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Convert files from lemon parser to php5

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	PHP
FILES=		Lempar.php ParserGenerator.php phplemon \
		phplemon.bat ParserGenerator/Action.php \
		ParserGenerator/ActionTable.php \
		ParserGenerator/Config.php ParserGenerator/Data.php \
		ParserGenerator/PropagationLink.php \
		ParserGenerator/Rule.php ParserGenerator/State.php \
		ParserGenerator/Symbol.php ParserGenerator/cli.php
TESTS=		bug9346.php bug9346.y

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
