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

LICENSE=	BSD

BUILD_DEPENDS=	pear>=1.9.4:${PORTSDIR}/devel/pear \
		pear-Symfony_Component_Console>=1.1.0:${PORTSDIR}/devel/pear-Symfony_Component_Console \
		pear-SebastianBergmann_FinderFacade>=1.1.0:${PORTSDIR}/devel/pear-SebastianBergmann_FinderFacade \
		pear-SebastianBergmann_Git>=1.0.0:${PORTSDIR}/devel/pear-SebastianBergmann_Git \
		pear-SebastianBergmann_Version>=1.0.0:${PORTSDIR}/devel/pear-SebastianBergmann_Version \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PHP=	tokenizer
PEAR_CHANNEL=	phpunit
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
