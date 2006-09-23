# Ports collection makefile for:  pear-PHP_CompatInfo
# Date created:			  15 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHP_CompatInfo
PORTVERSION=	1.1.1
CATEGORIES=	devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class to find out the minimum version and extensions required

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	tokenizer

CATEGORY=	PHP
FILES=		CompatInfo/Cli.php CompatInfo/const_array.php \
		CompatInfo/func_array.php CompatInfo.php
EXAMPLES=	checkConstants.php checkPHP5.php ci_frontend.php Cli.php \
		cliOutput.txt parseArray.php parseDir.php parseFile.php \
		parseString.php
TESTS=		checkMax.php sample_req6056.php
_EXAMPLESDIR=	docs/examples

LATEST_LINK=	pear-PHP_CompatInfo
OPTIONS=	PEAR_CONSOLE_TABLE "PEAR::Console_Table support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_CONSOLE_TABLE)
RUN_DEPENDS+=	${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
