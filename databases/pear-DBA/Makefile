# Ports collection makefile for:  pear-DBA
# Date created:			  08 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	DBA
PORTVERSION=	1.1
CATEGORIES=	databases www pear

MAINTAINER=	antonio@php.net
COMMENT=	Berkely-style database abstraction class

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		DBA.php DBA/Compatibility.php DBA/Driver/File.php DBA/Driver/Builtin.php
TESTS=		benchmark_drivers.php test_drivers.php test_compatibility.php
DOCS=		README.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
