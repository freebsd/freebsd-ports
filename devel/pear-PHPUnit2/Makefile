# Ports collection makefile for:  pear-PHPUnit2
# Date created:			  09 September 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHPUnit
PORTVERSION=	2.3.6
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR regression testing framework for unit tests

CONFLICTS=	pear-PHPUnit-[13]*

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit

RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit \
		${PEARDIR}/Benchmark/Timer.php:${PORTSDIR}/benchmarks/pear-Benchmark

PEAR_CHANNEL=	phpunit
PEAR_AUTOINSTALL=	yes

LATEST_LINK=	pear-PHPUnit2

OPTIONS=	PEAR_LOG "PEAR::Log support" off

USE_PHP=	dom pcre

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_LOG)
RUN_DEPENDS+=	${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
