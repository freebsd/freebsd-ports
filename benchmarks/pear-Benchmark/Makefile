# Ports collection makefile for:  pear-Benchmark
# Date created:			  09 September 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Benchmark
PORTVERSION=	1.2.6
CATEGORIES=	benchmarks devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR framework to benchmark PHP scripts or function calls

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	bcmath

CATEGORY=	Benchmark
FILES=		Timer.php Iterate.php Profiler.php
EXAMPLES=	timer_example.php
_EXAMPLESDIR=	doc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
