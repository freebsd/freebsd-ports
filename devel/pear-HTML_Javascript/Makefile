# Ports collection makefile for:  pear-HTML_Javascript
# Date created:			  01 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Javascript
PORTVERSION=	1.1.0
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	Provides an interface for creating simple JS scripts

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		Javascript.php Javascript/Convert.php
EXAMPLES=	javascript.php js.php
TESTS=		js.php output.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
