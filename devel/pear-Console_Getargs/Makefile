# Ports collection makefile for:  pear-Console_Getargs
# Date created:			  18 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Console_Getargs
PORTVERSION=	1.3.0
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR command-line arguments parser

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Console
FILES=		Getargs.php
EXAMPLES=	example.php example2.php
TESTS=		Console_TestListener.php Getargs_basic_testcase.php \
		Getargs_getValues_testcase.php test.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
