# Ports collection makefile for:  pear-Benchmark
# Date created:			  09 September 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Benchmark
PORTVERSION=	1.2.1
CATEGORIES=	benchmarks devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	Framework to benchmark PHP scripts or function calls

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Benchmark
FILES=		Timer.php Iterate.php Profiler.php
DOCS=		timer_example.php

_DOCSDIR=	doc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
