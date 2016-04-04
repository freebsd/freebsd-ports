# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHPLOC
PORTVERSION=	2.0.3
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-SebastianBergmann_
DISTNAME=	phploc-${PORTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Tool for quickly measuring the size of a PHP project

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	pear-Symfony_Component_Console>=1.1.0:devel/pear-Symfony_Component_Console \
		pear-SebastianBergmann_FinderFacade>=1.1.0:devel/pear-SebastianBergmann_FinderFacade \
		pear-SebastianBergmann_Git>=1.0.0:devel/pear-SebastianBergmann_Git \
		pear-SebastianBergmann_Version>=1.0.0:devel/pear-SebastianBergmann_Version \
		${PEARDIR}/.channels/pear.phpunit.de.reg:devel/pear-channel-phpunit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PHP=	tokenizer
PEAR_CHANNEL=	phpunit
USES=	pear

.include <bsd.port.mk>
